/*!
 ******************************************************************************
 **  Example for a CarMaker ROS Node that communicates with an external node
 **
 **  Copyright (C)   IPG Automotive GmbH
 **                  Bannwaldallee 60             Phone  +49.721.98520.0
 **                  76185 Karlsruhe              Fax    +49.721.98520.99
 **                  Germany                      WWW    www.ipg-automotive.com
 ******************************************************************************
 */

 #include "cm_ros_if.hpp"
 #include "VehicleControl.h"
 #include "Vehicle/Sensor_Object.h"
 #include "Vehicle.h"
 
 using cm_ros::CMIF;
 using CMJob::Log;
 
 CMIF::CMIF() {}
 
 double test = 0.0;

 void CMIF::ext2cmCallback(
   cm_msgs::msg::VehicleInput::ConstSharedPtr msg) {
   // store the message information sent by ros in the interface buffer
   vc_buffer_.brake = msg->brake;
   vc_buffer_.gas = msg->gas;
 }
 
 void CMIF::cm2extObjectSensor(cm_msgs::msg::Object& msg) {
   // read the values from the CarMaker object sensor
   tObjectSensor *pOS = &ObjectSensor[0];
   msg.object.data =  (bool)pOS->Targ_Dtct;
 }

 void CMIF::cm2extVehicleState(cm_msgs::msg::VehicleState &msg) {
  // get the vehicle velocity from the CM simulation
  // Your code here
  tVehicle* Vhcl = &Vehicle;
  msg.velocity = (double)Vhcl->v;
}


 
 int CMIF::userInit() {
    // vehicle state
   { 
     typedef CMJob::RosPublisher<cm_msgs::msg::VehicleState> cm2ext_vstate_t;
     auto job = std::make_shared<cm2ext_vstate_t>(nhp_, "vehicle/state");
     job->setCycleTime(10);
     job->registerCallback(&CMIF::cm2extVehicleState, this);
     scheduler_.addJob(job);
   }

   { 
    typedef CMJob::RosPublisher<cm_msgs::msg::Object> cm2ext_objectsensor_t;
    auto job = std::make_shared<cm2ext_objectsensor_t>(nhp_, "vehicle/object_sensor");
    job->setCycleTime(10);
    job->registerCallback(&CMIF::cm2extObjectSensor, this);
    scheduler_.addJob(job);
  }
 
   Log::printLog("  -> Initializing service client /pse_aeb");
   param_client_ =
       std::make_shared<rclcpp::SyncParametersClient>(nhp_, "/aeb_node_example");
 
   return 1;
 }
 
 void CMIF::userDeclQuants() {
   DDefDouble(NULL, "Test", "", &test, DVA_IO_Out);
 }
 
 int CMIF::userTestrunStartAtBegin() {
   // Prepare external node for next simulation
   
   Log::printLog("  -> Sending service request");
   {  // set up ext2cm subscriber + job
     std::string topic = "ext2cm";
     bool synchronize = (sync_mode_ == SyncMode::kTopic);
     CMJob::JobType job_type =
         synchronize ? CMJob::JobType::Cyclic : CMJob::JobType::Trigger;
     // auto cycle_time = param_client_->get_parameter("cycletime", 2000);
     auto cycle_time = 10;
     typedef CMJob::RosSubscriber<cm_msgs::msg::VehicleInput> ext2cm_t;
     auto job = std::make_shared<ext2cm_t>(job_type, synchronize, nhp_, topic);
     job->setCycleTime(static_cast<unsigned long>(cycle_time));
     job->skipFirstCycles(1);
     job->setTimeoutTime(max_sync_time_);
     job->registerCallback(&CMIF::ext2cmCallback, this);
     scheduler_.addJob(job);
 
     if (cycle_time % clock_cycle_time_ != 0 ||
         (cycle_time < clock_cycle_time_ && clock_cycle_time_ > 0)) {
       node_mode_ = NodeMode::kDisabled;
       LogErrF(EC_Sim,
               "Ext. ROS node has an invalid cycle time! Expected multiple of "
               "%iums but got %ims",
               clock_cycle_time_, cycle_time);
 
       return -1;
     }
   }
 
   return 1;
 }
 
 int CMIF::userVehicleControlCalc(const double& dt)
 {
     (void)dt;
     // set the vehicle control values
     VehicleControl.Gas              = vc_buffer_.gas ;
     VehicleControl.Brake            = vc_buffer_.brake ;
     return 1;
 }
 
 
 int CMIF::userTestrunEnd() {
   scheduler_.deleteJob("ext2cm");
   return 1;
 }
 
 // Important: Use this macro to register the derived class as an interface with
 // the CarMaker C++ Interface Loader module
 REGISTER_CARMAKER_CPP_IF(CMIF)