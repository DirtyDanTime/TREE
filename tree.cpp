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
	leftChild->null;
	rightChild->null;
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
	if(loc == 1)
		return numOne;
	else if(loc == 2)
		return numTwo;
	else if(loc == 3)
		return numThree;
	else if(loc == 4)
		return numFour;
	else
		return;
}

void Node::setVal(short num)
{
	if()
}