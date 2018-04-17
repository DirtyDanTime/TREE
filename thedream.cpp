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


void output(Node *node)
{
        short mid = 45;
        if(node->parent == NULL)
        {
                for(int i = 0; i < node->stored; i++)
                {
                        if(i == 0)
                                cout << setw(mid) << node->values[i] << setw(0);
                        else if(i != node->stored-1)
                                cout << "-" << node->values[i];
                        else
                                cout << "-" << node->values[i];
                }
                cout << endl << endl << endl;
        }

        if(node->children[0] != NULL)
        {
                if(node->stored+1 == 2)
                {
                        for(int i = 0; i < node->stored+1; i++)
                        {
                                for(int j = 0; j < node->children[i]->stored; j++)
                                {
                                        if(j == 0 && i == 0)
                                                cout <<setw(3*mid/4) << node->children[i]->values[j] << setw(0);
                                        else if(j ==0)
                                                cout <<setw(mid/2) << node->children[i]->values[j] << setw(0);
                                        else if(j != node->children[i]->stored-1)
                                                cout << "-" << node->children[i]->values[j];
                                        else
                                                cout << "-" << node->children[i]->values[j];
                                }
                        }
                }
                else if(node->stored+1 == 3)
                {
                        for(int i = 0; i < node->stored+1; i++)
                        {
                                for(int j = 0; j < node->children[i]->stored; j++)
                                {
                                        if(j == 0 && i == 0)
                                                cout <<setw(2*mid/3) << node->children[i]->values[j] << setw(0);
                                        else if(j ==0)
                                                cout <<setw(mid/5+1) << node->children[i]->values[j] << setw(0);
                                        else if(j != node->children[i]->stored-1)
                                                cout << "-" << node->children[i]->values[j];
                                        else
                                                cout << "-" << node->children[i]->values[j];
                                }
                        }
                }
                if(node->stored+1 == 4)
                {
                        for(int i = 0; i < node->stored+1; i++)
                        {
                                for(int j = 0; j < node->children[i]->stored; j++)
                                {
                                        if(j == 0 && i == 0)
                                                cout <<setw(5*mid/8) << node->children[i]->values[j] << setw(0);
                                        else if(j ==0)
                                                cout <<setw(mid/5) << node->children[i]->values[j] << setw(0);
                                        else if(j != node->children[i]->stored-1)
                                                cout << "-" << node->children[i]->values[j];
                                        else
                                                cout << "-" << node->children[i]->values[j];
                                }
                        }
                }
        }

        cout << endl << endl << endl;
        if(node->children[0]->children[0] != NULL)
        {

                short num = 0;
                node = root->children[0];
                do
                {

                        if(node->children[0] != NULL)
                        {
                                if(node->stored+1 == 2)
                                {
                                        if(num == 0)
                                                cout << setw(22);
                                        else
                                                cout << setw(0);
                                        for(int i = 0; i < node->stored+1; i++)
                                        {
                                                for(int j = 0; j < node->children[i]->stored; j++)
                                                {
                                                        if(j == 0 && i == 0)
                                                                cout << "    " << node->children[i]->values[j] << setw(0);
                                                        else if(j ==0)
                                                                cout << "    " << node->children[i]->values[j] << setw(0);
                                                        else if(j != node->children[i]->stored-1)
                                                                cout << "-" << node->children[i]->values[j];
                                                        else
                                                                cout << "-" << node->children[i]->values[j] << "->";
                                                }
                                        }
                                }
                                else if(node->stored+1 == 3)
                                {
                                        if(num == 0)
                                                cout << setw(15);
                                        else
                                                cout << setw(0);
                                        for(int i = 0; i < node->stored+1; i++)
                                        {
                                                for(int j = 0; j < node->children[i]->stored; j++)
                                                {
                                                        if(j == 0 && i == 0)
                                                                cout << "  " << node->children[i]->values[j] << setw(0);
                                                        else if(j ==0)
                                                                cout << "  " << node->children[i]->values[j] << setw(0);
                                                        else if(j != node->children[i]->stored-1)
                                                                cout << "-" << node->children[i]->values[j];
                                                        else
                                                                cout << "-" << node->children[i]->values[j] << "->";
                                                }

                                        }
                                }
                                else if(node->stored+1 == 4)
                                {
                                        if(num ==0)
                                                cout << setw(8);
                                        else
                                                cout << setw(0);
                                        for(int i = 0; i < node->stored+1; i++)
                                        {
                                                for(int j = 0; j < node->children[i]->stored; j++)
                                                {
                                                        if(j == 0 && i == 0)
                                                                cout << " " << node->children[i]->values[j] << setw(0);
                                                        else if(j ==0)
                                                                cout << " " << node->children[i]->values[j] << setw(0);
                                                        else if(j != node->children[i]->stored-1)
                                                                cout << "-" << node->children[i]->values[j];
                                                        else
                                                                cout << "-" << node->children[i]->values[j] << "->";
                                                }
                                        }
                                }
                        }
                        node = root->children[++num];

                }while(node!= NULL);
                cout << endl;
        }
}

