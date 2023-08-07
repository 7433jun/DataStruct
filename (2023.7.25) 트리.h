#pragma once
#include <iostream>

#pragma region 트리
// 그래프의 일종으로 정점과 간선을
// 이용하여 데이터의 배치 형태를 추상화한 자료구조입니다.
#pragma endregion

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int _data, Node* _left, Node* _right) {
	Node* newNode = new Node;
	newNode->data = _data;
	newNode->left = _left;
	newNode->right = _right;
	return newNode;
}

void Preorder(Node* root) {
	std::cout << root->data;

	if (root->left != nullptr) {
		Preorder(root->left);
	}

	if (root->right != nullptr) {
		Preorder(root->right);
	}
}

void Inorder(Node* root) {
	if (root->left != nullptr) {
		Inorder(root->left);
	}

	std::cout << root->data;

	if (root->right != nullptr) {
		Inorder(root->right);
	}
}

void Postorder(Node* root) {
	if (root->left != nullptr) {
		Postorder(root->left);
	}

	if (root->right != nullptr) {
		Postorder(root->right);
	}

	std::cout << root->data;
}

int main() {
	Node* node7 = CreateNode(7, nullptr, nullptr);
	Node* node6 = CreateNode(6, nullptr, nullptr);
	Node* node5 = CreateNode(5, nullptr, nullptr);
	Node* node4 = CreateNode(4, nullptr, nullptr);
	Node* node3 = CreateNode(3, node6, node7);
	Node* node2 = CreateNode(2, node4, node5);
	Node* node1 = CreateNode(1, node2, node3);

	Preorder(node1);
	std::cout << std::endl << std::endl;
	Inorder(node1);
	std::cout << std::endl << std::endl;
	Postorder(node1);


	return 0;
}