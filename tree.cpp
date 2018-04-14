Node::Node()
{
	numOne = null;
	numTwo = null;
	numThree = null;
	numFour = null;
	if(getOrder() == 0) { isRoot = true; incrementOrder(); }
	isLeaf = true;
	level = getOrder();
	nodeNum = incrementNum();
	childOne->null;
	childTwo->null;
	childThree->null;
	childFour->null;
	childFive->null;
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
			if(numOne != null)
				return numOne;
			break;
		case 2:
			if(numTwo null)
				return numTwo;
			break;
		case 3:
			if(numThree != null)
				return numThree;
			break;
		case 4:
			if(numFour != null)
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

