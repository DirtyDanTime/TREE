//Node functions

Node::Node()
{
	values = new short[4];
	if(getOrder() == 0) { isRoot = true; incrementOrder(); }
	isLeaf = true;
	level = getOrder();
	nodeNum = incrementNum();
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

short Node::getVal(short loc)
{
	switch(loc):
	{
		case 1:
			if(values[0] != NULL)
				return numOne;
			break;
		case 2:
			if(values[1] != NULL)
				return numTwo;
			break;
		case 3:
			if(values[2] != NULL)
				return numThree;
			break;
		case 4:
			if(values[3] != NULL)
				return numFour;
			break;
		default:
			cout << endl << "Desired node value doesn't exist!" << endl;
			return;
			break;
	}

	cout << endl << "Desired node value NULL!" << endl;

	return;
}


short Node::getNodeNum() { return nodeNum; }

void Node::changeNodeNum(short num) { nodeNum = num; return; }

void Node::setLeaf() { isLeaf = true; return; }

void Node::setRoot() { isRoot = true; return; }

bool Node::getLeaf() { return isLeaf; }

bool Node::getRoot() { return isRoot; }

//Tree Functions

BTree::BTree()
{
	order = 0;
	root = NULL;
	numOfNodes = 0;
}

Node::~Node() {}

short BTree::incrementNum() { numOfNodes++; return numOfNodes; }

short BTree::decrementNum() { numOfNodes--; return numOfNodes; }

void BTree::incrementOrder() { order++; return; }

void BTree::decrementOrder() { order--; return; }

short BTree::getOrder() { return order; }

bool BTree::checkLeaf(Node temp) { return temp.getLeaf(); }