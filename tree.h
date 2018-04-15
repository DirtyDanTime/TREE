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
		short stored;
		short *values;
		bool isRoot;
		bool isLeaf;
		Node **children;
	public:
		Node(BTree tree);
		~Node();
		void incrementStored();
		void decrementStored();
		void setVal(short val, short loc);
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
		BTree *tree;
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
		void insert(short num);
		short split(Node *node, short num);

};

#include "tree.cpp"

//hello

#endif