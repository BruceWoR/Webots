#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "particle.h"
#include "joint.h" //TODO:just for using the PI

particle::particle()
{
	for (int i = 0; i < 3; ++i) //TODO i should be dimention
	{
		Xi[i] = parameter_seting(PI,0,2);
		Vi[i] = parameter_seting(PI,0,2); //TODO
		Pi[i] = parameter_seting(PI,0,2); //TODO
		fit_now = 0;
		fit_better = 0;
	}
}
void renew_Pi()
{
	for (int i = 0; i < 3; ++i)
	{
		Pi[i] = Xi[i];
	}
}
float parameter_seting(float max, float min, int accu)
{
	float deno;
	float a;
	deno = 1.0*pow(10,accu);
	indeno = 1.0/deno; 
	srand(time(NULL));
	a = rand() % ((max-min) * deno) * indeno + min; //change 12/4	
	return a;
}