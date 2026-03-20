#pragma once
class Stack
{
private:
	static constexpr int DEFAULT_SIZE = 0;
	int* stack;
	size_t size;
	size_t capacity;

	void copyFrom(const Stack& other);
	void free();
	void resize(const size_t newCapacity);

public:
	Stack();

	~Stack();

	Stack(size_t size);

	Stack(const Stack& other);

	Stack& operator=(const Stack& other);

	void push(int a);

	int pop();

	int peek();
};

