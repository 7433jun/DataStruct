#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

std::vector<int> bfsGraph[6];
std::vector<int> dfsGraph[6];
bool bfsCheck[6];
bool dfsCheck[6];

#pragma region BFS (�ʺ� �켱 Ž��)
// ���� ��带 �湮�� �� ���� ��忡 �ִ�
// ������ ��� ������ Ž���ϴ� ����Դϴ�.
std::queue<int> queue;

void BFS(int start) {
	queue.push(start);
	bfsCheck[start] = true;

	while (!queue.empty()) {

		for (int& element : bfsGraph[queue.front()]) {
			if (bfsCheck[element] == false) {
				queue.push(element);
				bfsCheck[element] = true;
			}
		}

		std::cout << queue.front() << std::endl;
		queue.pop();
	}
}


// �� �̻� �湮���� ���� ��尡 ���� ������ �湮����
// ���� ��� ��忡 ���ؼ��� BSF�� �����մϴ�.
#pragma endregion

#pragma region DFS (���� �켱 Ž��)
// ���������� ���� ��η� �Ѿ�� ����
// �ش� ��θ� �Ϻ��ϰ� Ž���ϴ� �Ѿ�� ����Դϴ�.

void DFS(int start) {
	dfsCheck[start] = true;
	std::cout << start << " ";
	for (int& element : dfsGraph[start]) {
		if (dfsCheck[element] == false) {
			DFS(element);
		}
	}
}
#pragma endregion


int main() {
#pragma region BFS
	//bfsGraph[0].push_back(1);
	//bfsGraph[0].push_back(2);
	//
	//bfsGraph[1].push_back(0);
	//bfsGraph[1].push_back(3);
	//
	//bfsGraph[2].push_back(0);
	//bfsGraph[2].push_back(4);
	//bfsGraph[2].push_back(5);
	//
	//bfsGraph[3].push_back(1);
	//
	//bfsGraph[4].push_back(2);
	//
	//bfsGraph[5].push_back(2);
	//
	//BFS(0);
#pragma endregion

#pragma region DFS
	dfsGraph[0].push_back(1);
	dfsGraph[0].push_back(2);
	dfsGraph[0].push_back(3);

	dfsGraph[1].push_back(0);
	dfsGraph[1].push_back(4);

	dfsGraph[2].push_back(0);

	dfsGraph[3].push_back(0);
	dfsGraph[3].push_back(5);

	dfsGraph[4].push_back(1);

	dfsGraph[5].push_back(3);

	DFS(0);

#pragma endregion


	return 0;
}