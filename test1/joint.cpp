#include <iostream.h>
#include <stdlib.h>
using namespace std;
using std::string;

//define class joint
	//good to make seperate set and get for each menber.
	//set join's parameters
void joint::joint(float phase, float offset, float p1, float p2, float p3, float p4)
{
}
void joint::renew_phase(joint neibour_joint)
{
	phase = phase + W +sin(Bias + joint - neibour_joint.phase);    // W is a network param. ***** how to define W???
}
void joint::set_phase(float ph)
{
	phase = ph;
}
void joint::set_angle(float angle)
{
	angle = angle;
}
void joint::set_offset(float off)
{
	offset = off;
}
void joint::set_p4(float p1, float p2, float p3, float p4)
{
	p[0] = p1;
	p[1] = p2;
	p[2] = p3;
	p[3] = p4;
}

float joint::get_phase()
{
	return phase;
}
float joint::get_angle()
{
	return angle;
}	
float joint::get_offset()
{
	return offset;
}
float joint::get_p4(){}
//output parameters of joint
//good to return but not cout, cout can be used when testing. like: cout<<"xxxxxx"<<joint.get_param.
float joint::get_joinParam()
{
	cout<<"phase = "<<phase<<endl;
	cout<<"angle = "<<angle<<endl;
	cout<<"offset= "<<offset<<endl;
	cout<<"4 points are"<<endl;
	for (int i = 0; i < 4; ++i)
	{
		cout<<p[i]<<endl;
		/* code */
	}
}


