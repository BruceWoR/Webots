#include <iostream>
#include <stdlib.h>
using namespace std;


//define class Joint
	//good to make seperate set and get for each menber.
	//set join's parameters

Joint::Joint()
{
}


Joint::Joint(float phase, float offset, float p0, float p1, float p2, float p3)
{
	_phase = phase;
	_offset = offset;
	_p[0] = p0;
	_p[1] = p1;
	_p[2] = p2;
	_p[3] = p3;
}
void Joint::renew_phase(Joint neibour_joint)
{
	_phase = _phase + W +sin(Bias + Joint - neibour_joint.phase);    // W is a network param. ***** how to define W???
}
void Joint::set_phase(float ph)
{
	_phase = ph;
}
void Joint::set_angle(float angle)
{
	_angle = angle;
}
void Joint::set_offset(float off)
{
	_offset = off;
}
void Joint::set_p4(float p1, float p2, float p3, float p4)
{
	_p[0] = p1;
	_p[1] = p2;
	_p[2] = p3;
	_p[3] = p4;
}

float Joint::get_phase()
{
	return _phase;
}
float Joint::get_angle()
{
	return _angle;
}	
float Joint::get_offset()
{
	return _offset;
}
float Joint::get_p4(){}
//output parameters of Joint
//good to return but not cout, cout can be used when testing. like: cout<<"xxxxxx"<<Joint.get_param.
float Joint::get_joinParam()
{
	cout<<"phase = "<<_phase<<endl;
	cout<<"angle = "<<_angle<<endl;
	cout<<"offset= "<<_offset<<endl;
	cout<<"4 points are"<<endl;
	for (int i = 0; i < 4; ++i)
	{
		cout<<_p[i]<<endl;
		/* code */
	}
}