#pragma once
#include "pch.h"
#include <cstdlib>
#include <ctime>

namespace auxil
{
	void start();							//��������� ���.����� ��� ���������� ��������������� �����
	double dget(double rmin, double rmax);	//��������� ��������������� ����������.����� � ��������
	int iget(int rmin, int rmax);			//��������� ������ ���������������� ����� � �������� ���������
}