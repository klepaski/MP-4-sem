#pragma once
#include "pch.h"
#include <cstdlib>
#include <ctime>

namespace auxil
{
	void start();							//установка нач.числа для генератора псевдослучайных чисел
	double dget(double rmin, double rmax);	//генерация действительного псевдослуч.числа в заданном
	int iget(int rmin, int rmax);			//генерация целого псевдослучайного числа в заданном диапазоне
}