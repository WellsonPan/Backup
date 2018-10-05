//Bankers.cpp
#include "Process.h"
#include "Bankers.h"
#include <vector>
using namespace std;

	Bankers::Bankers()
	{
		for (int i = 0; i < 4; i++)
		{
			available[i] = 0;
		}
		passCount = 1;
	}

	Bankers::Bankers(int arr[])
	{
		for (int i = 0; i < 4; i++)
		{
			available[i] = arr[i];
		}
		passCount = 1;
	}

	void Bankers::setHold(vector<Process> h)
	{
		hold = h;
	}

	void Bankers::addProcess(Process p)
	{
		hold.push_back(p);
	}

	void Bankers::setAvailable(int arr[])
	{
		for (int i = 0; i < 4; i++)
		{
			available[i] = arr[i];
		}
	}

	bool Bankers::test()
	{
		bool passed;
		cout << "Pass #" << passCount << ": ";
		for (int i = 0; i < (hold.size()); i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (hold[i].getNeed()[j] > available[j])
				{
					hold[i].setPass(false);
					break;
				}
				else
				{
					hold[i].setPass(true);
				}
			}

			if (hold[i].getPass())
			{
				cout << "P(" << hold[i].getID() << "): TRUE | ";
				for (int j = 0; j < 4; j++)
				{
					available[j] += hold[i].getAlloc()[j];
				}
				hold[i].dealloc();
			}
			else
			{
				cout << "P(" << hold[i].getID() << "): FALSE | ";
			}
		}

		cout << endl;
		passCount++;

		for (int i = 0; i < (hold.size()); i++)
		{
			if (hold[i].getPass() == true)
			{
				passed = true;
			}
			else
			{
				passed = false;
				break;
			}
		}
		return passed;
	}

