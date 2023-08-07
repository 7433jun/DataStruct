#pragma once
#include <iostream>

#define SIZE 4

template <typename T>
class CircleQueue {
private:
	int front;
	int rear;
	T buffer[SIZE];
public:
	CircleQueue() {
		front = SIZE - 1;
		rear = SIZE - 1;
		buffer[SIZE - 1] = {};
	}

	void Push(T data) {
		if (!IsFull()) {
			rear++;
			buffer[rear % SIZE] = data;

			if (front > 3 && rear > 3) {
				front -= 4;
				rear -= 4;
			}
		}
		else {
			exit(1);
		}
	}

	void Pop() {
		if (!Empty()) {
			front++;
			buffer[front % SIZE] = NULL;
		}
		else {
			exit(1);
		}
	}

	T& Front() {
		return buffer[(front + 1) % SIZE];
	}

	T& Back() {
		return buffer[rear % SIZE];
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
		if (rear - front == 4) {
			return true;
		}
		else {
			return false;
		}
	}

	int GetFront() {
		return front;
	}

	int GetRear() {
		return rear;
	}
};

int main() {
#pragma region 원형 큐
	// 물리적으로는 선형 구조를 가지고 있으며,
	// 큐의 시작점과 끝점을 연결한 큐입니다.
#pragma endregion

	CircleQueue<int> queue;

	queue.Push(10);
	queue.Push(20);
	queue.Push(30);
	queue.Push(40);

	std::cout << queue.Front() << std::endl;
	std::cout << queue.Back() << std::endl;

	std::cout << queue.GetFront() << std::endl;
	std::cout << queue.GetRear() << std::endl;

	queue.Pop();
	queue.Push(50);

	std::cout << queue.Front() << std::endl;
	std::cout << queue.Back() << std::endl;

	std::cout << queue.GetFront() << std::endl;
	std::cout << queue.GetRear() << std::endl;

	return 0;
}