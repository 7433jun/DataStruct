#include <iostream>

#pragma region 원형 연결 리스트
// 단순 연결 리스트에서 마지막 노드가
// 리스트의 첫 번째 노드를 가리키는 리스트 구조를
// 원형으로 만든 리스트입니다.

struct Node {
	int data;
	Node* next;
};


class CircleLinkedList {
private:
	int count;

public:
	CircleLinkedList() : count(0) { };

	Node* CreateNode(int data) {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		return newNode;
	}

	Node* Push_Front(Node* head, int data) {
		if (head == nullptr) {
			head = CreateNode(data);
			head->next = head;
		}
		else {
			Node* temp = CreateNode(data);
			temp->next = head->next;
			head->next = temp;
		}
		count++;
		return head;
	}

	Node* Push_Back(Node* head, int data) {
		if (head == nullptr) {
			head = CreateNode(data);
			head->next = head;
		}
		else {
			Node* temp = CreateNode(data);
			temp->next = head->next;
			head->next = temp;

			head = temp;
		}
		count++;
		return head;
	}

	void Information(Node* head) {
		Node* temp = head->next;

		while (temp != head) {
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
		std::cout << temp->data << std::endl;
	}

	int Size() {
		return count;
	}
};

#pragma endregion

int main() {
	Node* head = nullptr;

	CircleLinkedList circleLinkedList;

	head = circleLinkedList.Push_Front(head, 20);
	head = circleLinkedList.Push_Front(head, 10);
	head = circleLinkedList.Push_Back(head, 30);
	
	circleLinkedList.Information(head);
	

	std::cout << circleLinkedList.Size() << std::endl;

	return 0;
}