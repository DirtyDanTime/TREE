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