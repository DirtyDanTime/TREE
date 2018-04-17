#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <iomanip>

using namespace std;

struct Node
{
        Node *parent;
        short *values;
        Node **children;
        Node *next;
        bool isLeaf;
        short stored;
}*root = NULL, *ptr = NULL;

Node * construct();

void sort(short *p, short n);

void split(Node *node, Node *last, short *num);

void insert(short num);

void parentDelete(Node *node, short num, short replace);

Node * search(short num, bool exact);

Node * subSearch(Node *node, Node *par, short num);

void remove(short num);

void merge(Node *node, short del, short num);

void output(Node *node);
#include "thedream.cpp"



#endif


