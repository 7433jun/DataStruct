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
			std::cout << "�ش� Ű ����" << std::endl;
			return;
		}

		while (nextNode != nullptr) {
			if (nextNode->key == key) {
				// ù��° ����� Ű�� ã�� ���϶�
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

		std::cout << "�ش� Ű ����" << std::endl;
	}

	void Search(int key) {
		int hashIndex = HashFunction(key);

		Node* nextNode = bucket[hashIndex].head;

		if (nextNode == nullptr) {
			std::cout << "�ش� Ű ����" << std::endl;
			return;
		}

		while (nextNode != nullptr) {
			if (nextNode->key == key) {
				std::cout << "key : " << nextNode->key << " value : " << nextNode->value << std::endl;
				return;
			}

			nextNode = nextNode->next;
		}

		std::cout << "�ش� Ű ����" << std::endl;
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
#pragma region �� ����
	// �������� ȹ���� ���� �ش� �������� �������� �迭�� ������
	// �� �ʿ��� ���������� ���� �׸���� ��ġ�ϰ� �ٸ� �ʿ��� ���������� ū �׸���� ��ġ�Ѵ�.
	// �������� ���� �迭�� ���� ��������� �� ������ ȣ���Ͽ�,
	// ��� �迭�� �⺻ �迭(��Ұ� �ϳ����� �迭)�� �� ������ �ݺ��ϴ� �˰����Դϴ�.

	//int num[SIZE] = { 5,7,9,3,2,8,6,1,4,0 };
	//
	//QuickSort(num, 0, SIZE - 1);
	//
	//for (int i = 0;i < SIZE;i++) {
	//	std::cout << num[i] << " ";
	//}

#pragma endregion

#pragma region �ؽ� ���̺�
	// (Key, Value)�� �����͸� �����ϴ� �ڷᱸ�� �� �ϳ���
	// ������ �����͸� �˻��� �� �ִ� �ڷᱸ���Դϴ�.

	// �ؽ� ���̺��� ��� �ð� ���⵵�� O(1)�Դϴ�.

	// �ؽ� �浹�� �ذ��ϴ� ���

	// ü�̴� ���
	// �� �ؽ� ��Ŷ�� ���Ḯ��Ʈ�� �����ϴ� ����Դϴ�.
	// �ؽ� �浹 �߻� �� ������ �ؽ� ���� �ش��ϴ� �����͵���
	// ���Ḯ��Ʈ�� �����Ͽ� �����մϴ�.

	// ���� �ּҹ�
	// �浹 �߻� �� �� ���Ͽ� �����͸� �����ϴ� ����Դϴ�.
	// �� ��Ŷ�� ��� ������ ���� ���� ���� ����� �޶����ϴ�.

	// ���� Ž�� : �浹 �߻� �� �տ������� ���ʴ�� �� ��Ŷ��
	// ã�� ���� �����ϴ� ����Դϴ�.

	// ���� Ž�� : �浹 �߻� �� 2^, 2^3��ŭ ������ �� ��Ŷ�� ã��
	// ���� �����ϴ� ����Դϴ�.

	// ���� �ؽ� : �ؽ� ���� �ѹ� �� �ؼ� �Լ��� �־� �ٸ� �ؽð���
	// �����ϴ� ����Դϴ�.

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