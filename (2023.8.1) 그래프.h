#pragma once
#include <iostream>
#include <vector>

#pragma region �׷���
// ������ �������� �̷���� �ڷᱸ���Դϴ�.

// ����(Vertex) : ��带 �ǹ��ϸ�, �� ��忡�� �����Ͱ� ����˴ϴ�.
// ����(Edge) : ��ũ��� �ϸ�, ��尣�� ���踦 ��Ÿ���ϴ�.
// ����(Degree) : ������ �׷������� �ϳ��� ������ ������ ������ ��
// ���� ����(out-degree) : ���� �׷������� ���Ǹ�, �� ��忡�� �ܺη� ���ϴ� ������ ��
// ���� ����(in-degree) : ���� �׷������� ���Ǹ�, �ܺ� ��忡�� ������ ������ ��
#pragma endregion

int main() {

#pragma region ���� ���
	// �׷����� ���� ���踦 ������ �迭�� ��Ÿ���� ����Դϴ�.

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

#pragma region ���� ����Ʈ
	// �׷����� ���� ���踦 vector�� �迭(vector<int> data[])�� ��Ÿ���� �迭�Դϴ�.

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