//Main.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Bankers.h"
#include "Process.h"
using namespace std;

int main()
{
	int arr[4];
	int choose = 0;
	string file;
	string file2;
	cout << "Which data set do you want to run? (Enter 1, 2, or 3) ";
	cin >> choose;
	while (choose > 3 || choose < 1)
	{
		cout << "Enter 1, 2, or 3" << endl;
		cin >> choose;
	}
	if (choose == 1)
	{
		file = "dataset1Max.txt";
		file2 = "dataset1Alloc.txt";
		arr[0] = 1; arr[1] = 5; arr[2] = 2; arr[3] = 0;
	}
	else if (choose == 2)
	{
		file = "dataset2Max.txt";
		file2 = "dataset2Alloc.txt";
		arr[0] = 0; arr[1] = 0; arr[2] = 4; arr[3] = 2;
	}
	else if (choose == 3)
	{
		file = "dataset3Max.txt";
		file2 = "dataset3Alloc.txt";
		arr[0] = 1; arr[1] = 5; arr[2] = 2; arr[3] = 0;
	}
	else
	{
		cout << "Enter 1, 2, or 3" << endl;
	}
	ifstream inputfile(file); //max
	ifstream inputfile2(file2); //alloc
	Bankers safeSeq(arr);
	Process zero(0);
	Process one(1);
	Process two(2);
	Process three(3);
	Process four(4);

	int input;
	vector<int> temp; //max
	vector<int> temp2; //alloc
	while (inputfile >> input)
	{
		temp.push_back(input);
	}
	while (inputfile2 >> input)
	{
		temp2.push_back(input);
	}

	int alloc[5][4];
	int need[5][4];
	int k = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			alloc[i][j] = temp2[k];
			need[i][j] = temp[k] - temp2[k];
			k++;
		}
	}

	zero.setAlloc(alloc[0]);
	one.setAlloc(alloc[1]);
	two.setAlloc(alloc[2]);
	three.setAlloc(alloc[3]);
	four.setAlloc(alloc[4]);

	zero.setNeed(need[0]);
	one.setNeed(need[1]);
	two.setNeed(need[2]);
	three.setNeed(need[3]);
	four.setNeed(need[4]);
	
	safeSeq.addProcess(zero);
	safeSeq.addProcess(one);
	safeSeq.addProcess(two);
	safeSeq.addProcess(three);
	safeSeq.addProcess(four);

	bool flag = safeSeq.test();
	while (!flag)
	{
		flag = safeSeq.test();
	}

	system("pause");
	return 0;
}