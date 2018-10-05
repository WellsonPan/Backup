#pragma once

#include <fstream>
#include <string>
#include "SearchTree.h"


SearchTree<Entry<string, string> >* buildBST_fromDatafile(const std::string& filename) {
	std::ifstream f(filename.c_str());
	if (!f)
		throw std::runtime_error("cannot open data file");

	std::string s;

	getline(f, s);
	std::string magic("CPSC131 Project3 raw data file");
	if (!f || !std::equal(magic.begin(), magic.end(), s.begin()))
		throw std::runtime_error("incorrect data file");
	getline(f, s);

	std::string firstName, movie;

	SearchTree<Entry<string, string>> *bst = new SearchTree<Entry<string, string>>;

	// TO DO: implement the creation of a binary search tree
	while (!f.eof())
	{
		getline(f,s);
		for (int index = 0; index < s.length(); index++)
		{
			if (s[index] == ',')
			{
				firstName = s.substr(0, index);
				size_t found = s.find_last_of("\r\n");
				int movieLength;
				movieLength = found - (index + 1);
				movie = s.substr(index + 1, movieLength);
				bst->insert(firstName, movie);
				index = s.length();
			}
		}
		//cout << movie << endl;
	}


	f.close();

	return bst;
}

// TO DO: You need to implement a function to print a singly linked list in reverse order
void printInReverseOrder(SNode<Entry<string, string> >* node)
{
	if (node->getnext() == NULL)
	{
		cout << endl;
	}
	else
	{
		cout << node->getElem().key() << ", " << node->getElem().value() << endl;
		printInReverseOrder(node->getnext());
	}
}

