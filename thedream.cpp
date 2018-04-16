

#include <iostream>
#include <stdio.h>

using namespace std;


Node * construct()
{
	ptr = new Node;
	ptr->parent = NULL;
	ptr->values = new short[3];

	ptr->children = new Node *[4];
	ptr->isLeaf = true;
	ptr->stored = 0;
	for(short i = 0; i < 4; i++)
	{
		ptr->children[i] = NULL;
	}
	return ptr;
}
LeafNode * leaf()
{
	p = new LeafNode;
	p->values = new short[3];
	p->next = new LeafNode;
	p->isLeaf = true;
	p->stored = 0;
	return p;
}

void sort(short *p, short n)
{
	short temp;
	for(short i = 0; i < n; i++)
	{
		for(short j = i; j <= n; j++)
		{	if(p[i] > p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
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
		short *four = new short[4];
		for(int i = 0; i < 3; i++)
		{
			four[i] = ptr->values[i];
		}
		four[3] = n;
		sort(four, 4)
		split(ptr, four)
	}

}

void split(Node *node, short *num)
{
	Node *parent = node->parent;
	if(parent->children[3] != NULL)
	{

	}
	else
	{
		Node *leftNode = construct();
		leftNode->parent = node->parent;
		leftNode->values[0] = num[0];
		leftNode->values[1] = num[1];
		leftNode->children[0]
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

void deletion(short num)
{
   LeafNode *temp;

    temp = search(num);

    if(temp != NULL)
    {
        if(temp->values[0] == num)
        {
            temp->values[0] = temp->values[1];
            temp->values[1] = temp->values[2];
            temp->values[2] = 0;
        }

        if(temp->values[1] == num)
        {
            temp->values[1] = temp->values[2];
            temp->values[2] = 0;
        }

        else
            temp->values[2] = 0;

        temp->stored -= 1;

        if(temp->stored < 2)
        {
            merge(temp, num);
        }

        parentDelete(temp, num);
    }
    return;

}

LeafNode * search(short num)
{
	LeafNode *temp = leaf();
	temp = subSearch(root, NULL, num);
	bool exist = false;

	for(short i = 0; i < temp->stored; i++)
	{
		if(temp->values[i] == num)
			exist = true;
	}

	if(exist == true)
		return temp;
	else 
		return NULL;
}

LeafNode * subSearch(Node *node, Node *par, short num)
{
	if(node->isLeaf == true)
	{
		node->parent = par;
		return leafSwap(node);
	}

	
	if(num < node->values[0])
		return subSearch(node->children[0], node, num);
	else if(node->values[0] < num && num < node->values[1])
		return subSearch(node->children[1], node, num);
	else if(node->values[1] < num && num < node->values[2])
		return subSearch(node->children[2], node, num);
	else if(node->values[2] < num)
		return subSearch(node->children[3], node, num);
		

}