#include "pch.h"
#include "Auxil.h"

//RAND_MAX = 32767
namespace auxil
{
	void start()///старт генератора
	{
		srand((unsigned)time(NULL));
	}

	double dget(double rmin, double rmax)
	{
		return (double)rand() / RAND_MAX * (rmax - rmin) + rmin;
	}

	int iget(int rmin, int rmax)
	{
		///return -(rand() / RAND_MAX * (rmax - rmin) + rmin);
		return (int)dget((double)rmin, (double)rmax);
	}
}