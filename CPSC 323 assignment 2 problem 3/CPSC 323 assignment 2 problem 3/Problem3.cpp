#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isReserved(string reserve)
{
	bool reserved = false;
	if (reserve == "int" || reserve == "float")
	{
		reserved = true;
	}
	else
	{
		reserved = false;
	}

	return reserved;
}

bool isIdentifier(string id)
{
	bool identifier = false;
	if (id[0] > 64 && id[0] < 91)
	{
		for (int index = 1; index < id.length(); index++)
		{
			if (id[index] > 64 && id[index] < 91)
			{
				identifier = true;
			}
			else if (id[index] > 96 && id[index] < 123)
			{
				identifier = true;
			}
			else if (id[index] > 47 && id[index] < 58)
			{
				identifier = true;
			}
			else if (id[index] == '_')
			{
				identifier = true;
			}
			else
			{
				identifier = false;
				break;
			}
		}
	}
	else if (id[0] > 96 && id[0] < 123)
	{
		for (int index = 1; index < id.length(); index++)
		{
			if (id[index] > 64 && id[index] < 91)
			{
				identifier = true;
			}
			else if (id[index] > 96 && id[index] < 123)
			{
				identifier = true;
			}
			else if (id[index] > 47 && id[index] < 58)
			{
				identifier = true;
			}
			else if (id[index] == '_')
			{
				identifier = true;
			}
			else
			{
				identifier = false;
				break;
			}
		}
	}
	else
	{
		identifier = false;
	}

	return identifier;
}

bool isInteger(string digitString)
{
	bool noDecimal = false;
	for (int index = 0; index < digitString.length(); index++)
	{
		if (digitString[index] > 47 && digitString[index] < 58)
		{
			noDecimal = true;
		}
		else
		{
			noDecimal = false;
			break;
		}
	}
	return noDecimal;
}

bool isFloat(string real)
{
	bool decimal = false;
	int decimalCount = 0;
	for (int index = 0; index < real.length(); index++)
	{
		if (real[index] > 47 && real[index] < 58)
		{
			decimal = true;
		}
		else if ((real[index] == '.') && decimalCount == 0)
		{
			decimal = true;
			decimalCount++;
		}
		else
		{
			decimal = false;
			break;
		}
	}
	return decimal;
}

/*if (line[index] == ',')
				{
					if (commaCount == 0)
					{
						cout << ",\t" << "SPECIAL CHARACTER" << endl;
						commaCount++;
					}
					else
					{
						
					}
				}
				else if (line[index] == ';')
				{
					if (colonCount == 0)
					{
						cout << ";\t" << "SPECIAL CHARACTER" << endl;
						colonCount++;
					}
					else
					{

					}
				}
				else if (line[index] == '=')
				{

				}
				else
				{

				}*/

int main()
{
	//string line = "This is a sentence";
	//cout << line.substr(4, 7) << endl;

	ifstream textFile;
	string line;
	int commaCount = 0;
	int colonCount = 0;
	textFile.open("Token.txt");
	if (textFile.is_open())
	{
		while (getline(textFile, line))
		{
			int tokenBegin = 0;
			for (int index = 0; index < line.length(); index++)
			{
				if (line[index] == ' ' || line[index] == '=' || line[index] == ',' || line[index] == ';')
				{

					if (line[index] == ',' && commaCount == 0)
					{
						cout << ",\t" << "SPECIAL CHARACTER" << endl;
						commaCount++;
					}
					if (line[index] == ';' && colonCount == 0)
					{
						cout << ";\t" << "SPECIAL CHARACTER" << endl;
						colonCount++;
					}

					int tokenEnd = index - tokenBegin;
					if (isReserved(line.substr(tokenBegin, tokenEnd)))
					{
						cout << line.substr(tokenBegin, tokenEnd) << "\tRESERVED WORD" << endl;
						if (line[index + 1] == ' ')
						{
							tokenBegin = index + 2;
							index++;
						}
						else
						{
							tokenBegin = index + 1;
						}
					}
					else if (isIdentifier(line.substr(tokenBegin, tokenEnd)))
					{
						cout << line.substr(tokenBegin, tokenEnd) << "\tIDENTIFIER" << endl;
						if (line[index + 1] == ' ')
						{
							tokenBegin = index + 2;
							index++;
						}
						else
						{
							tokenBegin = index + 1;
						}
					}
					else if (isInteger(line.substr(tokenBegin, tokenEnd)))
					{
						cout << line.substr(tokenBegin, tokenEnd) << "\tINTEGER NUMBER" << endl;
						if (line[index + 1] == ' ')
						{
							tokenBegin = index + 2;
							index++;
						}
						else
						{
							tokenBegin = index + 1;
						}
					}
					else if (isFloat(line.substr(tokenBegin, tokenEnd)))
					{
						cout << line.substr(tokenBegin, tokenEnd) << "\tREAL NUMBER" << endl;
						if (line[index + 1] == ' ')
						{
							tokenBegin = index + 2;
							index++;
						}
						else
						{
							tokenBegin = index + 1;
						}
					}
					else
					{
						cout << line.substr(tokenBegin, tokenEnd) << "\tINVALID TOKEN" << endl;
						if (line[index + 1] == ' ')
						{
							tokenBegin = index + 2;
							index++;
						}
						else
						{
							tokenBegin = index + 1;
						}
					}
				}
				else
				{
				
				}
			}
		}
		textFile.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	system("pause");
	return 0;
}