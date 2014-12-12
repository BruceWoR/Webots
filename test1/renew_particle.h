#ifndef RENEW_PARTICLE_H
#define RENEW_PARTICLE_H

struct Pglobal
{
	float Pg[dim];
	float fit_best;
	Pglobal();//TODO is ";" right?
};

void renew_particle(std::vector<particle> all, Pglobal &P);
void seekP_best(vector<particle> v, Pglobal &P);

#endif