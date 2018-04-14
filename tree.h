#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;

class Node
{
	private:
		short nodeNum;
		short level;
		short *values;
		bool isRoot;
		bool isLeaf;
		Node **children;
	public:
		Node();
		~Node();
		short getVal(short loc);
		short getNodeNum();
		void changeNodeNum(short num);
		void setLeaf();
		void setRoot();
		bool getLeaf();
		bool getRoot();
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