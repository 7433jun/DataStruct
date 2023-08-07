#pragma once
#include <iostream>

struct Node {
	int data;
	Node* next;
};

class LinkedList {
private:
	Node* head;
	Node* tail;

	int size;

public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;

		size = 0;
	}

	void Push_Front(int _data) {
		Node* newNode = new Node;
		newNode->data = _data;
		newNode->next = nullptr;

		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}

		size++;
	}

	void Push_Back(int _data) {
		Node* newNode = new Node;
		newNode->data = _data;
		newNode->next = nullptr;

		if (tail == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}

		size++;
	}

	void Insert(Node* prevNode, int _data) {
		//Node* newNode = new Node;
		//newNode->data = _data;
		//newNode->next = prevNode->next;
		//prevNode->next = newNode;
		//
		//size++;
	}

	int Size() {
		return size;
	}

	~LinkedList() {
		Node* curPtr = head;
		while (curPtr != nullptr) {
			Node* nextPtr = curPtr->next;
			delete curPtr;
			curPtr = nextPtr;
		}

		std::cout << "Á¦°Å" << std::endl;
	}

};

int main() {
	LinkedList list;

	list.Push_Front(10);
	list.Push_Back(20);

	std::cout << list.Size() << std::endl;
}