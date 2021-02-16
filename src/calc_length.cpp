#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <std_msgs/Float64.h>

ros::Publisher pub;

void callback_receivePoint(const geometry_msgs::Point& p)
{
    std_msgs::Float64 f;
    f.data = sqrt(p.x*p.x + p.y*p.y);
    pub.publish(f);
}

int main (int argc, char **argv)
{
    ros::init(argc, argv, "calc_length"); // length, magnitude, or norm of a vector
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/xy_point", 1000, callback_receivePoint);
    pub = nh.advertise<std_msgs::Float64>("/topic_float", 1000);
    ros::spin(); // to enable msg callback functions
}


