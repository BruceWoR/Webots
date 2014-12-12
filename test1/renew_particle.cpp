#include "renew_particle.h"
#include "particle.h"
#include <time.h>
#include <stdlib.h>
using namespace std;

#define C1 1
#define C2 2 
const dim 3;

Pglobal::Pglobal()
{
	for (int i = 0; i < dim; ++i)
	{
		Pg[i] = 0;
	}
	fit_best = 0;
}

void renew_particle(std::vector<particle> all, Pglobal &P)
{
	seekP_best(all, P); //TODO
	std::vector<particle>::iterator it_all;
	it_all = all.end();
	for (int j = 0; j < it_all; ++j)
	{
		for (int i = 0; i < dim; ++i)
		{
			all[j].Vi[i] = w*Vi[i] + 
						   C1*rand()%100*0.01*(all[j].Pi[i] - all[j].Xi[i])+
		    			   C2*rand()%100*0.01*(P.Pg[i] - all[j].Xi[i]);
			all[j].Xi[i] = all[j].Xi[i] + all[j].Vi[i];
		}
	}
}

void seekP_best(vector<particle> v, Pglobal &P)
{
	std::vector<particle>::iterator it_all;
	it_all = v.end();
	for (int i = 0; i < it_all; ++i)
	{
		if(v[i].fit_better > P.fit_best)
	//CAUTION: using fit_better not fit_now can reduce compare times! 	
		{
			for (int j = 0; j < dim; ++j)
			{
				P.Pg[j] = v[i].X[j];
				P.fit_best = v[i].fit_better;
				/* code */
			}
		}
	}
}