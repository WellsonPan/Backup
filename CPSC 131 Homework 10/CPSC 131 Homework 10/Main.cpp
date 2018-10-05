//94-3*

#include <iostream>
#include <string>
#include "LinkedStack.h"
using namespace std;


struct ArithNode
{
	char elem;
	ArithNode *left;
	ArithNode *right;
};


bool isOperator(char elem)
{
	if (elem == '+' || elem == '-' || elem == '*' || elem == '/')
		return true;
	else
		return false;
}


ArithNode* createANewNode(char c)
{
	ArithNode *node = new ArithNode;
	node->left = NULL;
	node->right = NULL;
	node->elem = c;
	return node;
};




// construct a binary tree from RPN notation
ArithNode* rpn_to_tree(const string & rpn)
{
	LinkedStack<ArithNode *> aStack;
	
	for (int index = 0; index < rpn.length(); index++)
	{
		if (rpn[index] == '+')
		{
			ArithNode *temp1 = new ArithNode;
			temp1 =	aStack.top();
			aStack.pop();
			ArithNode *temp2 = new ArithNode;
			temp2 =	aStack.top();
			aStack.pop();
			float ia = temp1->elem - '0';
			float ib = temp2->elem - '0';
			aStack.push(createANewNode((ia + ib) + 48));
			aStack.top()->left = temp2;
			aStack.top()->right = temp1;
		}
		else if (rpn[index] == '-')
		{
			ArithNode *temp1 = new ArithNode;
			temp1 = aStack.top();
			aStack.pop();
			ArithNode *temp2 = new ArithNode;
			temp2 = aStack.top();
			aStack.pop();
			float ia = temp1->elem - '0';
			float ib = temp2->elem - '0';
			aStack.push(createANewNode((ib - ia) + 48));
			aStack.top()->left = temp2;
			aStack.top()->right = temp1;
		}
		else if (rpn[index] == '*')
		{
			ArithNode *temp1 = new ArithNode;
			temp1 = aStack.top();
			aStack.pop();
			ArithNode *temp2 = new ArithNode;
			temp2 = aStack.top();
			aStack.pop();
			float ia = temp1->elem - '0';
			float ib = temp2->elem - '0';
			aStack.push(createANewNode((ia * ib) + 48));
			aStack.top()->left = temp2;
			aStack.top()->right = temp1;
		}
		else if (rpn[index] == '/')
		{
			ArithNode *temp1 = new ArithNode;
			temp1 = aStack.top();
			aStack.pop();
			ArithNode *temp2 = new ArithNode;
			temp2 = aStack.top();
			aStack.pop();
			float ia = temp1->elem - '0';
			float ib = temp2->elem - '0';
			aStack.push(createANewNode((ib / ia) + 48));
			aStack.top()->left = temp2;
			aStack.top()->right = temp1;
		}
		else
		{
			aStack.push(createANewNode(rpn[index]));
		}
	}
	return aStack.top();
}




// create standard form from arithmetic binary tree
/* Note that the inorder traversal of the binary tree should generate the standard form
of this arithmetic expression, for example (9-4)*3 or ((9-4)*3), or (((9)-(4))*(3))*/
string traverse_inOrder(ArithNode *node)
{
	// fill your code here to complete the first part of question (c)
	if (node == NULL)
	{
		return "";
	}
	else
	{
		return traverse_inOrder(node->left) + to_string((int(node->elem) - 48)) + " " + traverse_inOrder(node->right);
	}
}

// create RPN form from arithmetic binary tree
string traverse_postOrder(ArithNode *node)
{
	// fill your code here to complete the second part of question (c)
	if (node == NULL)
	{
		return "";
	}
	else
	{
		return traverse_postOrder(node->left) + traverse_postOrder(node->right) + to_string(int(node->elem) - 48) + " ";
	}
}

float eval_binaryTree(ArithNode *node)
{
	char letter = node->elem;
	if (!isOperator(letter)) {
		return float(node->elem - '0');
	}
	else {
		float left = eval_binaryTree(node->left);
		float right = eval_binaryTree(node->right);


		switch (letter) {
		case '+': 	return left + right;
			break;
		case '-': 	return left - right;
			break;
		case '*':	return left * right;
			break;
		case '/':
			if (right == 0)
				throw string("divde by zero");
			return left / right;
			break;
		default:
			throw string("illegal operator");
		}
	}
}


int main() {
	try {
		// arithemtic expression: (3+5)*4
		string rpn1 = "35+4*";
		ArithNode* root1 = rpn_to_tree(rpn1);
		string sInOrder1 = traverse_inOrder(root1);
		string sPostOrder1 = traverse_postOrder(root1);
		cout << "inOrder: " << sInOrder1.c_str() << endl;
		cout << "postOrder:" << sPostOrder1.c_str() << endl;
		cout << eval_binaryTree(root1) << endl;




		// Given the equation: (6-3) / 4
		string rpn2 = "63-4/";
		ArithNode* root2 = rpn_to_tree(rpn2);
		string sInOrder2 = traverse_inOrder(root2);
		string sPostOrder2 = traverse_postOrder(root2);
		cout << "inOrder: " << sInOrder2.c_str() << endl;
		cout << "postOrder:" << sPostOrder2.c_str() << endl;
		cout << eval_binaryTree(root2) << endl;
	}
	catch (const string &error1) {
		cout << error1.c_str() << endl;
	}

	system("pause");
	return 1;
}
// anything that is a decimal will round down to the nearest integer