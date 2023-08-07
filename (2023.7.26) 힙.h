#pragma once
#include <iostream>

#define SIZE 8

class MAX_HEAP {
private:
	int heapArray[SIZE];
	int index;

public:
	MAX_HEAP() {
		for (int i = 0; i < SIZE; i++) {
			heapArray[i] = NULL;
		}
		index = 0;
	}

	void Insert(int data) {
		if (IsFull()) {
			return;
		}

		heapArray[++index] = data;

		Insert_Heapify(index);
	}

	int& Delete() {
		if (Empty()) {
			return index;
		}

		int temp = heapArray[1];

		heapArray[1] = heapArray[index];
		heapArray[index] = NULL;
		index--;
		Delete_Heapify(1);


		return temp;
	}

	void Insert_Heapify(int _index) {
		if (_index == 1) {
			return;
		}

		if (heapArray[_index] > heapArray[_index / 2]) {
			std::swap(heapArray[_index], heapArray[_index / 2]);
			Insert_Heapify(_index / 2);
		}
	}

	void Delete_Heapify(int _index) {
		if (_index > (SIZE - 1) / 2) {
			return;
		}

		if (heapArray[_index * 2] == NULL) {
			if (heapArray[_index * 2 + 1] == NULL) {
				return;
			}
		}

		if (heapArray[_index * 2] > heapArray[_index * 2 + 1]) {
			if (heapArray[_index * 2] > heapArray[_index]) {
				std::swap(heapArray[_index * 2], heapArray[_index]);
				Delete_Heapify(_index * 2);
			}
		}
		else {
			if (heapArray[_index * 2 + 1] > heapArray[_index]) {
				std::swap(heapArray[_index * 2 + 1], heapArray[_index]);
				Delete_Heapify(_index * 2 + 1);
			}
		}
	}

	bool IsFull() {
		if (index >= SIZE - 1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Empty() {
		if (index <= 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void Show() {
		for (int i = 1; i < SIZE; i++) {
			std::cout << heapArray[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main() {
#pragma region 힙
	// 여러 값들 중에서 최댓값 혹은 최솟값을
	// 빠르게 찾아내기 위한 자료구조입니다.

	// 최대 힙
	// 부모 노드의 키 값이 자식 노드의 키 값보다
	// 크거나 같은 완전 이진 트리
#pragma endregion
	MAX_HEAP heap;

	heap.Insert(1);
	heap.Insert(2);
	heap.Insert(3);
	heap.Insert(4);
	heap.Insert(5);
	heap.Insert(6);
	heap.Insert(7);

	heap.Show();
	heap.Delete();
	heap.Show();
	heap.Delete();
	heap.Show();
	heap.Delete();
	heap.Show();
	heap.Delete();
	heap.Show();
	heap.Delete();
	heap.Show();
	heap.Delete();
	heap.Show();
	heap.Delete();
	heap.Show();
	heap.Delete();
	heap.Show();

	return 0;
}