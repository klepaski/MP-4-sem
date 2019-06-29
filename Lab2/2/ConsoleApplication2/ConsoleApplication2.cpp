#include "stdafx.h"
#include "Combi.h"
#include <iostream>
#include <ctime>
char alfavit1[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6' };
using namespace std;
#define N 33

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	clock_t  begin = 0;
	clock_t end = 0;
	begin = clock();
	int i, j;
	int mas1[N];
	srand((int)time(NULL));
	for (i = 0; i < N; i++)
	{
		mas1[i] = 10 + rand() % 291;
	}
	int mas2[N];
	for (j = 0; j < N; j++)
	{
		mas2[j] = 5 + rand() % 51;
	}
	//clock_t  begin = 0;
	//clock_t end = 0;
	begin = clock();
	bylean b(4);
	b.Bylean();
	end = clock();
	cout << "duration (y.e):   " << end - begin << endl;
	cout << "duration (sec):" << ((double)(end - begin)) / ((double)CLOCKS_PER_SEC) << endl;
	/*sochet s(6);
	s.Sochet(2);
	perest p(4);
	p.Perest(alfavit1, 0);
	razm r(7);
	r.Razm(5);
	bylean b(4);
	b.Zadacha(300, mas1, mas2);
	end = clock();
	cout << "duration (y.e):   " << end - begin << endl;
	cout << "duration (sec):" << ((double)(end - begin)) / ((double)CLOCKS_PER_SEC) << endl;*/
	system("pause");
	return 0;
}