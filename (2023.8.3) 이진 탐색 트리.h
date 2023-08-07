#pragma once
#include <iostream>

#pragma region 이진 탐색 트리 (BST)
// 임의의 키를 가진 원소를 삽입, 삭제, 검색하는데
// 효율적인 트리입니다.

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

Node* Insert(Node* root, int data) {
	if (root == nullptr) {
		root = CreateNode(data);
	}
	else if (data < root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

int FindMax(Node* root) {
	if (root == nullptr) {

		return NULL;
	}
	while (root->right != nullptr) {
		root = root->right;
	}
	return root->data;
}

int FindMin(Node* root) {
	if (root == nullptr) {

		return NULL;
	}
	while (root->left != nullptr) {
		root = root->left;
	}
	return root->data;
}
Node* temp;
Node* DeleteNode(Node* root, int key) {
	if (root == nullptr) {
		std::cout << "값 없음" << std::endl;
	}
	else if (key == root->data) {
		if (root->left == nullptr && root->right == nullptr) {
			delete root;
		}
		else if (root->left == nullptr) {
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr) {
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else {
			Node* temp = root->right;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			root->data = temp->data;
			DeleteNode(temp, temp->data);
		}
	}
	else if (key < root->data) {
		root = DeleteNode(root->left, key);
		temp = root;
	}
	else {
		root = DeleteNode(root->right, key);
		temp = root;
	}
	return root;
}

#pragma endregion

int main() {
	Node* root = nullptr;

	root = Insert(root, 10);
	root = Insert(root, 5);
	root = Insert(root, 15);
	root = Insert(root, 1);
	root = Insert(root, 20);

	std::cout << FindMax(root) << std::endl;
	std::cout << FindMin(root) << std::endl;
	root = DeleteNode(root, 20);
	std::cout << FindMax(root) << std::endl;
	std::cout << FindMin(root) << std::endl;
	return 0;
}