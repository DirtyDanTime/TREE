#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;
class BTree;

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
		Node(BTree tree);
		~Node();
		short getVal(short loc);
		short getNodeNum();
		void changeNodeNum(short num);
		void setLeaf();
		bool getLeaf();
		bool getRoot();
};

class BTree
{
	private:
		int order;
		Node *root;
		int numOfNodes;
	public:
		BTree();
		~BTree();
		short incrementNum();
		short decrementNum();
		void incrementOrder();
		void decrementOrder();
		short getOrder();
		bool checkLeaf(Node temp);
		Node getRoot();
		void setRoot(Node *temp);

};

#include "tree.cpp"

//hello

#endif