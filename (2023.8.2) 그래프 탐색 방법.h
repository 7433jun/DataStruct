#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

std::vector<int> bfsGraph[6];
std::vector<int> dfsGraph[6];
bool bfsCheck[6];
bool dfsCheck[6];

#pragma region BFS (너비 우선 탐색)
// 시작 노드를 방문한 후 시작 노드에 있는
// 인접한 모든 노드들을 탐색하는 방법입니다.
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


// 더 이상 방문하지 않은 노드가 없을 때까지 방문하지
// 않은 모든 노드에 대해서도 BSF를 적용합니다.
#pragma endregion

#pragma region DFS (깊이 우선 탐색)
// 시작점부터 다음 경로로 넘어가기 전에
// 해당 경로를 완벽하게 탐색하는 넘어가는 방법입니다.

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