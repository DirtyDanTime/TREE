#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;

class Node
{
	private:
		short nodeNum;
		short level;
		short numOne;
		short numTwo;
		short numThree;
		short numFour;
		bool isRoot;
		bool isLeaf;
		Node *leftChild;
		Node *rightChild;
		friend class BTree;
	public:
		Node();
		~Node();
}

class BTree
{
	private:
		int order;
		Node root;
	public:
		BTree();
		~Btree();
		bool checkLeaf(Node temp);

}

#endif