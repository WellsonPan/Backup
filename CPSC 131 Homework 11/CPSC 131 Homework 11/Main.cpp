#include <iostream>
#include "LinkedBinaryTree.h"
#include "SearchTree.h"
using namespace std;

int main()
{
	LinkedBinaryTree<int> tree = LinkedBinaryTree<int>();

	tree.addRoot(9);

	tree.addLeftLeaf(tree.root(), 4);
	tree.addLeftLeaf(tree.root().left(), 2);
	tree.addRightLeaf(tree.root().left(), 7);
	tree.addLeftLeaf(tree.root().left().right(), 5);

	tree.addRightLeaf(tree.root(), 12);
	tree.addLeftLeaf(tree.root().right(), 11);
	tree.addRightLeaf(tree.root().right(), 20);
	tree.addRightLeaf(tree.root().right().right(), 42);
	tree.addLeftLeaf(tree.root().right().right().right(), 24);
	tree.addLeftLeaf(tree.root().right().right(), 14);
	tree.addLeftLeaf(tree.root().right().right().left(), 13);
	tree.addRightLeaf(tree.root().right().right().left(), 19);
	tree.addLeftLeaf(tree.root().right().right().left().right(), 16);
	tree.addRightLeaf(tree.root().right().right().left().right().left(), 17);

	SearchTree<int> tree2 = SearchTree<int>();
	system("pause");
	return 0;
}