void sort(short *p, short n)
{
        short temp;
        for(short i = 0; i < n; i++)
        {
                for(short j = i; j < n; j++)
                {       if(p[i] > p[j])
                        {
                                temp = p[i];
                                p[i] = p[j];
                                p[j] = temp;
                        }
                }
        }
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
                if(search(n, true) != NULL)
                        return;
                p = search(n, false);
        }
        if(p->stored < 3)
        {
                p->values[p->stored] = n;
                p->stored++;
                if(p->stored > 1)
                        sort(p->values, p->stored);
        }
        else
        {
                short *four = new short[4];
                for(int i = 0; i < 3; i++)
                {
                        four[i] = p->values[i];
                }
                four[3] = n;
                sort(four, 4);
                split(p, NULL, four);
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
                        node->stored = 2;
                        if(node->isLeaf)
                                node->next = newNode;
                        else
                                newNode->isLeaf = false;
                        newNode->parent = node->parent;
                        newNode->values[0] = num[2];
                        newNode->values[1] = num[3];
                        newNode->stored = 2;
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
                        root = newRoot;
                        node->parent = root;
                        node->values[0] = num[0];
                        node->values[1] = num[1];
                        node->values[2] = 0;
                        node->stored = 2;
                        newNode->parent = newRoot;
                        newNode->values[0] = num[2];
                        newNode->values[1] = num[3];
                        newNode->stored = 2;
                        if(node->isLeaf)
                                node->next = newNode;
                        else
                                newNode->isLeaf = false;
                        root->stored = 1;
                        root->values[0] = num[1];
                        root->children[0] = node;
                        root->children[1] = newNode;
                        root->isLeaf = false;
                        return;
                }
                node->parent = newRoot;
                node->values[0] = num[0];
                node->values[1] = 0;
                node->values[2] = 0;
                node->stored = 1;
                node->isLeaf = false;
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

