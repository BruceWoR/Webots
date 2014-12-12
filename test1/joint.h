#ifndef JOINT_H
#define JOINT_H

extern  const PI;//TODO: define an global value.
//define class joint
class Joint
{
private:
	float _phase;
	float _angle;
	float _offset;
	float _p[4];
	float _wave[100];		//
public:
	//good to make seperate set and get for each menber.
	//set join's parameters
	Joint();
	Joint(float phase, float offset, float p1, float p2, float p3, float p4); // empty structure

	//set function
	void set_phase( float );    //set phase
	void set_angle( float );   //set angle
	void set_offset( float );  //set off
	void set_p4(float, float, float, float);
	
	//get function
	float get_phase();
	float get_angle();
	float get_offset();
	float get_p4();
	//output parameters of joint
	//good to return but not cout, cout can be used when testing. like: cout<<"xxxxxx"<<joint.get_param.
	float get_joinParam(); // return all param in once
	//
	//
	//
	//!!!!!!!!!!!!!!!!!!!!!!!新东西
	void update(vector<pair<float,float>> update_param);//TODO：有了phi_i和phi_ij，更新phase和angle
	float get_phi();//取得phi
};

#endif