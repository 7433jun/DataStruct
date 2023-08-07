#pragma once
#include <iostream>
#include <vector>

#pragma region 그래프
// 정점과 간선으로 이루어진 자료구조입니다.

// 정점(Vertex) : 노드를 의미하며, 각 노드에는 데이터가 저장됩니다.
// 간선(Edge) : 링크라고 하며, 노드간의 관계를 나타냅니다.
// 차수(Degree) : 무방향 그래프에서 하나의 정점에 인접한 정점의 수
// 진출 차수(out-degree) : 방향 그래프에서 사용되며, 한 노드에서 외부로 향하는 간선의 수
// 집입 차수(in-degree) : 방향 그래프에서 사용되며, 외부 노드에서 들어오는 간선의 수
#pragma endregion

int main() {

#pragma region 인접 행렬
	// 그래프의 연결 관계를 이차원 배열로 나타내는 방식입니다.

	//int buffer[4][4] = {};
	//int vertex = 0;
	//int edge = 0;
	//std::cin >> vertex >> edge;
	//
	//for (int i = 0;i < edge;i++) {
	//	int x, y;
	//	std::cin >> x >> y;
	//	buffer[x][y] = 1;
	//	buffer[y][x] = 1;
	//}
	//
	//for (int i = 0;i < 4;i++) {
	//	for (int j = 0;j < 4;j++) {
	//		std::cout << buffer[i][j];
	//	}
	//	std::cout << std::endl;
	//}

#pragma endregion

#pragma region 인접 리스트
	// 그래프의 연결 관계를 vector의 배열(vector<int> data[])로 나타내는 배열입니다.

	int node = 0;
	int edge = 0;

	std::vector<int> data[4];

	std::cin >> node >> edge;

	for (int i = 0;i < edge;i++) {
		int edgeNode;
		std::cin >> node >> edgeNode;
		data[node].push_back(edgeNode);
	}

	for (int i = 0;i < edge;i++) {
		std::cout << i << '-';
		for (auto& element : data[i]) {
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}

#pragma endregion



	return 0;
}