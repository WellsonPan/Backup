//Process.h
#pragma once
#include <iostream>
using namespace std;

class Process
{
private:
	int id;
	int alloc[4];
	int need[4];
	bool pass;

public:
	Process();
	Process(int);
	int getID();
	bool getPass();
	void setAlloc(int []);
	int * getNeed();
	int * getAlloc();
	void setNeed(int []);
	void setPass(bool);
	void dealloc();
};