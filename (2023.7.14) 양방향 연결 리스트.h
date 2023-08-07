#pragma once
#include <iostream>

template <typename T>
struct Node {
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T>
class DoubleLinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	DoubleLinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	void Push_Front(T _data) {
		Node<T>* newNode = new Node<T>;
		newNode->data = _data;
		newNode->next = nullptr;
		newNode->prev = nullptr;

		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}

	void Push_Back(T _data) {
		Node<T>* newNode = new Node<T>;
		newNode->data = _data;
		newNode->next = nullptr;
		newNode->prev = nullptr;

		if (tail == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}

	void Pop_Front() {
		if (tail == nullptr) {
			return;
		}
		else {
			Node<T>* dummy = head;
			head = head->next;
			head->prev = nullptr;
			delete dummy;
		}
	}

	void Pop_Back() {
		if (head == nullptr) {
			return;
		}
		else {
			Node<T>* dummy = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete dummy;
		}
	}

	~DoubleLinkedList() {
		Node<T>* curPtr = head;
		while (curPtr != nullptr) {
			Node<T>* nextPtr = curPtr->next;
			nextPtr->prev = nullptr;
			delete curPtr;
			curPtr = nextPtr;
		}
		head = nullptr;
		tail = nullptr;
		std::cout << "Á¦°Å" << std::endl;
	}
};

int main() {
	DoubleLinkedList<int> list;

}