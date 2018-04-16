void insert(short num)
{

	
}

Node * search(Node *node, short num)
{
	if(node->isLeaf == true)
		return node;

	switch (num)
	{
		case (num < node->values[0]):
			return search(node->children[0], num);
			break;
		case (node->values[0] < num && num < node->values[1]):
			return search(node->children[1]);
			break;
		case (node->values[1] < num && num < node->values[2]):
			return search(node->children[2]);
			break;
		case (node->values[2] < num):
			return search(node->children[3]);
			break;
	}
}