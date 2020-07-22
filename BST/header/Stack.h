#ifndef __STACK__
#define __STACK__

#include "Node.h"

class stack
{
private:
	int top;
	int size;
	Node const **array;

public:
	stack(int);
	void push(const Node*);
	const Node* pop();
	bool isEmpty() const;
};
#endif 