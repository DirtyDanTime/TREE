

#include <iostream>
#include <stdio.h>

using namespace std;


Node * construct()
{
	ptr = new Node;
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
	}

	switch (num)
	{
		case (num < node->values[0]):
			return search(node->children[0], num);
			break;
		case (node->values[0] < num && num < node->values[1]):
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
}