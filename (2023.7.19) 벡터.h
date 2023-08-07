#pragma once
#include <iostream>
#include <vector>

template <typename T>
class VECTOR {
private:
	int capacity = 0;
	int size = 0;

	T* array;
public:
	VECTOR() {
		capacity = 1;
		array = new T[capacity];
	}

	void Push_Back(T data) {
		if (size >= capacity) {
			Resize(capacity * 2);
		}
		array[size] = data;

		size++;
	}

	void Pop_Back() {
		if (size <= 0) {
			return;
		}
		array[size] = NULL;

		size--;
	}

	void Clear() {
		for (int i = 0;i < size;i++) {
			array[size] = NULL;
		}
		size = 0;
	}

	void Resize(int _size) {
		if (_size > capacity) {
			T* temp = new T[_size];

			// 새 벡터 초기화
			for (int i = 0;i < _size;i++) {
				temp[i] = NULL;
			}

			// 벡터 값 복사
			for (int i = 0;i < capacity;i++) {
				temp[i] = array[i];
			}

			// 기존 백터 해제
			delete array;
			capacity = _size;
			array = temp;
		}
		else {
			size = _size;
		}
	}

	int Size() {
		return size;
	}

	// 연산자 오버로딩 []
	T& operator [] (const int& value) {
		return array[value];
	}

	~VECTOR() {
		delete array;
	}
};

int main() {
	VECTOR<int> vector;

	vector.Push_Back(10);

	std::cout << vector[0] << std::endl;
	std::cout << vector.Size() << std::endl;
	std::cout << vector[1] << std::endl;

	vector.Push_Back(20);

	std::cout << vector[0] << std::endl;
	std::cout << vector.Size() << std::endl;
	std::cout << vector[1] << std::endl;

	vector.Push_Back(30);
	vector.Push_Back(40);
	vector.Push_Back(50);

	std::cout << vector.Size() << std::endl;
	vector.Resize(3);
	std::cout << vector.Size() << std::endl;

	return 0;
}