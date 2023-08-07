#pragma once
#include <iostream>

int main() {
#pragma region 계수 정렬
	// 데이터의 값을 직접 비교하지 않고, 단순하게 각 숫자가
	// 몇 개 있는지 갯수를 세어 저장한 다음 정렬하는 알고리즘입니다.

	int num[20] = { 1,2,3,4,7,5,4,5,7,8,4,2,5,7,5,9,3,3,3,2 };
	int sort[10] = {};
	
	for (int i = 1;i <= 10;i++) {
		int count = 0;
		for (int j = 0;j < 20;j++) {
			if (num[j] == i) {
				count++;
			}
		}
		sort[i - 1] = count;
	}

	for (int i = 0;i < 20;i++) {
		sort[num[i] - 1]++;
	}

	for (int i = 0;i < 10;i++) {
		std::cout << sort[i] << " ";
	}
#pragma endregion
	return 0;
}