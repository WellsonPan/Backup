#pragma once
#pragma warning(disable:4996)
#define PIPE "|"


#include <iostream>
#include <fstream>
#include <string>
#include <errno.h>
using namespace std;

class Logger
{
private:
	ofstream logFileOut;
	ifstream logFileIn;
	string input;
	string buffer;

public:
	Logger();
	void openOutput(string fileName);
	void openInput(string fileName);
	void closeOut();
	void closeIn();
	void flushFile();
	void read();
	void write(int lineNum, string file, string function, int description);
};