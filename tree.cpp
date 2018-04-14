//Node functions

Node::Node()
{
	numOne = NULL;
	numTwo = NULL;
	numThree = NULL;
	numFour = NULL;
	if(getOrder() == 0) { isRoot = true; incrementOrder(); }
	isLeaf = true;
	level = getOrder();
	nodeNum = incrementNum();
	childOne-> NULL;
	childTwo-> NULL;
	childThree-> NULL;
	childFour-> NULL;
	childFive-> NULL;
}

Node::~Node()
{
	delete childOne;
	delete childTwo;
	delete childThree;
	delete childFour;
	delete childFive	
}

short Node::getVal(short loc)
{
	switch(loc):
	{
		case 1:
			if(numOne != NULL)
				return numOne;
			break;
		case 2:
			if(numTwo != NULL)
				return numTwo;
			break;
		case 3:
			if(numThree != NULL)
				return numThree;
			break;
		case 4:
			if(numFour != NULL)
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

void Node::setVal(short num)
{
	if()

}

short Node::getNodeNum() { return nodeNum; }

void Node::changeNodeNum(short num) { nodeNum = num; return; }

void Node::setLeaf() { isLeaf = true; return; }

void Node::setRoot() { isRoot = true; return; }

//Tree Functions



