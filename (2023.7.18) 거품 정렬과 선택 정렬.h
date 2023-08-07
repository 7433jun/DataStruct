#pragma once
#include <iostream>

#define SIZE 5

int main() {
#pragma region 시간 복잡도
	// 컴퓨터 프로그램의 입력 값과 연산 수행 시간의
	// 상관관계를 나타내는 척도입니다.

	// Big-O 표기법
	// 입력값의 변화에 따라 연산을 수행할 때,
	// 연산 횟수에 비해 시간이 얼마만큼 걸리는 지 나타내는 척도입니다.

	// 최악의 경우를 고려하므로, 프로그램이 실행되는
	// 과정에서 소요되는 최악의 시간까지 고려할 수 있기 때문입니다.

	// O(1) 상수 시간복잡도
	/*
	// 입력값이 증가하더라도 시간이 늘어나지 않는 시간 복잡도입니다.

	// ex 배열의 인덱스 접근
	// int buffer[100];
	// buffer[50] = 10;
	// std::cout << buffer[50] << std::endl;
	*/

	// O(n) 선형 시간 복잡도
	/*
	입력값이 증가함에 따라 시간 또한 같은 비율로
	증가하는 시간 복잡도입니다.

	입력 1
	시간 1

	입력 100
	시간 100

	ex) for문
	*/

	// O(log n) 로그 시간 복잡도
	/*
	입력 데이터의 크기가 커질수록 처리 시간이 로그(log) 만큼
	짧아지는 시간 복잡도
	*/

	// O(n^2) 2차 시간복잡도
	/*
	입력값이 증가함에 따라 시간이 n의 제곱수의
	비율로 증가하는 시간 복잡도

	ex) 2중 for문
	*/

	// O(2n) 기하 급수적 시간 복잡도
	/*
	ex) 재귀 함수 (피보나치 수열)
	*/
#pragma endregion

#pragma region 거품 정렬
	//서로 인접한 두 원소를 검사하여 정렬하는 알고리즘
	//시간 복잡도 O(n^2)

	// int sortBuffer[SIZE] = { 5,7,2,8,6 };
	// for (int i = SIZE - 1;i > 0;i--) {
	// 	for (int j = 0;j < i;j++) {
	// 		if (sortBuffer[j] > sortBuffer[j + 1]) {
	// 			std::swap(sortBuffer[j], sortBuffer[j + 1]);
	// 		}
	// 	}
	// }
	// 
	// for (int i = 0;i < SIZE;i++) {
	// 	std::cout << sortBuffer[i] << " ";
	// }
#pragma endregion

#pragma region 선택 정렬
	// 정렬되지 않은 데이터들에 대해 가장
	// 작은 데이터를 찾아서 가장 앞에 있는 데이터와 교환하는
	// 알고리즘입니다.

	// 시간복잡도 O(n^2)

	int selectBuffer[SIZE] = { 6,43,7,8,5 };
	for (int i = 0;i < SIZE - 1;i++) {
		int select;
		for (int j = i + 1;j < SIZE;j++) {
			int min = selectBuffer[i];
			select = i;
			if (selectBuffer[j] < min) {
				min = selectBuffer[j];
				select = j;
			}
		}
		if (select != i) {
			std::swap(selectBuffer[select], selectBuffer[i]);
		}
	}

	for (auto& element : selectBuffer) {
		std::cout << element << " ";
	}

#pragma endregion


	return 0;
}