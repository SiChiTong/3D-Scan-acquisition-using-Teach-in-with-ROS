#include "ros/ros.h"
#include "vels.h"
#include "nav_msgs/Odometry.h"
#include "tf/transform_listener.h"
#include "gio_path_v_3.h"
#include "math.h"
#include "volksbot/vels.h"
#include <sstream>
#include <string>
#include "std_srvs/Empty.h"

double x, y;
double angle;
char filename[255];
int filenumber = 0;
int cannotDeterminePos_tolerance = 0;
int maxCannotDeterminePos_tolerance = 0;
string path = "";

int datasetCount = 0;

//dataset reduction stuff
//int toDel = 2;

void odomSubscriber(const nav_msgs::Odometry::ConstPtr& msg)
{
x = msg->pose.pose.position.x;
y = msg->pose.pose.position.y;
double  qx = msg->pose.pose.orientation.x;
double  qy = msg->pose.pose.orientation.y;
double  qz = msg->pose.pose.orientation.z;
double  qw = msg->pose.pose.orientation.w;
 angle = atan2(2 * ( qw * qz + qx * qy),1 - 2 * ( qz * qz + qy * qy));
}

int main(int argc, char **argv)
{
  std_srvs::Empty e;
  ros::init(argc, argv, "talker");
  ros::NodeHandle node;
  ros::Publisher chatter_pub = node.advertise<volksbot::vels>("Vel", 1000);
  ros::Rate loop_rate(10);
  tf::TransformListener listener;  
  CGioController cgio;
  path = argv[1];
  sprintf(filename, "%spath%d.dat",path.c_str(),filenumber);

 cout << "Waiting 15s for map!" << endl;
 ros::Duration(15).sleep();
	nextFile:
datasetCount = 0;
	cout << "pfadverfolgung/curent file: " << filename << endl;	
	cgio.getPathFromFile(filename);
	  cgio.setCurrentVelocity(15);
  double u = 0.0;
  double w = 0.0;
  double vleft = 0.0;
  double vright = 0.0;

//delete every xth dataset_____________
/*if(cgio.path->getCount() % toDel == 0){
	cgio.path->delEveryX(true, toDel, filename);
}else{
	cgio.path->delEveryX(false, toDel, filename);
}
 cout << "Deleted every " << toDel << " Dataset from " << path.c_str() << "!" << endl;*/
//________________________


  while (ros::ok())
  {

    tf::StampedTransform transform;

    try{
      listener.lookupTransform("/map","/base_link",ros::Time(0),transform);
    }
    catch(tf::TransformException &ex){
      ROS_ERROR("%s",ex.what());
    }
    x = transform.getOrigin().x();
    y = transform.getOrigin().y();
    angle = atan2(2*(transform.getRotation().w()*transform.getRotation().z()),1-2*(transform.getRotation().z()*transform.getRotation().z()));
   // ROS_INFO("X::%f\tY::%f\tANGLE::%f\t",x,y,angle);
	if(cgio.getNextState(u,w,vleft,vright,1) == 0){
		cout << "=== 1_1 - no next dataset found ===" << endl;
			if(cannotDeterminePos_tolerance < maxCannotDeterminePos_tolerance){
				cannotDeterminePos_tolerance = cannotDeterminePos_tolerance +1;
			}else{
				cout << "pfadverfolgung/Path Done" << endl;
				cannotDeterminePos_tolerance = 0;
				break;
			}
	}else{
		cout << "current dataset: " << datasetCount << endl;
		datasetCount = datasetCount + 1;
		cout << "=== 1 - do pathfollowing ===" << endl;
		//get next state only every temp iterations
		cgio.setPose(x,y,angle);
		    cgio.getNextState(u,w,vleft,vright,1);	
		    volksbot::vels msg;
		    msg.left = -vleft;
		    msg.right = -vright;
		    chatter_pub.publish(msg);
		    ros::spinOnce();
		    loop_rate.sleep();
	}
  }
		cout << "=== 2/4 - File ended - load next path and init scan ===" << endl;
	filenumber = filenumber + 1;
  	sprintf(filename, "%spath%d.dat", path.c_str(), filenumber);
	if(cgio.getPathFromFile(filename) == 1){
	cout << "=== 3/4 - next path loaded ===" << endl;
		if(filenumber > 0){
	cout << "=== 4/4 - init scan ===" << endl;
			cout << "Start measuring" << endl;
			ros::service::call("startMeasuring",e);
			ros::Duration(60).sleep();
		}
		goto nextFile;
	}else{
		cout << "Alle Pfade abgefahren, ENDE" << endl;
	}
  return 0;
}
