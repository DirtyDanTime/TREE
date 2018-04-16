#include "tree.h"


#include <iostream>
#include <stdio.h>

using namespace std;


Node * construct()
{
	ptr = new Node;
	ptr->parent = NULL;
	ptr->values = new short[4];

	ptr->children = new Node *[5];
	ptr->isLeaf = true;
	ptr->stored = 0;
	for(short i = 0; i < 5; i++)
	{
		ptr->children[i] = NULL;
	}
	return ptr;
}

void insert(short num)
{
	if(root == NULL)
	{
		root = construct();
		x = root;
	}
	else
	{
		ptr = search(x, num);
	}
	if(ptr->stored < 3)
	{
		ptr->values[ptr->stored] = num;
		ptr->stored++;
		sort(ptr->values, ptr->stored);
	}
	else
	{
		if()
	}
	
}

Node * search(Node *node, Node *par, short num)
{
	if(node->isLeaf == true)
	{
		node->parent = par;
		return node;
	}

	switch (num)
	{
		case (num < node->values[0]):
			return search(node->children[0], node, num);
			break;
		case (node->values[0] < num && num < node->values[1]):
			return search(node->children[1], node, num);
			break;
		case (node->values[1] < num && num < node->values[2]):
			return search(node->children[2], node, num);
			break;
		case (node->values[2] < num):
			return search(node->children[3], node, num);
			break;
	}
}

Node * mergeSearch(Node *parent, short num)
{
	Node *temp;

	temp = search(root, num);

	for(short i = 0; i < 4; i++)
	{
		if(parent->children[i] == )
	}	
}

void merge(Node *node, short num)
{

	return;
}