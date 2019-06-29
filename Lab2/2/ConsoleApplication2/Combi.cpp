#include "stdafx.h"
#include "Combi.h"
#include <iostream>
char alfavit[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6' };
using namespace std;
bylean::bylean(int s)
{
	size = s;
	mas = new elmnoz[s];
	for (int i = 0; size > i; i++)
	{
		mas[i].name = alfavit[i];
	}
}


void bylean::Bylean()
{
	int Ot = 0;
	int Do = 1 << size;
	int count = 0;
	cout << "{ ";
	for (; !(Do&Ot); Ot++)
	{

		cout << "{ ";
		for (int v = 1, izm = 0; izm < size; izm++)
		{
			if ((v&Ot) != 0)
			{
				cout << mas[izm].name << ", ";
			}
			v = v << 1;
		}
		cout << "\b\b }" << endl;
		count++;
	}
	cout << "Всего:" << count << endl;
}


void bylean::Zadacha(int vmest, int *ves, int *stoimost)
{
	for (int i = 0; i < size; i++)
	{
		mas[i].ves = ves[i];
		mas[i].stoimost = stoimost[i];
	}
	int Ot = 0;
	int Do = 1 << size;
	int maxves = 0;
	int tekves = 0;
	int maxstoim = 0;
	int tekstoim = 0;
	int optim = 0;
	for (int i = 0; i < size; i++)
	{
		cout << "наименование  вес           стоимость" << endl;
		cout << mas[i].name << "             " << mas[i].ves << "            " << mas[i].stoimost << endl;
	};
	for (; !(Do&Ot); Ot++)
	{
		for (int v = 1, izm = 0; izm < size; izm++)
		{
			if ((v&Ot) != 0)
			{

				tekves += mas[izm].ves;
				tekstoim += mas[izm].stoimost;
			}
			v = v << 1;
		}
		if (tekves < vmest) // проверка на вместимость рюкзака
		{
			if (tekstoim > maxstoim)
			{
				maxstoim = tekstoim;
				maxves = tekves;
				optim = Ot;
			}
		}
		tekves = 0;
		tekstoim = 0;
	}

	cout << "максимальная стоимость: " << maxstoim << endl;
	cout << "максимальный вес: " << maxves << endl;
	cout << "Необходимо выбрать следующие элементы: { ";
	for (int v = 1, izm = 0; izm < size; izm++)
	{
		if ((v&optim) != 0)
		{
			cout << mas[izm].name << ", ";
		}
		v = v << 1;
	}
	cout << "\b\b }" << endl;
}


sochet::sochet(int s)
{
	size = s;
	mas = new elmnoz[s];
	for (int i = 0; size > i; i++)
	{
		mas[i].name = alfavit[i];
	}
}

void sochet::Sochet(int ke)
{
	int Ot = 0;
	int Do = 1 << size;
	int se = 0;
	int count = 0;
	cout << "{ ";
	for (; !(Do&Ot); Ot++)
	{
		if (se == ke) cout << "{ ";
		se = 0;
		for (int v = 1, izm = 0; izm < size; izm++)//подсчет единичек в двоичном представлении Ot
		{
			if ((v&Ot) != 0)
			{
				se++;
			}
			v = v << 1;
		}
		for (int v = 1, izm = 0; (izm < size) && (se == ke); izm++) //вывод сочетаний
		{

			if ((v&Ot) != 0)
			{
				cout << mas[izm].name << ", ";
			}
			v = v << 1;
		}
		if (se == ke)
		{
			cout << "\b\b }" << endl;
			count++;
		}
	}
	cout << "Всего:" << count << endl;
}


perest::perest(int s)
{
	size = s;
	mas = new per[s];
	for (int i = 0; size > i; i++)
	{
		mas[i].name = alfavit[i];
		mas[i].mob = 0;
		mas[i].str = 0;
		mas[i].number = i;
	}
}


int perest::Perest(char *nov = alfavit, bool fl = 0)
{
	int net = 1;
	int indmax;
	per men;
	int count = 0;
	for (int i = 0; size > i; i++)
	{
		mas[i].name = nov[i];
		mas[i].mob = 0;
		mas[i].str = 0;
		mas[i].number = i;
	}
	for (;;)
	{
		net = 0;
		//растановка мобильности
		for (int i = 0; size > i; i++)
		{
			if (mas[i].str == 0)
			{
				if (i == 0) { mas[i].mob = 0; continue; }

				if (mas[i - 1].number < mas[i].number)
					mas[i].mob = 1;
			}
			else
			{
				if (i == size - 1) { mas[i].mob = 0; continue; }
				if (mas[i].number > mas[i + 1].number)
					mas[i].mob = 1;
			};
		};
		//вывод
		cout << "{ ";
		for (int i = 0; size > i; i++)
			cout << mas[i].name << ", ";
		cout << "\b\b }" << endl;
		count++;
		//проверка на мобильность
		for (int i = 0; size > i; i++)
		{
			if (mas[i].mob == 1)
			{
				indmax = i;
				net = 1;
				break;
			}
		}
		/*for (int i = 0; size > i; i++)
		{
			cout << mas[i].mob << ' ' << mas[i].name << ' ' << mas[i].number << ' ' << mas[i].str << endl;
		}*/
		//нахождение максимального мобильного элемента
		if (net == 0) break; // если нет мобильного элемента, алгоритм завершает работу
		for (int i = 0; size > i; i++)
		{
			if (mas[i].number > mas[indmax].number)
				if (mas[i].mob == 1)
					indmax = i;
		}
		//меняем местами максимальный мобильный с тем на который указывает стрелка
		if (mas[indmax].str == 0)
		{
			men = mas[indmax - 1];
			mas[indmax - 1] = mas[indmax];
			mas[indmax] = men;
			indmax--;
		}
		else
		{
			men = mas[indmax];
			mas[indmax] = mas[indmax + 1];
			mas[indmax + 1] = men;
			indmax++;
		};
		//если надо, то меняем направление стрелки
		for (int i = 0; size > i; i++)
		{
			if (mas[indmax].number < mas[i].number)
				mas[i].str = !mas[i].str;
		}

	};

	if (fl == 0) cout << "Всего:" << count << endl;
	return count;
}


razm::razm(int s)
{
	size = s;
	mas = new elmnoz[s];
	for (int i = 0; size > i; i++)
	{
		mas[i].name = alfavit[i];
	}
}


void razm::Razm(int ke)
{
	int Ot = 0;
	int Do = 1 << size;
	int se = 0;
	int count = 0;
	int kolvo_perest = 0;
	perest p(ke);
	char *nov = new char[ke];
	for (; !(Do&Ot); Ot++)
	{
		se = 0;
		for (int v = 1, izm = 0; izm < size; izm++)//подсчет единичек в двоичном представлении Ot
		{
			if ((v&Ot) != 0)
			{
				se++;
			}
			v = v << 1;
		}
		for (int v = 1, izm = 0, ind = 0; (izm < size) && (se == ke); izm++) //вывод сочетаний
		{

			if ((v&Ot) != 0)
			{
				nov[ind] = mas[izm].name;
				ind++;
			}
			v = v << 1;
		}
		if (se == ke)
		{
			kolvo_perest = p.Perest(nov, 1);
			count++;
		}
	}
	cout << "Всего:" << kolvo_perest * count << endl;
}