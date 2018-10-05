#include "Logger.h"
//#define err(msg) log.write(__LINE__, __FILE__, __FUNCTION__, msg)
using namespace std;

	Logger::Logger()
	{
		buffer = "";
	}

	void Logger::openOutput(string fileName)
	{
		logFileOut.open(fileName);
	}

	void Logger::openInput(string fileName)
	{
		logFileIn.open(fileName);
	}

	void Logger::closeOut()
	{
		if (logFileOut.is_open())
		{
			logFileOut.close();
		}
		else
		{
			cout << "File is not open" << endl;
		}
	}

	void Logger::closeIn()
	{
		if (logFileIn.is_open())
		{
			logFileIn.close();
		}
		else
		{
			cout << "File is not open" << endl;
		}
	}

	void Logger::flushFile()
	{
		if (logFileOut.is_open())
		{
			logFileOut << buffer << endl;
			logFileOut.flush();
		}
		else
		{
			cout << "File is not open" << endl;
		}
	}

	void Logger::read()
	{
		if (logFileIn.is_open())
		{
			while (getline(logFileIn, input))
			{
				cout << input << '\n';
			}
		}
		else
		{
			cout << "File is not open" << endl;
		}
	}

	void Logger::write(int lineNum, string file, string function, int description)
	{
		buffer += __DATE__;
		buffer += PIPE;
		buffer += __TIME__;
		buffer += PIPE;
		buffer += to_string(lineNum);
		buffer += PIPE;
		buffer += file;
		buffer += PIPE;
		buffer += function;
		buffer += PIPE;
		buffer += strerror(description);
		//buffer += PIPE;
		//buffer += description;
		buffer += "\n";
	}