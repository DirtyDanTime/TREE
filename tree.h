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
	public:
		Node();
		~Node();
		int getVal(int place);
		void setVal(int num, int place);
		int getNodeNum();
		void changeNodeNum(short num);


}

class BTree
{
	private:
		int order;
		Node root;
	public:
		BTree();
		~Btree();
		void incrementOrder();
		void decrementOrder();
		int getOrder();
		bool checkLeaf(Node temp);
}

#endif