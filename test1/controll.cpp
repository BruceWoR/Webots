/*
*
*Date: 		Oct 28th, 2014
*Date:		Nov  5th, 2014
*update:    gen frontal_knee/ankle data.
*			add fitness function
*Date:      Dec 12th, 2014
*			include p_to_net.h
*/
#include <webots/robot.h>
#include <webots/servo.h>
#include <webots/touch_sensor.h>
#include <webots/emitter.h>
#include <webots/GPS.hpp>

#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>

#include "particle.h"
#include "renew_particle.h"
#include "joint.h"
#include "network.h"
#include "p_to_net.h"
using namespace std;

const TIME_STEP = 64;  // used in wb_servo_set_position_sync();
const P_N = 1000;  // p_N is number of particle
const G_N = 300;  //G_N is number of generation.

static WbDeviceTag joint_tag[25];  // all the servos

void main()
{
	/*
	joint lateral_hip();       //num 2
	joint lateral_ankle();		//num 6		
	joint frontal_hip();		//num 3
	joint frontal_knee();		//num 4
	joint frontal_ankle();		//num 5
	
	//easy to access by order;
	initial Joint and Network;
	-----------------------------------------------*/
	Network net;
	initial_network(net);
	
	/* 
	--------------------------------------------------*/
	static WbDeviceTag emitter, left_touch, right_touch, gps;   // seems not used here.
	static double motor_position[] = { 0.0, /* body */
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, /* lleg */
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, /* rleg */
    0.0, 0.0, 0.0, 0.0, 0.0,   /* larm */
    0.0, 0.0, 0.0, 0.0, 0.0,   /* rarm */
    0.0, 0.0                  /* head */
	};
	static double next_position[] = { 0.0,  /* body */
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, /* lleg */
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, /* rleg */
    0.0, 0.0, 0.0, 0.0, 0.0,   /* larm */
    0.0, 0.0, 0.0, 0.0, 0.0,   /* rarm */
    0.0, 0.0                  /* head */
	};	
	/*---------------------------------------------------
	generate the partical all
	generate all particle and initialze them.
	*/ 
	std::vector<particle> particle_all;
	std::vector<particle>::iterator it_all;//TODO??
	particle_all p_all;
	//动态生成新的结构体对象（生成时自动初始化），并存入particle_all中。
	Pglobal P_best; //store the global best value of all particles.
	struct particle *p;
	for (int i = 0; i < P_N; ++i)
	{
		p = new partical a;    // TODO:is it right???
		particle_all.push_back(p);
	}
	it_all = particle_all.end();
	for (int i = 0; i < G_N; ++i)
	{
		for (int i = 0; i < it_all; ++i)
		{
			//pass values from particle to network
			// exist problem: how to access vector elements????
			//here we change the side, will node and net change???
					
			//interact with model.

			/* initialize the webots controller library */
			wb_robot_init()  	//must called before any webots AP I
			int control_step;	// maybe 50 ?? need to set value!!!!

			// get device tags
			for (int i = 0; i < 25; ++i)
			{
				joint_tag[i] = wb_robot_getdevice(joint_number_to_name(i));
				wb_servo_enable_position(joint_tag[i], control_step);
			}

			/*
		   	* The following devices are available, although they are not 
   		 	* used in this controller program.
			*/
		    left_touch = wb_robot_get_device("left touch");
    		right_touch = wb_robot_get_device("right touch");
    		wb_touch_sensor_enable(left_touch, control_step);
    		wb_touch_sensor_enable(right_touch, control_step);
    		gps = wb_robot_get_device("gps");
 		    emitter = wb_robot_get_device("emitter");
			/* enable sensors to read data from them */
			initial_temp_nex();
			
			/* main control loop:*/
			// synchronize the 5 joint till remain in stable speed
			
			//start simulate with webots
			wb_robot_step(50 * control_step); // waite a little bit before starting.
			for (int i = 0; i < 25; ++i)
			{
				next_position[i] = wb_robot_get_position(joint_tag[i]);
			}
			// circulate condition not fall and in simulate time
			do
			{	
				for (int i = 0; i < 5; ++i)
				{
					motor_position[i+2] = joint_five[i].get_angel();
					motor_position[i+8] = motor_position[i+2];
					joint_five[i].renew_phase();
					joint_five[i].renew_angle();
					next_position[i+2] = joint_five[i].get_angel();
					next_position[i+8] = next_position[i+2];
				}
				{//jesse !!need to add delay time!!! assume 1000.
					wb_servo_set_position_sync(joint_tag[body_joint_1],
										next_position[body_joint_1], 1000);
           			wb_servo_set_position_sync(joint_tag[lleg_joint_1],
                    			        next_position[lleg_joint_1]);
            		wb_servo_set_position_sync(joint_tag[lleg_joint_2],
                    		        	next_position[lleg_joint_2]);
            		wb_servo_set_position_sync(joint_tag[lleg_joint_3],
                           			    next_position[lleg_joint_3]);
            		wb_servo_set_position_sync(joint_tag[lleg_joint_4],
                         			    next_position[lleg_joint_4]);
            		wb_servo_set_position_sync(joint_tag[lleg_joint_5],
                               			next_position[lleg_joint_5]);
            		wb_servo_set_position_sync(joint_tag[lleg_joint_6],
                                		next_position[lleg_joint_6]);
            		wb_servo_set_position_sync(joint_tag[rleg_joint_1],
                               			next_position[rleg_joint_1]);
            		wb_servo_set_position_sync(joint_tag[rleg_joint_2],
                                		next_position[rleg_joint_2]);
            		wb_servo_set_position(joint_tag[rleg_joint_3],
                    		    	    next_position[rleg_joint_3]);
        		    wb_servo_set_position_sync(joint_tag[rleg_joint_4],
                                		next_position[rleg_joint_4]);
            		wb_servo_set_position_sync(joint_tag[rleg_joint_5],
                                		next_position[rleg_joint_5]);
            		wb_servo_set_position_sync(joint_tag[rleg_joint_6],
                                		next_position[rleg_joint_6]);
            		wb_servo_set_position_sync(joint_tag[larm_joint_1],
                                		next_position[larm_joint_1]);
           			wb_servo_set_position_sync(joint_tag[larm_joint_2],
           		 		            	next_position[larm_joint_2]);
            		wb_servo_set_position_sync(joint_tag[larm_joint_3],
                                		next_position[larm_joint_3]);
           		 	wb_servo_set_position_sync(joint_tag[larm_joint_4],
                                		next_position[larm_joint_4]);
            		wb_servo_set_position_sync(joint_tag[rarm_joint_1],
                                		next_position[rarm_joint_1]);
            		wb_servo_set_position_sync(joint_tag[rarm_joint_2],
                                		next_position[rarm_joint_2]);
            		wb_servo_set_position_sync(joint_tag[rarm_joint_3],
                                		next_position[rarm_joint_3]);
            		wb_servo_set_position_sync(joint_tag[rarm_joint_4],
                                		next_position[rarm_joint_4]);
				}
			}while(//robot does'n fall down && simulate Time < duration)

			
			// while in simulate time and not fall
			
			//calculate fitness
			fitness(particle_all[i]);
		}
		renew_particle(particle_all, P_best);
		//renew particle
	}

}
// refined on 10,30. inverse order of leg_join_2/3.
typedef enum {
    body_joint_1,
    lleg_joint_1,
    lleg_joint_2,
    lleg_joint_3,
    lleg_joint_4,
    lleg_joint_5,
    lleg_joint_6,
    rleg_joint_1,
    rleg_joint_2,
    rleg_joint_3,
    rleg_joint_4,
    rleg_joint_5,
    rleg_joint_6,
    larm_joint_1,
    larm_joint_2,
    larm_joint_3,
    larm_joint_4,
    larm_joint_5,
    rarm_joint_1,
    rarm_joint_2,
    rarm_joint_3,
    rarm_joint_4,
    rarm_joint_5,
    head_joint_2,
    head_joint_1
} joints;	
	
static const char *joint_number_to_name(int num)
{
    switch (num) {
    case body_joint_1:
        return "body_joint_1";
    case lleg_joint_1:
        return "lleg_joint_1";
    case lleg_joint_2:
        return "lleg_joint_2";
    case lleg_joint_3:
        return "lleg_joint_3";
    case lleg_joint_4:
        return "lleg_joint_4";
    case lleg_joint_5:
        return "lleg_joint_5";
    case lleg_joint_6:
        return "lleg_joint_6";
    case rleg_joint_1:
        return "rleg_joint_1";
    case rleg_joint_2:
       	return "rleg_joint_2";
    case rleg_joint_3:
        return "rleg_joint_3";
    case rleg_joint_4:
        return "rleg_joint_4";
    case rleg_joint_5:
        return "rleg_joint_5";
    case rleg_joint_6:
        return "rleg_joint_6";
    case larm_joint_1:
        return "larm_joint_1";
    case larm_joint_2:
        return "larm_joint_2";
    case larm_joint_3:
        return "larm_joint_3";
    case larm_joint_4:
        return "larm_joint_4";
    case larm_joint_5:
        return "larm_joint_5";
    case rarm_joint_1:
        return "rarm_joint_1";
    case rarm_joint_2:
        return "rarm_joint_2";
    case rarm_joint_3:
        return "rarm_joint_3";
    case rarm_joint_4:
        return "rarm_joint_4";
    case rarm_joint_5:
        return "rarm_joint_5";
    case head_joint_2:
        return "head_joint_2";
    case head_joint_1:
        return "head_joint_1";
    default:
        return "none";
    }
}
void wb_servo_set_position_sync(WbDeviceTag tag, double target, int delay)
{
	const double DELTA = 0.001;   //max tolerated difference
	wb_servo_set_position(tag, target);
	double effective;
	do {
		wb_robot_step(TIME_STEP);
		delay -= TIME_STEP;
		effective = wb_servo_get_positon(tag);
	}
	while (fabs(target - effective) > DELTA && delay > 0);
}	
float fitness(particle &p) //TODO: reference
{
	//using GPS c++ API p299 to obtian original position and current position
	//double current[3];
	//original[i], predifined on the top of codes!!!
	//current[i] = getValues(gps);
	float fit = sqrt( (current[0]-original[0])*(current[0]-original[0])
			+(current[2]-original[2])*(current[2]-original[2]) )
			-sqrt((current[0]-original[0])*(current[0]-original[0]);
	p.fit_now = fit;
	if(p.fit_now > p.fit_better)
	{
		p.fit_better = p.fit_now;
		p.renew_Pi();  // renew the local best value Pi.
	}
}
	
void initial_temp_nex()
{
	tempMotor[head_joint_1]     = 0;
	tempMotor[head_joint_2]     = 0;
	tempMotor[body_joint_1]     = 0;
	tempMotor[larm_joint_5]     = 0;    /* currently not needed, */
	tempMotor[rarm_joint_5]     = 0;    /* because we don't use the fingers */
	tempMotor[lleg_joint_1]     = 0;
	tempMotor[rleg_joint_1]     = 0;
			
	next_position[head_joint_1] = 0.0;
	next_position[head_joint_2] = 0.0;
	next_position[body_joint_1] = 0.0;
	next_position[larm_joint_5] = 0.0;
	next_position[rarm_joint_5] = 0.0;
	next_position[lleg_joint_1] = 0.0;
	next_position[rleg_joint_1] = 0.0;

	//!! need to refine, regulate the arm to bending state.
	tempMotor[larm_joint_1]     = 0;
	tempMotor[larm_joint_2]     = 0;
	tempMotor[larm_joint_3]     = 0;
	tempMotor[larm_joint_4]     = 0;
	next_position[larm_joint_1] = 0.0;
	next_position[larm_joint_2] = 0.0;
	next_position[larm_joint_3] = 0.0;
	next_position[larm_joint_4] = 0.0;
}




































