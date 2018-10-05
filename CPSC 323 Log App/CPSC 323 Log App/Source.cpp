#include "Logger.h"
#include <cmath>
#define err(msg) logg.write(__LINE__, __FILE__, __FUNCTION__, msg)
using namespace std;

double logFunc(double x) {
	double answer = 0;
	if (x <= 0) {
		answer = log(x);
		throw errno;
	}
	return answer;
}

int main()
{
	double num1;
	string message;
	Logger logg;
	logg.openOutput("Log.txt");

	cout << "Enter in 1 number to log: ";
	cin >> num1;
	try
	{
		cout << logFunc(num1) << endl;
	}
	catch (int errorMsg)
	{
		err(errorMsg);
		cerr << strerror(errorMsg) << endl;
	}


	logg.flushFile();
	logg.closeOut();
	system("pause");
	return 0;
}