#include <chrono>
#include <memory>
#include "rclcpp/create_timer.hpp"
#include "pse_aeb/aeb.hpp"

AEB::AEB() : Node("pse_example_aeb_node")
{
    RCLCPP_INFO(this->get_logger(), "Start spinning...");
    // Declare parameter
    this->declare_parameter<int>("cycletime", 10);
    init();
}

AEB::~AEB()
{
    RCLCPP_INFO(this->get_logger(), "Shutdown");
}

void AEB::init(){
    publisher_ = this->create_publisher<cm_msgs::msg::VehicleInput>("ext2cm", 10);

    subscription_ = this->create_subscription<cm_msgs::msg::Object>(
        "vehicle/object_sensor", 10, std::bind(&AEB::topic_callback, this, std::placeholders::_1));
    this->get_parameter("cycletime", cycle_time_);
    timer_ = rclcpp::create_timer(this, this->get_clock(),
                                  std::chrono::milliseconds(cycle_time_),
                                  std::bind(&AEB::control, this));
}

void AEB::control(){
  cm_msgs::msg::VehicleInput msg;
  
  if (this->object_) {
    msg.brake = 1.0;
    msg.gas = 0.0;
  } else {
    msg.brake = 0.0;
    msg.gas = 1.0;
  }
  // publish the message
  publisher_->publish(msg);
}

void AEB::topic_callback(const cm_msgs::msg::Object::SharedPtr msg){
  this->object_ = msg->object.data;
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AEB>());
    rclcpp::shutdown();
    return 0;
}