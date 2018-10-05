//Process.cpp
#include "Process.h"
using namespace std;

	Process::Process()
	{
		id = 0;
		for (int i = 0; i < 4; i++)
		{
			alloc[i] = need[0] = 0;
		}
		pass = false;
	}

	Process::Process(int iden)
	{
		id = iden;
		for (int i = 0; i < 4; i++)
		{
			alloc[i] = need[i] = 0;
		}
		pass = false;
	}

	int Process::getID()
	{
		return id;
	}

	bool Process::getPass()
	{
		return pass;
	}

	void Process::setAlloc(int arr[])
	{
		for (int i = 0; i < 4; i++)
		{
			alloc[i] = arr[i];
		}
	}

	int * Process::getAlloc()
	{
		return alloc;
	}

	int * Process::getNeed()
	{
		return need;
	}

	void Process::setNeed(int arr[])
	{
		for (int i = 0; i < 4; i++)
		{
			need[i] = arr[i];
		}
	}

	void Process::setPass(bool val)
	{
		pass = val;
	}

	void Process::dealloc()
	{
		for (int i = 0; i < 4; i++)
		{
			alloc[i] = need[i] = 0;
		}
	}