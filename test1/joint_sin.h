#ifndef JOINT_SIN_H
#define JOINT_SIN_H


class joint_sin : public joint
{
private:
	float first_point;
	float amplitude;
public:
	joint_sin();
	
	//xigou function
	~joint_sin();
	void set_amplitude(float);    //set amp
	void set_first_point(float);  //set first point
	void set_p4w();                //set p1 ~ p4
	
	//renew angle position
	void renew_phase(node);  // need to refine   2014.10.22
	void renew_angle();
};

#endif