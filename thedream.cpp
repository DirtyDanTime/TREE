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

Node * search(short num)
{
	leaf = new Node;
	leaf = construct();

	search(root, NULL, num);

}

Node * subSearch(Node *node, Node *par, short num)
{
	if(node->isLeaf == true)
	{
		node->parent = par;
		return node;
	}

	switch (num)
	{
		if(num < node->values[0])
		{	
			return search(node->children[0], node, num);
		}
		else if(node->values[0] < num && num < node->values[1])
		{	
			return search(node->children[1], node, num);
		}
		else if(node->values[1] < num && num < node->values[2])
		{	
			return search(node->children[2], node, num);
		}
		else if(node->values[2] < num)
		{
			return search(node->children[3], node, num);
		}
	}
}

void parentDelete(Node *node, short num)
{
	if(node != NULL)
	{
		for(short i = 0; i < node->stored; i++)
			if(node->values[i] == num) { node->values[i] = 0;}
	}
	else { return; }

	parentDelete(node->parent, num);

	return;
}

void merge(Node *node, short num)
{
	Node *temp;

	temp = construct();

	temp = node->parent;




	return;
}