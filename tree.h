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
		Node *childOne;
		Node *childTwo;
		Node *childThree;
		Node *childFour;
		Node *childFive;
	public:
		Node();
		~Node();
		short getVal(short loc);
		void setVal(short num);
		short getNodeNum();
		void changeNodeNum(short num);
		void setLeaf();
		void setRoot();
}

class BTree
{
	private:
		int order;
		Node root;
		int numOfNodes;
	public:
		BTree();
		~Btree();
		short incrementNum();
		short decrementNum();
		void incrementOrder();
		void decrementOrder();
		short getOrder();
		bool checkLeaf(Node temp);
}

#include "tree.cpp"

#endif