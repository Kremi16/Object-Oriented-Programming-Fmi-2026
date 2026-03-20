#include "Stack.h"

Stack::Stack() :size(DEFAULT_SIZE)
{
	stack = new int[size];
}

Stack::~Stack()
{
	delete[]stack;
}

Stack::Stack(const Stack& other)
{
	copyFrom(other);
}

void Stack::copyFrom(const Stack& other)
{
	size = other.size;
	capacity = other.capacity;
	stack = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		stack[i] = other.stack[i];
	}
}

void Stack::free()
{
	delete[]stack;
	stack = nullptr;
	size = 0;
}

Stack& Stack::operator=(const Stack& other)
{
	if (this == &other)
	{
		return *this;
	}

	free();
	copyFrom(other);

	return *this;
}

Stack::Stack(size_t size) :size(size)
{
	stack = new int[size];
}

void Stack::push(int a)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	stack[size] = a;
	size++;
}

int Stack::pop()
{
	if (size == DEFAULT_SIZE)
	{
		return 0;
	}

	int last = stack[size];

	size--;
	return last;
}

int Stack::peek()
{
	if (size == DEFAULT_SIZE)
	{
		return 0;
	}

	return stack[size];
}

void Stack::resize(const size_t newCapacity)
{
	capacity = newCapacity;
}
