#ifndef PARTICLE_H
#define PARTICLE_H

struct  particle
{
	// current position
	//float side12;   //be annotated because of fixed bias---PI/2
	float side23;
	float side34;
	float side45;
	float fit_now;

    // best position in history
	//float side12_better;
	float side23_better;
	float side34_better;
	float side45_better;
	float fit_better;
	//initialize function
	particle()
    {
    	//side12 = parameter_seting(2*PI, PI, 2);
    	side23 = parameter_seting(2*PI, PI, 2);
    	side34 = parameter_seting(2*PI, PI, 2);
    	side45 = parameter_seting(2*PI, PI, 2);
    	fit_now = 0;
    	//side12_better = 0;
    	side23_better = 0;
    	side34_better = 0;
    	side45_better = 0;
    	fit_better = 0;
    }
};

void parameter_seting(float max, float min, int accu)
{
	float deno;s
	float a;
	deno = 1.0*10^accu;
	indeno = 1.0/deno; 
	srand(time(NULL));
	a = (rand() % (max-min) * deno) * indeno + min;	
	return a;
}

#endif