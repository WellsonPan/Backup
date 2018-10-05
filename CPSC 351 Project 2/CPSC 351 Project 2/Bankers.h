//Bankers.h
#pragma once
#include "Process.h"
#include <vector>
using namespace std;

class Bankers
{
private:
	int passCount;
	int available[4];
	vector<Process> hold;

public:
	Bankers();
	Bankers(int []);
	void setHold(vector<Process>);
	void addProcess(Process);
	void setAvailable(int []);
	bool test();
};