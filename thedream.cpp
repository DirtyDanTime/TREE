

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
LeafNode * leaf()
{
	p = new LeafNode;
	p->values = new short[4];
	p->next = new LeafNode;
	p->isLeaf = true;
	p->stored = 0;
	return p;
}

void insert(short n)
{

	LeafNode *p = leaf();
	if(root == NULL)
	{
		root = construct();
		x = root;
	}
	else
	{
		p = search(x, n);
	}
	if(ptr->stored < 3)
	{
		ptr->values[ptr->stored] = n;
		ptr->stored++;
		sort(ptr->values, ptr->stored);
	}
	else
	{
		if()
	}
<<<<<<< HEAD

}

LeafNode * leafSwap(Node *node)
{
	LeafNode *l = leaf();
	for(int i = 0; i < node->stored; i++)
	{
		l->values[i] = node->values[i];
	}
	l->stored = node->stored;
	l->next = NULL;
	return l;
}

LeafNode * search(Node *node, short num)
{
	if(node->isLeaf == true)
	{
		LeafNode *n = leafSwap(node);
		return n;
=======
	
}

Node * search(Node *node, Node *par, short num)
{
	if(node->isLeaf == true)
	{
		node->parent = par;
		return node;
>>>>>>> 8ed1b2ec703342b2314f222418276914814727dc
	}

	switch (num)
	{
		case (num < node->values[0]):
			return search(node->children[0], node, num);
			break;
		case (node->values[0] < num && num < node->values[1]):
<<<<<<< HEAD
			return search(node->children[1], num);
			break;
		case (node->values[1] < num && num < node->values[2]):
			return search(node->children[2], num);
			break;
		case (node->values[2] < num):
			return search(node->children[3], num);
			break;
		default:
			break;
	}
=======
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
>>>>>>> 8ed1b2ec703342b2314f222418276914814727dc
}