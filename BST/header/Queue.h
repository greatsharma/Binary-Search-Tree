#ifndef __QUEUE__
#define __QUEUE__

#include "Node.h"
class queue
{
private:
	int size;
	int front, rear;
	Node const **array;

public:
	queue(int);
	void enqeue(const Node*);
	const Node* deqeue();
	bool isEmpty() const;
};

#endif