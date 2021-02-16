#include <ros/ros.h>
#include <geometry_msgs/Point.h>
using namespace std;

int main (int argc, char **argv)
{
    ros::init(argc, argv, "pub_point");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Point>("/xy_point", 1000);
    geometry_msgs::Point p;
    std::string s;

    while(ros::ok()) {
        try {
	        cout << "------------\nEnter x: ";
	        getline(cin, s);
                p.x = std::stof(s);
	        cout << "Enter y: ";
	        getline(cin, s);    
	        p.y = std::stof(s);
	        p.z = 0.0;
	        pub.publish(p); 
	} catch (std::exception& e) {
		cout << e.what() << " error. Try again. " << endl;
	}
    }
}
