//Node functions

Node::Node(BTree tree)
{
	values = new short[4];
	if(tree.getOrder() == 0) 
	{ 
		isRoot = true; 
		tree.incrementOrder();
		tree.setRoot(this);
	}
	else
	{
		isLeaf = true;
	}
	level = tree.getOrder();
	nodeNum = tree.incrementNum();
	children = new Node *[5];
	for(int i = 0; i < 5; i++)
	{
		children[i] = NULL;
	}
}

Node::~Node()
{
	for(int i = 0; i < 5; i++)
	{
		delete children[i];
	}
}



short Node::getNodeNum() { return nodeNum; }

void Node::changeNodeNum(short num) { nodeNum = num; return; }

void Node::setLeaf() { isLeaf = true; return; }

void BTree::setRoot(Node *temp) { root = temp; return; }

bool Node::getLeaf() { return isLeaf; }

bool Node::getRoot() { return isRoot; }

//Tree Functions

BTree::BTree()
{
	tree = new BTree();
	order = 0;
	root = NULL;
	numOfNodes = 0;
}

void sort(short *p, short n)
{
	short i, j, temp;
	for(i = 0; i < n; i++)
	{
		for(j = i; j <= n; j++)
		{	if(p[i] > p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

void BTree::insert(short num)
{
	short i, temp;
	Node *x = new Node(*tree);
	x = root;

	if(x == NULL)
	{
		root = new Node(*tree);
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

Node BTree::getRoot() { return *root; }

short BTree::incrementNum() { numOfNodes++; return numOfNodes; }

short BTree::decrementNum() { numOfNodes--; return numOfNodes; }

void BTree::incrementOrder() { order++; return; }

void BTree::decrementOrder() { order--; return; }

short BTree::getOrder() { return order; }

bool BTree::checkLeaf(Node temp) { return temp.getLeaf(); }

short BTree::split(Node node, short num)
{
	int mid = 0;

	if(num == -1)
	{
		mid = node.getVal(2);
		node.	
	}

	return mid;
}
//hello