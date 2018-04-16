#include "tree.h"


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