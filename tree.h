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
//template <typename T>
struct Node
{
	Node *parent;
	short *values;
	Node **children;
	Node *next;
	bool isLeaf;
	short stored;
}*root = NULL;

/*struct LeafNode
{
	Node *parent;
	short *values;
	LeafNode *next;
	bool isLeaf;
	short stored;

}*p = NULL;*/
//LeafNode * leaf();

//LeafNode * leafSwap(Node *n);

Node * construct();

void sort(short *p, short n);

void split(Node *node, Node *last, short num);

void insert(short num);

void parentDelete(Node *node, short num, short replace);

Node * search(short num, bool exact);

Node * subSearch(Node *node, Node *par, short num);

void deletion(short num);

void merge(Node *node, short num);

#include "thedream.cpp"

void output();
//hello

#endif