#include "stdafx.h"
#include <iostream>
#include "Combi.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	 char  AA[][2]= {"A", "B", "C", "D", "E"}; 

	 cout << "****** Generator of combinations *******";
	 cout << endl << "Primary array: ";
	 cout << "{ ";

	 for (int i = 0; i < sizeof(AA)/2; i++) 

		  cout << AA[i] << ((i< sizeof(AA)/2-1)?", ":" ");  
		  cout << "}" << endl;
		  cout << endl << "Generation of combinations ";

	 combi::xcombination xc(sizeof(AA)/2, 3);
	 cout << "iz " << xc.n << " po " << xc.m << ":";
 
	 int  n  = xc.getfirst(); 

	 while (n >= 0)
	 {
		cout << endl << xc.nc << ": { ";

		for (int i = 0; i < n; i++)
			 cout << AA[xc.ntx(i)] << ((i< n-1)?", ":" ");   
		cout << "}";
		n = xc.getnext();    
	 };

	 cout << endl << "Vsego: " << xc.count() << endl;
	 system("pause");
	 return 0;
}