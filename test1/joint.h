#ifndef JOINT_H
#define JOINT_H
//define class joint
class joint
{
private:
	float phase;
	float angle;
	float offset;
	float p[4];		//whether to set p[4] here
public:
	//good to make seperate set and get for each menber.
	//set join's parameters
	void joint(float phase, float offset, float p1, float p2, float p3, float p4); // empty structure
	void renew_phase(joint neibour_joint); // 

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
};

#endif