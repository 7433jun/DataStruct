#pragma once
#include <iostream>

#define SIZE 5

class Component {
private:
	float x;
	float y;
	int* count = new int;

public:
	// �⺻ ������
	Component() {
		x = 10;
		y = 20;
	}

	// ���� ������
	Component(Component& _Component) noexcept
	{
		std::cout << "���� ������" << std::endl;
		x = _Component.x;
		y = _Component.y;
		_Component.count = new int;
		*_Component.count = *(this->count);
	}

	// �̵� ������
	Component(Component&& _Component) noexcept
	{
		std::cout << "�̵� ������" << std::endl;
		x = _Component.x;
		y = _Component.y;
		count = _Component.count;
		_Component.count = nullptr;
	}
};

int main() {
#pragma region ���� ����
	// �� ���� �ڷ���� �����Ͽ� �� ��(����)��
	// �ڷ��� ���Ͽ� ������ ��ġ�� ������ ��
	// �ڷḦ �ڷ� �ű�� ������ �ڸ��� �ڷḦ �����Ͽ�
	// �����ϴ� �˰����Դϴ�.

	// �ð����⵵ O(n^2)

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

#pragma region �̵� ������
	// ���� ��ü�� �ּ� �� ���� ���ο� ������Ʈ��
	// �������� ������Ű�� �������Դϴ�.

	// Component component1;
	// 
	// Component component2 = component1;
	// 
	// Component component3 = std::move(component1);

#pragma endregion


	return 0;
}