void parentDelete(Node *node, short num, short replace)
{
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
        short numOfStored = 0;


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
                                temp->stored--;
                                temp->children[0]->values[1] = temp->children[1]->values[0];
                                temp->children[0]->values[2] = temp->children[1]->values[1];
                                temp->children[1] = temp->children[2];
                                temp->children[2] = temp->children[3];
                                temp->children[3] = NULL;
                                for(short i = 0; i < 3; i++)
                                {
                                  if(temp->children[0]->values[i] != 0)
                                          numOfStored++;
                                }
                                temp->children[0]->stored = numOfStored;

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
                                temp->stored--;
                                temp->children[0]->values[2] = temp->children[1]->values[0];
                                temp->children[1] = temp->children[2];
                                temp->children[2] = temp->children[3];
                                temp->children[3] = NULL;
                                for(short i = 0; i < 3; i++)
                                {
                                  if(temp->children[0]->values[i] != 0)
                                          numOfStored++;
                                }
                                temp->children[0]->stored = numOfStored;


                                return;
                        }
                        else if(temp->children[2]->stored <= 2)
                        {
                                temp->values[1] = temp->values[2];
                                temp->values[2] = 0;
                                temp->stored--;
                                temp->children[1]->values[1] = temp->children[2]->values[0];
                                temp->children[1]->values[2] = temp->children[2]->values[1];
                                temp->children[2] = temp->children[3];
                                temp->children[3] = NULL;
                                for(short i = 0; i < 3; i++)
                                {
                                  if(temp->children[1]->values[i] != 0)
                                          numOfStored++;
                                }
                                temp->children[1]->stored = numOfStored;


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
                        else if(temp->children[1]->stored <= 2)
                        {
                                temp->values[1] = temp->values[2];
                                temp->values[2] = 0;
                                temp->stored--;
                                temp->children[1]->values[2] = temp->children[2]->values[0];
                                temp->children[2] = temp->children[3];
                                temp->children[3] = NULL;
                                for(short i = 0; i < 3; i++)
                                {
                                  if(temp->children[1]->values[i] != 0)
                                          numOfStored++;
                                }
                                temp->children[1]->stored = numOfStored;


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
                        else if(temp->children[3]->stored <= 2)
                        {
                                temp->values[2] = 0;
                                temp->stored--;
                                temp->children[2]->values[1] = temp->children[3]->values[0];
                                temp->children[2]->values[2] = temp->children[3]->values[1];
                                temp->children[3] = NULL;
                                for(short i = 0; i < 3; i++)
                                {
                                  if(temp->children[2]->values[i] != 0)
                                          numOfStored++;
                                }
                                temp->children[2]->stored = numOfStored;


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
                                temp->stored--;
                                temp->children[2]->values[2] = temp->children[3]->values[0];
                                temp->children[3] = NULL;
                                for(short i = 0; i < 3; i++)
                                {
                                  if(temp->children[2]->values[i] != 0)
                                          numOfStored++;
                                }
                                temp->children[2]->stored = numOfStored;


                                return;
                        }

                        break;
        }



        return;

}

void remove(short num)
{

    Node *temp;

    temp = search(num, true);

    short amount = 0;
    short first = 0;
    short rep = 0;
    if(temp != NULL)
    {
        if(temp->values[0] == num)
        {
            temp->values[0] = temp->values[1];
            temp->values[1] = temp->values[2];
            temp->values[2] = 0;
            temp->stored--;

        }

        if(temp->values[1] == num)
        {
            temp->values[1] = temp->values[2];
            temp->values[2] = 0;
            temp->stored--;

        }

        else
        {
            temp->values[2] = 0;
            temp->stored--;

        }

        if(temp->stored < 2)
        {
            first = temp->values[0];
            merge(temp, first);
            amount = temp->stored;
            rep = temp->values[amount - 1];
            parentDelete(temp, num, rep);
            return;
        }
        amount = temp->stored;
        rep = temp->values[amount - 1];
        parentDelete(temp, num, rep);
    }
    else
            return;
    return;

}

Node * search(short num, bool exact)
{
        Node *temp = construct();
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
                cout << node->values[0] << endl << endl;
                return node;
        }
        if(node->stored == 1)
        {
                if(num <= node->values[0])
                        return subSearch(node->children[0], node, num);
                else if(num > node->values[0])
                        return subSearch(node->children[1], node, num);
        }
        else if(node->stored == 2)
        {
                if(num <= node->values[0])
                        return subSearch(node->children[0], node, num);
                else if(node->values[0] < num && num <= node->values[1])
                        return subSearch(node->children[1], node, num);
                else if(node->values[1] < num)
                        return subSearch(node->children[2], node, num);
        }
        else if(node->stored == 3)
        {
                if(num <= node->values[0])
                        return subSearch(node->children[0], node, num);
                else if(node->values[0] < num && num <= node->values[1])
                        return subSearch(node->children[1], node, num);
                else if(node->values[1] < num && num <= node->values[2])
                        return subSearch(node->children[2], node, num);
                else if(node->values[2] < num)
                        return subSearch(node->children[3], node, num);
        }


        return node;
}



