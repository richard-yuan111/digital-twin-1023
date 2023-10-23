#include <ros/ros.h>
#include <scale_truck_control/xav2lrc.h>

void velocityCallback(const scale_truck_control::xav2lrc::ConstPtr &msg)
{
    float velocity = msg->tar_vel;
    ROS_INFO_STREAM("Received velocity: " << velocity << " m/s");
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "xavier_velocity_subscriber");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/xavier_to_lrc_msg", 1, velocityCallback);
    ros::spin();
    return 0;
}