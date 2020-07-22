#ifndef __NODE__
#define __NODE__

class Node
{
private:
	int data;
	Node *left;
	Node *right;
public:
	friend class Tree;
	Node(int, Node* left=0,Node *right=0);
	~Node();
};

#endif