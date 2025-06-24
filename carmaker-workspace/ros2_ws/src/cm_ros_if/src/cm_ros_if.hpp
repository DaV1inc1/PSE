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

#ifndef CM_ROS_IF_HPP
#define CM_ROS_IF_HPP

#include "cmrosutils/cmrosif.hpp"
#include "cm_msgs/msg/object.hpp"
#include "cm_msgs/msg/vehicle_input.hpp"
#include "cm_msgs/msg/vehicle_state.hpp"

 struct VehicleControlBuffer {
  double gas = 0.0;
  double brake = 0.0;
  double steer = 0.0;
};

namespace cm_ros {
/**
 * @brief The CMNodeHelloCM class serves as an example for a CarMaker ROS Node
 * that communicates with an external node. It derives from the
 * CarMakerROSInterface base class, which already implements the basic CarMaker
 * ROS node functioniality.
 */
class CMIF : public CarMakerROSInterface {
 public:
  CMIF();

 private:
  /**
   * @brief userInit sets up the ros publisher job and the service client
   * @return 1
   */
  int userInit() final;

  /**
   * @brief userDeclQuants declares some User Accessible Quantities (UAQs) for
   * data storage in ERG files, data access via e.g. DVA or visualization in
   * e.g. IPGControl
   */
  void userDeclQuants() final;

  /**
   * @brief userTestrunStartAtBegin first calls the service of the external node
   * to resets it. Then it sets up the ros subscriber job. In case of
   * synchronized mode the job uses the cycle time of the external node
   * retrieved via ros parameter server and checks whether it is compatible with
   * the current clock cycle time.
   * @return 1 if successful, -1 if otherwise
   */
  int userTestrunStartAtBegin() final;

  /**
   * @brief userVehicleControlCalc sets the vehicle control values
   * @param dt time step
   * @return 1
   */
  int userVehicleControlCalc(const double& dt);

  /**
   * @brief userTestrunEnd deletes the subscriber job
   * @return 1
   */
  int userTestrunEnd() final;

  /**
   * @brief ext2cmCallback Callback function for ext2cm subscriber.
   * Used in this example to synchronize the CM cycle to
   * @param msg Received ROS message
   */
  void ext2cmCallback(cm_msgs::msg::VehicleInput::ConstSharedPtr msg);

  /**
   * @brief cm2extFillMsg prepares the message to be sent to the external node.
   * Demonstrates how CarMaker variables can be sent out as ros messages.
   * @param msg the actual message being prepared by this function
   */
  void cm2extObjectSensor(cm_msgs::msg::Object& msg);

/**
 * @brief cm2extVehicleState prepares the message to be sent to the external node.
 * Demonstrates how CarMaker variables can be sent out as ros messages.
 * @param msg the actual message being prepared by this function
 */ 
  void cm2extVehicleState(cm_msgs::msg::VehicleState &msg);


  /**
   * @brief param_client_ synchronous parameter client to retrieve parameters
   * from external node.
   */
  rclcpp::SyncParametersClient::SharedPtr param_client_;

  /**
   * @brief vc_buffer_ buffer for vehicle control values received from external ros node
   */
  VehicleControlBuffer vc_buffer_;

};
}  // namespace cm_ros

#endif  // CM_ROS_IF_HPP
