#ifndef AEB_hpp
#define AEB_hpp

#include "rclcpp/rclcpp.hpp"
#include "cm_msgs/msg/object.hpp"
#include "cm_msgs/msg/vehicle_input.hpp"

class AEB : public rclcpp::Node
{
public:
    AEB();
    ~AEB();
private:
    /**
     * @brief Executes the control algorithm
     * Gets periodically called by the timer and evaluates if the vehicle should brake or accelerate
    */
    void control();

    /**
     * @brief Callback function for the topic subscription
     * Stores the received message in the object_ variable
     * @param msg The message received from the topic
    */
    void topic_callback(const cm_msgs::msg::Object::SharedPtr msg);

    /**
     * @brief Initializes the node
     * Creates the publisher and subscription for the topics
    */
    void init();
    
    int cycle_time_;
    bool object_ = false;
    rclcpp::Publisher<cm_msgs::msg::VehicleInput>::SharedPtr publisher_;
    rclcpp::Subscription<cm_msgs::msg::Object>::SharedPtr subscription_;
    rclcpp::TimerBase::SharedPtr timer_;
};

#endif // AEB_hpp