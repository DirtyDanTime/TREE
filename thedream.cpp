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
	ptr->next = NULL;
	for(short i = 0; i < 4; i++)
	{
		ptr->children[i] = NULL;
	}
	return ptr;
}
/*{
	p = new LeafNode;
	p->values = new short[3];
	p->next = new LeafNode;
	p->isLeaf = true;
	p->stored = 0;
	return p;
}*/

void sort(short *p, short n)
{
	short temp;
	for(short i = 0; i < n; i++)
	{
		for(short j = i; j < n; j++)
		{	if(p[i] > p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

void output()
{

}
//hey tyler

void insert(short n)
{

	Node *p = construct();
	if(root == NULL)
	{
		root = construct();
		p = root;
	}
	else
	{
		p = search(n, false);
	}
	if(p->stored < 3)
	{
		p->values[ptr->stored] = n;
		p->stored++;
		if(p->stored > 1)
			sort(p->values, p->stored);
	}
	else
	{
		short *four = new short[4];
		for(int i = 0; i < 3; i++)
		{
			four[i] = ptr->values[i];
		}
		four[3] = n;
		cout << "1" << endl;
		sort(four, 4);
		split(p, NULL, *four);
	}

}

void split(Node *node, Node *last, short *num)
{
	Node *parent = node->parent;

	if(parent != NULL)
	{
		if(last == NULL) 
		{
			Node *newNode = construct();
			node->values[0] = num[0];
			node->values[1] = num[1];
			node->values[2] = 0;
			if(node->isLeaf)
				node->next = newNode;
			else
				newNode->isLeaf = false;
			newNode->parent = node->parent;
			newNode->values[0] = num[2];
			newNode->values[1] = num[3];
			node->next = newNode;
			

			if(parent->stored == 3)
			{
				short *four = new short[4];
				for(int i = 0; i < 3; i++)
				{
					four[i] = parent->values[i];
				}
				four[3] = num[1];
				sort(four, 4);
				split(parent, newNode, four);
			}
			else
			{
				parent->values[parent->stored] = num[1];
				parent->stored++;
				sort(parent->values, parent->stored);
			
				for(int i = 0; i < parent->stored+1; i++)
				{
					if(parent->children[i]->values[0] == node->values[0])
					{
						parent->children[i] = node;
						for(int j = parent->stored-1; j > i; j--)
						{
							parent->children[j+1] = parent->children[j];
						}
						parent->children[i+1] = newNode;
						break;
					}
				}
			}

		}
		else
		{
			Node *newNode = construct();
			if(last->values[0] > node->children[0]->values[0] && last->values[0] < node->children[1]->values[0])
			{
				newNode->children[0] = node->children[1];
				newNode->children[1] = node->children[2];
				newNode->children[2] = node->children[3];
				node->children[1] = last;
				node->children[2] = NULL;
				node->children[3] = NULL;
			}
			else if(last->values[0] > node->children[1]->values[0] && last->values[0] < node->children[2]->values[0])
			{
				newNode->children[0] = last;
				newNode->children[1] = node->children[2];
				newNode->children[2] = node->children[3];
				node->children[2] = NULL;
				node->children[3] = NULL;
			}
			else if(last->values[0] > node->children[2]->values[0] && last->values[0] < node->children[3]->values[0])
			{
				newNode->children[0] = node->children[2];
				newNode->children[1] = last;
				newNode->children[2] = node->children[3];
				node->children[2] = NULL;
				node->children[3] = NULL;
			}
			else if(last->values[0] > node->children[3]->values[0])
			{
				newNode->children[0] = node->children[2];
				newNode->children[1] = node->children[3];
				newNode->children[2] = last;
				node->children[2] = NULL;
				node->children[3] = NULL;
			}
			node->values[0] = num[0];
			node->values[1] = 0;
			node->values[2] = 0;
			node->stored = 1;
			if(node->isLeaf)
				node->next = newNode;
			else
				newNode->isLeaf = false;
			newNode->parent = parent;
			newNode->values[0] = num[2];
			newNode->values[1] = num[3];
			newNode->stored = 2;
			if(parent->stored == 3)
			{
				short *four = new short[4];
				for(int i = 0; i < 3; i++)
				{
					four[i] = parent->values[i];
				}
				four[3] = num[1];
				sort(four, 4);

				split(parent, newNode, four);
			}
			else
			{
				parent->values[parent->stored] = num[1];
				parent->stored++;
				sort(parent->values, parent->stored);
			
				for(int i = 0; i < parent->stored+1; i++)
				{
					if(parent->children[i]->values[0] == node->values[0])
					{
						for(int j = parent->stored-1; j > i; j--)
						{
							parent->children[j+1] = parent->children[j];
						}
						parent->children[i+1] = newNode;
						break;
					}
				}
			}

		}
	}
	else
	{

		Node *newNode = construct();
		Node *newRoot = construct();
		if(last != NULL)
		{
			if(last->values[0] > node->children[0]->values[0] && last->values[0] < node->children[1]->values[0])
			{
				newNode->children[0] = node->children[1];
				newNode->children[1] = node->children[2];
				newNode->children[2] = node->children[3];
				node->children[1] = last;
				node->children[2] = NULL;
				node->children[3] = NULL;
			}
			else if(last->values[0] > node->children[1]->values[0] && last->values[0] < node->children[2]->values[0])
			{
				newNode->children[0] = last;
				newNode->children[1] = node->children[2];
				newNode->children[2] = node->children[3];
				node->children[2] = NULL;
				node->children[3] = NULL;
			}
			else if(last->values[0] > node->children[2]->values[0] && last->values[0] < node->children[3]->values[0])
			{
				newNode->children[0] = node->children[2];
				newNode->children[1] = last;
				newNode->children[2] = node->children[3];
				node->children[2] = NULL;
				node->children[3] = NULL;
			}
			else if(last->values[0] > node->children[3]->values[0])
			{
				newNode->children[0] = node->children[2];
				newNode->children[1] = node->children[3];
				newNode->children[2] = last;
				node->children[2] = NULL;
				node->children[3] = NULL;
			}
		}
		else
		{
			node->parent = newRoot;
			node->values[0] = num[0];
			node->values[1] = num[1];
			node->values[2] = 0;
			node->stored = 1;
			newNode->parent = newRoot;
			newNode->values[0] = num[2];
			newNode->values[1] = num[3];
			newNode->stored = 2;
			if(node->isLeaf)
				node->next = newNode;
			else
				newNode->isLeaf = false;
			newRoot->stored = 1;
			newRoot->values[0] = num[1];
			newRoot->children[0] = node;
			newRoot->children[1] = newNode;
			newRoot->isLeaf = false;
			root = newRoot;
			return;
		}
		node->parent = newRoot;
		node->values[0] = num[0];
		node->values[1] = 0;
		node->values[2] = 0;
		node->stored = 1;
		newNode->parent = newRoot;
		newNode->values[0] = num[2];
		newNode->values[1] = num[3];
		newNode->stored = 2;
		if(node->isLeaf)
			node->next = newNode;
		else
			newNode->isLeaf = false;
		newRoot->stored = 1;
		newRoot->values[0] = num[1];
		newRoot->children[0] = node;
		newRoot->children[1] = newNode;
		newRoot->isLeaf = false;
		root = newRoot;
	}

}

Node * childfind()
{

}

void parentDelete(Node *node, short num, short replace)
{
	short place = 99;

	if(node != NULL)
	{
		for(short i = 0; i < node->stored; i++)
		{
			if(node->values[i] == num)
			{
				node->values[i] = replace;			
				return;
			}
			
		}

	}
	else { return; }

	parentDelete(node->parent, num, replace);
	
	return;
}

void merge(Node *node, short num)
{
	Node *temp = construct();
	temp = node->parent;
	short child = 0; 
	bool place = false;
	short childNo = 0;

	for(short i = 0; i < 4; i++)
	{
		child = temp->children[i]->values[0];
		if(child == num)
			place = true;
		if(place == true)
		{
			childNo = i;
			break;
		}
	}	

	switch (childNo)
	{
		case 0:
			if(temp->children[1]->stored == 3)
			{
				node->values[1] = temp->children[1]->values[0];
				temp->values[0] = temp->children[1]->values[0];
				temp->children[1]->values[0] = temp->children[1]->values[1];
				temp->children[1]->values[1] = temp->children[1]->values[2];
				temp->children[1]->values[2] = 0;
				temp->children[0]->stored = 2;
				temp->children[1]->stored = 2;
				return;
			}
			else if(temp->children[1]->stored <= 2)
			{
				temp->values[0] = temp->values[1];
				temp->values[1] = temp->values[2];
				temp->values[2] = 0;
				temp->children[0]->values[1] = temp->children[1]->values[0]; 
				temp->children[0]->values[2] = temp->children[1]->values[1];
				temp->children[1] = temp->children[2];
				temp->children[2] = temp->children[3];
				temp->children[3] = NULL;
				temp->children[0]->stored = 3;

				return;
			}

			break;
		case 1:
			if(temp->children[0]->stored  == 3)
			{
				node->values[1] = node->values[0];
				node->values[0] = temp->children[0]->values[2];
				temp->values[0] = temp->children[0]->values[1];
				temp->children[0]->values[2] = 0;
				temp->children[0]->stored = 2;
				temp->children[1]->stored = 2;
				
				return;
			}
			else if(temp->children[2]->stored == 3)
			{
				node->values[1] = temp->children[2]->values[0];
				temp->values[0] = temp->children[2]->values[0];
				temp->children[2]->values[0] = temp->children[2]->values[1];
				temp->children[2]->values[1] = temp->children[2]->values[2];
				temp->children[2]->values[2] = 0;
				temp->children[1]->stored = 2;
				temp->children[2]->stored = 2;
				return;
			}
			else if(temp->children[0]->stored <= 2)
			{
				temp->values[0] = temp->values[1];
				temp->values[1] = temp->values[2];
				temp->values[2] = 0;
				temp->children[0]->values[2] = temp->children[1]->values[0]; 
				temp->children[1] = temp->children[2];
				temp->children[2] = temp->children[3];
				temp->children[3] = NULL;
				temp->children[0]->stored = 3;

				return;
			}
			else if(temp->children[2]->stored <= 2)
			{
				temp->values[1] = temp->values[2];
				temp->values[2] = 0;
				temp->children[1]->values[1] = temp->children[2]->values[0]; 
				temp->children[1]->values[2] = temp->children[2]->values[1];
				temp->children[2] = temp->children[3];
				temp->children[3] = NULL;
				temp->children[1]->stored = 3;

				return;
			}

			break;
		case 2:
			if(temp->children[1]->stored  == 3)
			{
				node->values[1] = node->values[0];
				node->values[0] = temp->children[1]->values[2];
				temp->values[1] = temp->children[1]->values[1];
				temp->children[1]->values[2] = 0;
				temp->children[1]->stored = 2;
				temp->children[2]->stored = 2;
				
				return;
			}
			else if(temp->children[3]->stored == 3)
			{
				node->values[1] = temp->children[3]->values[0];
				temp->values[0] = temp->children[3]->values[0];
				temp->children[3]->values[0] = temp->children[3]->values[1];
				temp->children[3]->values[1] = temp->children[3]->values[2];
				temp->children[3]->values[2] = 0;
				temp->children[2]->stored = 2;
				temp->children[3]->stored = 2;

				return;
			}
			else if(temp->children[1]->stored <= 2)
			{
				temp->values[1] = temp->values[2];
				temp->values[2] = 0;
				temp->children[1]->values[2] = temp->children[2]->values[0]; 
				temp->children[2] = temp->children[3];
				temp->children[3] = NULL;
				temp->children[1]->stored = 3;

				return;
			}
			else if(temp->children[3]->stored <= 2)
			{
				temp->values[2] = 0;
				temp->children[2]->values[1] = temp->children[3]->values[0]; 
				temp->children[2]->values[2] = temp->children[3]->values[1];
				temp->children[3] = NULL;
				temp->children[2]->stored = 3;

				return;
			}

			break;
		case 3:
			if(temp->children[2]->stored  == 3)
			{
				node->values[1] = node->values[0];
				node->values[0] = temp->children[2]->values[2];
				temp->values[1] = temp->children[2]->values[1];
				temp->children[2]->values[2] = 0;
				temp->children[2]->stored = 2;
				temp->children[3]->stored = 2;

				return;
			}
			else if(temp->children[2]->stored <= 2)
			{
				temp->values[2] = 0;
				temp->children[2]->values[2] = temp->children[3]->values[0]; 
				temp->children[3] = NULL;
				temp->children[2]->stored = 3;

				return;
			}

			break;
	}

	

	return;

}

void deletion(short num)
{

    Node *temp;

    temp = search(num, true);

    short amount = temp->stored;
    short first = 0;
    short rep = temp->values[amount - 1];

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
        	first = temp->values[0];
            merge(temp, first);
            parentDelete(temp, num, rep);
            return;
        }

        parentDelete(temp, num, rep);
    }
    return;

}

Node * search(short num, bool exact)
{
	Node *temp = leaf();
	temp = subSearch(root, NULL, num);
	bool exist = false;

	if(exact == true)
	{	
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
	else 
		return temp;
}

Node * subSearch(Node *node, Node *par, short num)
{
	if(node->isLeaf == true)
	{
		node->parent = par;
		return node;
	}

	
	if(num < node->values[0])
		return subSearch(node->children[0], node, num);
	else if(num > node->values[0] && node->values[1] == 0)
		return
	else if(node->values[0] < num && num < node->values[1])
		return subSearch(node->children[1], node, num);
	else if(node->values[1] < num && num < node->values[2])
		return subSearch(node->children[2], node, num);
	else if(node->values[2] < num)
		return subSearch(node->children[3], node, num);
		

	return node;
}