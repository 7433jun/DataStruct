#pragma once
#include <iostream>

#define SIZE 10

void QuickSort(int data[], int start, int end) {
	if (start >= end) {
		return;
	}

	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right) {
		if (data[left] < data[pivot]) {
			left++;
			continue;
		}
		if (data[right] > data[pivot]) {
			right--;
			continue;
		}
		std::swap(data[left], data[right]);
	}
	std::swap(data[pivot], data[right]);

	QuickSort(data, pivot, right - 1);
	QuickSort(data, right + 1, end);
}

struct Node {
	int key;
	int value;
	Node* next;
};

struct Bucket {
	Node* head;
	int count;
};

class HashTable {
private:
	Bucket bucket[5];

public:
	HashTable() {
		for (int i = 0;i < 5;i++) {
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	Node* CreateNode(int key, int value) {
		Node* newNode = new Node;
		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;
		return newNode;
	}

	int HashFunction(int key) {
		return key % 5;
	}

	void Insert(int key, int value) {
		int hashIndex = HashFunction(key);
		Node* newNode = CreateNode(key, value);

		if (bucket[hashIndex].count == 0) {
			bucket[hashIndex].head = newNode;
			bucket[hashIndex].count++;
		}
		else {
			newNode->next = bucket[hashIndex].head;
			bucket[hashIndex].head = newNode;
			bucket[hashIndex].count++;
		}
	}

	void Remove(int key) {
		int hashIndex = HashFunction(key);

		Node* nextNode = bucket[hashIndex].head;
		Node* tempNode = nullptr;

		if (nextNode == nullptr) {
			std::cout << "해당 키 없음" << std::endl;
			return;
		}

		while (nextNode != nullptr) {
			if (nextNode->key == key) {
				// 첫번째 노드의 키가 찾는 값일때
				if (nextNode == bucket[hashIndex].head) {
					bucket[hashIndex].head = nextNode->next;
				}
				else {
					tempNode->next = nextNode->next;
				}
				bucket[hashIndex].count--;
				delete nextNode;
				return;
			}

			tempNode = nextNode;
			nextNode = nextNode->next;
		}

		std::cout << "해당 키 없음" << std::endl;
	}

	void Search(int key) {
		int hashIndex = HashFunction(key);

		Node* nextNode = bucket[hashIndex].head;

		if (nextNode == nullptr) {
			std::cout << "해당 키 없음" << std::endl;
			return;
		}

		while (nextNode != nullptr) {
			if (nextNode->key == key) {
				std::cout << "key : " << nextNode->key << " value : " << nextNode->value << std::endl;
				return;
			}

			nextNode = nextNode->next;
		}

		std::cout << "해당 키 없음" << std::endl;
	}

	void Show() {
		for (int i = 0;i < 5;i++) {
			Node* currentNode = bucket[i].head;

			if (currentNode == nullptr) {
				std::cout << std::endl;
				continue;
			}

			while (currentNode) {
				std::cout << currentNode->key << ", " << currentNode->value << " / ";
				currentNode = currentNode->next;
			}
			std::cout << std::endl;
		}
	}
};

int main() {
#pragma region 퀵 정렬
	// 기준점을 획득한 다음 해당 기준점을 기준으로 배열을 나누고
	// 한 쪽에는 기준점보다 작은 항목들이 위치하고 다른 쪽에는 기준점보다 큰 항목들이 위치한다.
	// 나뉘어진 하위 배열에 대해 재귀적으로 퀵 정렬을 호출하여,
	// 모든 배열이 기본 배열(요소가 하나뿐인 배열)이 될 때까지 반복하는 알고리즘입니다.

	//int num[SIZE] = { 5,7,9,3,2,8,6,1,4,0 };
	//
	//QuickSort(num, 0, SIZE - 1);
	//
	//for (int i = 0;i < SIZE;i++) {
	//	std::cout << num[i] << " ";
	//}

#pragma endregion

#pragma region 해시 테이블
	// (Key, Value)로 데이터를 저장하는 자료구조 중 하나로
	// 빠르게 데이터를 검색할 수 있는 자료구조입니다.

	// 해시 테이블의 평균 시간 복잡도는 O(1)입니다.

	// 해시 충돌을 해결하는 방법

	// 체이닝 기법
	// 각 해시 버킷을 연결리스트로 구성하는 방식입니다.
	// 해시 충돌 발생 시 동일한 해시 값에 해당하는 데이터들을
	// 연결리스트로 연결하여 저장합니다.

	// 개방 주소법
	// 충돌 발생 시 빈 버켓에 데이터를 저장하는 방식입니다.
	// 빈 버킷을 어떻게 결정할 지에 따라 구현 방식이 달라집니다.

	// 선형 탐사 : 충돌 발생 시 앞에서부터 차례대로 빈 버킷을
	// 찾아 값을 저장하는 방식입니다.

	// 이차 탐사 : 충돌 발생 시 2^, 2^3만큼 떨어진 빈 버킷을 찾아
	// 값을 저장하는 방식입니다.

	// 이중 해싱 : 해시 값을 한번 더 해서 함수에 넣어 다른 해시값을
	// 도출하는 방식입니다.

	HashTable hashtable;

	hashtable.Insert(5, 10);
	hashtable.Insert(10, 15);
	hashtable.Insert(15, 20);
	hashtable.Insert(20, 25);
	hashtable.Insert(25, 30);
	hashtable.Insert(1, 1);
	hashtable.Insert(3, 3);
	hashtable.Insert(2, 2);
	hashtable.Insert(4, 4);

	hashtable.Remove(15);

	hashtable.Show();

#pragma endregion


	return 0;
}