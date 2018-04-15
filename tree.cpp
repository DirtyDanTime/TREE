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
	for(int i = 0; i < 6; i++)
	{
		children[i] = NULL;
	}
}

Node::~Node()
{
	for(int i = 0; i < 6; i++)
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
	order = 0;
	root = NULL;
	numOfNodes = 0;
}

void BTree::insert(short num)
{
	short i, temp;
	Node *x = new Node(*tree);
	x = root;
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