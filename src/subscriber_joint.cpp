#include "ros/ros.h"
#include "trajectory_msgs/JointTrajectory.h"

void chatterCallback(const trajectory_msgs::JointTrajectory& msg) {
    for(int i=0; i<6; i++) {
        ROS_INFO("%s is at position : %f]", msg.joint_names[i].c_str(), msg.points[0].positions[i]);
    }
    
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "listener");
    ros::NodeHandle nodeHandle;
    ros::Subscriber subscriber = nodeHandle.subscribe("chatter",10,chatterCallback);
    ros::spin();
    return 0;
}