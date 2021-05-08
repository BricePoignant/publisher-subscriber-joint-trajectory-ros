#include <ros/ros.h>
#include <trajectory_msgs/JointTrajectory.h>


int main(int argc, char **argv) {
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;
    ros::Publisher chatterPublisher = nh.advertise<trajectory_msgs::JointTrajectory>("chatter", 1);
    ros::Rate loopRate(10);

    trajectory_msgs::JointTrajectory traj;
    trajectory_msgs::JointTrajectoryPoint points_n;

    traj.header.frame_id = "joints_test";
    traj.joint_names.resize(6);
    traj.points.resize(1);

    traj.joint_names[0] ="joint_1";
    traj.joint_names[1] ="joint_2";
    traj.joint_names[2] ="joint_3";
    traj.joint_names[3] ="joint_4";
    traj.joint_names[4] ="joint_5";
    traj.joint_names[5] ="joint_6";

    traj.points[0].positions.resize(6);
    unsigned int count = 0;
    while (ros::ok()) {
        traj.header.stamp = ros::Time::now();

        for(int j=0; j<6; j++) {
                traj.points[0].positions[j] = count;
        }
        traj.points[0].time_from_start = ros::Duration(1);

        chatterPublisher.publish(traj);
        //ROS_INFO("Joint_message_sent");
        ros::spinOnce();
        loopRate.sleep();
        count++;
    }
    return 0;
}