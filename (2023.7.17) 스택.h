#pragma once
#include <iostream>

#define SIZE 5

template <typename T>
class STACK {
private:
	int top;
	T buffer[SIZE];

public:
	STACK() {
		top = -1;
	}

	void Push(T data) {
		if (IsFull()) {
			std::cout << "STACK FULL" << std::endl;
		}
		else {
			buffer[++top] = data;
		}
	}

	T Pop() {
		if (Empty()) {
			std::cout << "STACK EMPTY" << std::endl;
			exit(1);
		}
		else {
			return buffer[top--];
		}
	}

	T Top() {
		if (Empty()) {
			return 0;
		}
		else {
			return buffer[top];
		}
	}

	bool Empty() {
		if (top <= -1) {
			top = -1;
			return true;
		}
		else {
			return false;
		}
	}

	bool IsFull() {
		if (top >= SIZE - 1) {
			top = SIZE - 1;
			return true;
		}
		else {
			return false;
		}
	}

	~STACK() {

	}
};

int main() {
	STACK<int> stack;

	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(40);
	stack.Push(50);
	stack.Push(60);

	while (stack.Empty() == false) {
		std::cout << stack.Top() << std::endl;
		stack.Pop();
	}

	return 0;
}