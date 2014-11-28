#include <math>
#include <iostream>
#include <stdlib>
#include "joint_sin.h"

using namespace std;

joint_sin::joint_sin();
joint_sin::~joint_sin();
void joint_sin::set_amplitude(float amp)
	{
		amplitude = amp;
	}
void joint_sin::set_first_point(float p1)
	{
		first_point = p1;
	}
void joint_sin::set_p4w()
	{
		float point1 = first_point;
		float point2 = 0.5 - point1;
		float point3 = 0.5 + point1;
		float point4 = 1.0 - point1;
		set_p4(point1, point2, point3, point4);
	}
	//renew angle position
void joint_sin::renew_phase(node node_i)    //??? 10/26 is it right to use node here without include the corresponding.h ???
	{	
		it_node = node_i.end(); //?? need to aclaim first?? 
		float x = 0;
		float sita_i=this.get_angle();
		for (int i = 0; i < it_node; ++i)   // 如果webots支持c++11，则采用范循环。
		{
			
			sita_j=node[i].joint_i.get_angle();
			phi_ij=node[i].bias;
			x += sin(sita_i - sita_j - phi_ij);
		}
		x = x + w + this.get_phase();
		this.set_phase(x);
	}
void joint_sin::renew_angle(){
		float output;
		float x = get_phase;
		output = sinewave(amplitude, x, p[0], p[1], p[2], p[3]) + offset;  // is ture for exist this.nagle? // phase can't be used directly???
		set_angle(output);	
	}


//input: point
//return: output value 
// param p[i] can be as form of pointer of p[] but not 4 values.    need to promote!!!!!
float sinewave(float amp, float x, float p1, float p2, float p3, float p4)
{
	float y;
	float w = PI/(2*p1);         // 10/16 added
	if (x<0||x>1 )
	{
		cout<<"ilegal number";/* code */
		return;
	}
	if (x<p1)
	{
		y=amp*sin(w*x);
		return y;/* code */
	}
	else if (x<p2)
	{
		y=amp;
		return y;
	}
	else if (x<p3)
	{
		y=amp*sin(w*(x-p2+p1));
		return y;
	}
	else if (x<p4)
	{
		y=-amp;
		return y;
	}
	else 
	{
		y=amp*sin(w*(x-1.0));
		return y;
	}
}