#ifndef PARTICLE_H
#define PARTICLE_H

struct particle
{
	float Xi[3];
	float Vi[3];
	float Pi[3];
	float fit_now;
	float fit_better;
	particle(); //TODO is ";" right?
	void renew_Pi();
};

float parameter_seting(float max, float min, int accu);

#endif

