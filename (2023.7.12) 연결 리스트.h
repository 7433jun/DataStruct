#include <iostream>

struct Node {
	int num;
	Node* nextNode;
};

void AddNode(Node* target, int data) {
	Node* newNode = new Node;
	newNode->num = data;
	newNode->nextNode = target->nextNode;
	target->nextNode = newNode;
}

void ShowNode(Node* target) {
	Node* currentPtr = target;

	while (currentPtr != nullptr) {
		currentPtr = currentPtr->nextNode;
		if (currentPtr != nullptr) {
			std::cout << currentPtr->num << std::endl;
		}
	}
}

void RemoveNode(Node* target) {
	Node* removeNode = target->nextNode;
	target->nextNode = removeNode->nextNode;
	delete removeNode;
}

void ReleaseNode(Node* target) {
	Node* curPtr = target;
	while (curPtr != nullptr) {
		Node* nextPtr = curPtr->nextNode;
		delete curPtr;
		curPtr = nextPtr;
	}
}
