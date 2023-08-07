#pragma once
#include <iostream>

#define SIZE 5

template <typename T>
class LinearQueue {
private:
	int front;
	int rear;
	int size;
	T array[SIZE] = {};

public:
	LinearQueue() {
		front = 0;
		rear = 0;
		size = 0;

	}

	void Push(T data) {
		if (!IsFull()) {
			array[rear] = data;
			rear++;
			size++;
		}
	}

	void Pop() {
		if (!Empty()) {
			array[front] = NULL;
			front++;
			size--;
		}
	}

	int& Size() {
		return size;
	}

	T& Front() {
		return array[front];
	}

	T& Back() {
		return array[rear - 1];
	}

	bool Empty() {
		if (front == rear) {
			return true;
		}
		else {
			return false;
		}
	}

	bool IsFull() {
		if (rear >= SIZE) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
#pragma region ���� ť
	// �迭�� ������ �� �����Ͱ� �����Ǿ�
	// �����͸� �������� �ʱ�ȭ���� ������
	// ���� �����Ͱ� �ִ� �迭�� �ڸ��� �� �̻�
	// �ٸ� ���� �� �� ���� ������ Queue�Դϴ�.

#pragma endregion
	LinearQueue<int> queue;

	queue.Push(10);
	queue.Push(20);
	queue.Push(30);
	queue.Push(40);
	queue.Push(50);

	std::cout << queue.Front() << std::endl;
	std::cout << queue.Back() << std::endl;
	std::cout << queue.Size() << std::endl;
	std::cout << queue.IsFull() << std::endl;

	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();

	return 0;
}