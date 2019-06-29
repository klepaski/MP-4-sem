#pragma once 

struct elmnoz
{
	char name;
	int stoimost;
	int ves;
};

class bylean
{
	elmnoz* mas;
	int size;
public:
	bylean(int s);
	void Bylean();
	void Zadacha(int vmest, int *ves, int *stoimost);
};

class sochet
{
	elmnoz* mas;
	int size;
public:
	sochet(int s);
	void Sochet(int ke);
};

struct per
{
	bool str; //0 - налево, 1 - направо
	bool mob; //0 - не мобильный, 1 - мобильный
	char name;
	int number;
};

class perest
{
	per* mas;
	int size;
public:
	perest(int s);
	int Perest(char *nov, bool fl);
};

class razm
{
	elmnoz* mas;
	int size;
public:
	razm(int s);
	void Razm(int ke);
};

