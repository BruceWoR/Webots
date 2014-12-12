#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "joint.h"
using namespace std;

const float PI = 3.1415;//TODO: define an global value.

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
void Joint::update(vector<pair<float,float>> update_param, const W)
{
	float SUM(0);
	for (int i = 0; i < update_param.size(); ++i)
	{
		float phi_j = update_param[i].first;
		float phi_ij = update_param[i].second;
		SUM += sin(_phase-phi_j-phi_ij);
	}
	_phase += SUM + W;
	while(_phase>2*PI)
	{
		_phase = _phase - 2*PI;
	}
	while(_phase<0)
	{
		_phase = _phase +2*PI;
	}
	//TODO: in case phase is out of range. 

	int index = int(_phase*50/PI); //TODO: whether need to define const PI
	_angle = _wave(index);
}
//W is constant, Bias is edge weight. 
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
void Joint::set_wave(char* name)
{
	ifstream fp;
	fp.open(name, "r");
	for (int i = 0; i < 100; ++i)
	{
		fp>>_wave[i];
	}
	fp.close();
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
