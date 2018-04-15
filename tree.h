#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;
/*class BTree;

class Node
{
	private:
		friend class BTree;
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
		Node root;
		int numOfNodes;
		friend class Node;
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

};*/

struct Node
{
	short *values;
	Node **children;
	bool isLeaf;
	short stored;
}*root = NULL, *ptr = NULL, *x = NULL;

Node * construct();

void sort(short *p, short n);

short split(Node *node, short num);

void insert(short num);

Node * search(Node *node, short num);

void deletion(short num);

void merge(Node *node, short num);

#include "tree.cpp"

//hello

#endif