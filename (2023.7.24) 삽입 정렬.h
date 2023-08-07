#pragma once
#include <iostream>

#define SIZE 5

class Component {
private:
	float x;
	float y;
	int* count = new int;

public:
	// 기본 생성자
	Component() {
		x = 10;
		y = 20;
	}

	// 복사 생성자
	Component(Component& _Component) noexcept
	{
		std::cout << "복사 생성자" << std::endl;
		x = _Component.x;
		y = _Component.y;
		_Component.count = new int;
		*_Component.count = *(this->count);
	}

	// 이동 생성자
	Component(Component&& _Component) noexcept
	{
		std::cout << "이동 생성자" << std::endl;
		x = _Component.x;
		y = _Component.y;
		count = _Component.count;
		_Component.count = nullptr;
	}
};

int main() {
#pragma region 삽입 정렬
	// 두 번쨰 자료부터 시작하여 그 앞(왼쪽)의
	// 자료들과 비교하여 삽입할 위치를 지정한 후
	// 자료를 뒤로 옮기고 지정한 자리에 자료를 삽입하여
	// 정렬하는 알고리즘입니다.

	// 시간복잡도 O(n^2)

	// int array[SIZE] = { 4,7,2,8,5 };
	// 
	// for (int i = 1; i < SIZE; i++) {
	// 	int temp = array[i];
	// 
	// 	for (int j = i - 1; j >= -1; j--) {
	// 		if (j < 0) {
	// 			array[0] = temp;
	// 		}
	// 		else if (array[j] < temp) {
	// 			array[j + 1] = temp;
	// 			break;
	// 		}
	// 		else {
	// 			array[j + 1] = array[j];
	// 		}
	// 	}
	// }
	// 
	// for (int i = 0;i < SIZE;i++) {
	// 	std::cout << array[i];
	// }
#pragma endregion

#pragma region 이동 생성자
	// 기존 객체의 주소 및 값을 새로운 오브젝트에
	// 소유권을 이전시키는 생성자입니다.

	// Component component1;
	// 
	// Component component2 = component1;
	// 
	// Component component3 = std::move(component1);

#pragma endregion


	return 0;
}