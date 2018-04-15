//Node functions
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

void traverse(Node *p)
{
	for(int i = 0; i < p->stored; ++i)
	{
		traverse(p->children[i]);
		cout << p->values[i];
	}
	traverse (p->children[p->stored-1]);
	
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

short split(Node *node, short num)
{
	short mid, i;

	Node *x,*y,*z;
	y = construct();
	y->isLeaf = true;
	if(num == -1)
	{
		mid = node->values[2];
		node->values[2]=0;
		node->stored--;
		x = construct();
		x->isLeaf = false;
		node->isLeaf = true;

		for(i = 2; i < 4; i++)
		{
			y->values[i - 2] = node->values[i];
			y->children[i - 2] = node->children[i];
			y->stored++;
			node->values[i] = 0;
			node->stored--;
		}

		for(i = 0; i < 5; i++)
		{
			node->children[i] = NULL;
		}

		x->values[0] = mid;
		x->children[x->stored] = node;
		x->children[x->stored + 1] = y;
		x->stored++;
		root = x;
	}
	else
	{
		z = node->children[num];
		mid = z->values[2];
		z->values[2] = 0;
		z->stored--;

		for(i = 2; i < 4; i++)
		{
			y->values[i - 2] = z->values[i]; 
			y->stored++;
			z->values[i] = 0;
			z->stored--;
		}

		node->children[num + 1] = z;
		node->children[num + 1] = y;
	}

	return mid;
}

void insert(short num)
{
	short i, temp;
	x = root;

	if(x == NULL)
	{
		root = construct();
		x = root;
	}
	else
	{
		if(x->isLeaf && x->stored == 4)
		{
			temp = split(x, -1);
			x = root;
			for(i = 0; i < (x->stored); i++)
			{
				if((num > x->values[i]) && (num < x->values[i+1]))
				{
					i++;
					break;
				}
				else if ( num < x->values[0])
				{
					break;
				}
				else
				{
					continue;
				}
			}
			x = x->children[i];
		}
		else
		{
			while (x->isLeaf == false)
			{
				for(i = 0; i < (x->stored); i++)
				{
					if((num > x->values[i]) && (num < x->values[i+1]))
					{
						i++;
						break;
					}
					else if(num < x->values[0])
					{
						break;
					}
					else
					{
						continue;
					}
				}
				if((x->children[i])->stored == 4)
				{
					temp = split(x,i);
					x->values[x->stored] = temp;
					x->stored++;
					continue;
				}
				else
				{
					x = x->children[i];
				}
			}
		}
	}
	x->values[x->stored] = num;
	sort(x->values, x->stored);
	x->stored++;
}

Node * search(Node *node, short num)
{
	Node *found, *temp;

	bool check1 = false;
	bool check2 = false;

	found = construct();
	found->isLeaf = false;

	temp = construct();
	temp->isLeaf = false;

	for(short i = 0; i < node->stored; i++)
	{
		if(node->values[i] == num)
		{
			found = node;
			break;
		}
	}


	if(found->isLeaf == true)
		return found;
	else
	{
		for(short i = 0; i < 5; i++)
		{		
			if(found->children[i] != NULL)
				temp = search(found->children[i], num);
			if(temp == NULL)
				continue;
			if(temp->isLeaf == true)
				return temp;
		}	


	}

	for(short i = 0; i < 5; i++)
	{
		if(node->children[i] != NULL)
			temp = search(node->children[i], num);	
		for(short j = 0; j < temp->stored; j++)
		{
			if(temp->values[i] == num)
				check1 = true;
		}
		if(temp->isLeaf == true)
			check2 = true;
		if(check1 == true && check2 == true)
			return temp;
	}

	temp = NULL;

	return temp;
}

void deletion(short num)
{
	Node *loc;

	loc = search(root, num);

	if(loc == NULL)
		return;
	else
	{
		for(short i = 0; i < loc->stored; i++)
		{
			
		}
	}


	return;
}


//hello