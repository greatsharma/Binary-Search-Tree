#include "../header/Stack.h"

stack::stack(int size) : size(size), top(-1)
{
	array = new const Node*[size];
}

void stack::push(const Node* node)
{
	array[++top] = node;
}

const Node* stack::pop()
{
	return array[top--];
}

bool stack::isEmpty() const
{
	return top == -1;
}