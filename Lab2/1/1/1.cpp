#include <iomanip>
#include "stdafx.h"
#include <iostream>
#include "Combi.h"

using namespace std;

int main()
{
	 char  AA[][2]= {"A", "B", "C", "D"};

	 cout << "****** Generator of all subsets  *******" << endl;
	 cout << endl << "Primary array: ";
	 cout << "{ ";

	for (int i = 0; i < sizeof(AA)/2; i++) 
		cout << AA[i] << ((i < sizeof(AA)/2-1)?", ":" ");  

	cout << "}" << endl;
	cout << endl << "Generation of all subsets: ";

	 combi::subset s1(sizeof(AA)/2);         // создание генератора  
	 int  n  = s1.getfirst();                // первое (пустое) подмн-во    
 
	 while (n >= 0)                          // пока есть подмн-ва 
	 {
		cout << endl << "{ ";

		for (int i = 0; i < n; i++)  
			cout << AA[s1.ntx(i)] << ((i< n-1)?", ":" ");   
		cout << "}";
		n = s1.getnext();                  // cледующее подмн-во 
	 };
	 cout << endl << "Vsego: " << s1.count() << endl;
	 system("pause");
	 return 0;
}
