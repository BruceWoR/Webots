#include <iostream>
#include <stdlib>
#include <utility>
#include <vector>

#include <webots/robot.h>
#include <webots/servo.h>
#include <webots/touch_sensor.h>
#include <webots/emitter.h>
#include <webots/GPS.hpp>

#include "joint.h"
#include "particle.h"
#include "control.h"

using namespace std;

const int TIME_STEP = 64;  // used in wb_servo_set_position_sync();
const float PI = 3.1415926;
const int P_N = 1000;  // p_N is number of particle
const int G_N = 300;  //G_N is number of generation.

static WbDeviceTag joint_tag[25];  // all the servos

int main()
{
	vector<pair<string,Joint>> joints = joint_init();


	vector<Node> nodes;
	for(int i = 0;i<joints.size();i++)
	{
		nodes.push_back(Node(joints[i]->first,joints[i]->second));
	}


	Network net;
	vector<int> node_indexes = net.add_node_from_vector(nodes);
	//
	//
	//下面该加入edge了


}
















vector<pair<string,Joint>> joint_init()
{
	//generate five joint;
	Joint lateral_hip;       //num 0
	Joint lateral_ankle;		//num 1	
	Joint frontal_hip;		//num 2
	Joint frontal_knee;		//num 3
	Joint frontal_ankle;		//num 4


	//initialize joints
	lateral_ankle.set_amplitude(9.0);
	lateral_ankle.set_firstpoint(0.17);
	lateral_ankle.set_p4w();
	lateral_ankle.set_offset(0);

	lateral_hip.set_amplitude(9.0);
	lateral_hip.set_firstpoint(0.17);
	lateral_hip.set_p4w();
	lateral_hip.set_offset(0);
	
	frontal_hip.set_amplitude(52.1);
	frontal_hip.set_firstpoint(0.21);
	frontal_hip.set_p4w();
	frontal_hip.set_offset(30.0);

	frontal_knee.set_p4w(0.02, 38, 0.58, 12.25, 0.84, 32.5, 41.5);  //need to write joint_ran function, x of the last point is 1. 
	frontal_knee.set_offset(0);
	frontal_ankle.set_p4w(0.28, 28.0, 0.57, -15.0, 0.62, -27.0, -22.0); 
	frontal_ankle.set_offset(0);


	//easy to access by order;
	vector<pair<string,Joint>> joint_five;
	joint_five.push_back(make_pair("lateral_hip",lateral_hip));
	joint_five.push_back(make_pair("frontal_hip",frontal_hip));
	joint_five.push_back(make_pair("frontal_knee",frontal_knee));
	joint_five.push_back(make_pair("frontal_ankle",frontal_ankle));
	joint_five.push_back(make_pair("lateral_ankle",lateral_ankle));

	return joint_five;
}


