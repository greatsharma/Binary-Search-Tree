#include "../header/Queue.h"

queue::queue(int size) : size(size),front(-1),rear(-1)
{
	array = new const Node*[size];
}

void queue::enqeue(const Node *node)
{
	array[rear++] = node;
}

const Node* queue::deqeue()
{
	return array[front++];
}

bool queue::isEmpty() const
{
	return front == size - 1;
}