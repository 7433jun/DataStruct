#pragma once
#include <iostream>

#define SIZE 5

int main() {
#pragma region �ð� ���⵵
	// ��ǻ�� ���α׷��� �Է� ���� ���� ���� �ð���
	// ������踦 ��Ÿ���� ô���Դϴ�.

	// Big-O ǥ���
	// �Է°��� ��ȭ�� ���� ������ ������ ��,
	// ���� Ƚ���� ���� �ð��� �󸶸�ŭ �ɸ��� �� ��Ÿ���� ô���Դϴ�.

	// �־��� ��츦 ����ϹǷ�, ���α׷��� ����Ǵ�
	// �������� �ҿ�Ǵ� �־��� �ð����� ����� �� �ֱ� �����Դϴ�.

	// O(1) ��� �ð����⵵
	/*
	// �Է°��� �����ϴ��� �ð��� �þ�� �ʴ� �ð� ���⵵�Դϴ�.

	// ex �迭�� �ε��� ����
	// int buffer[100];
	// buffer[50] = 10;
	// std::cout << buffer[50] << std::endl;
	*/

	// O(n) ���� �ð� ���⵵
	/*
	�Է°��� �����Կ� ���� �ð� ���� ���� ������
	�����ϴ� �ð� ���⵵�Դϴ�.

	�Է� 1
	�ð� 1

	�Է� 100
	�ð� 100

	ex) for��
	*/

	// O(log n) �α� �ð� ���⵵
	/*
	�Է� �������� ũ�Ⱑ Ŀ������ ó�� �ð��� �α�(log) ��ŭ
	ª������ �ð� ���⵵
	*/

	// O(n^2) 2�� �ð����⵵
	/*
	�Է°��� �����Կ� ���� �ð��� n�� ��������
	������ �����ϴ� �ð� ���⵵

	ex) 2�� for��
	*/

	// O(2n) ���� �޼��� �ð� ���⵵
	/*
	ex) ��� �Լ� (�Ǻ���ġ ����)
	*/
#pragma endregion

#pragma region ��ǰ ����
	//���� ������ �� ���Ҹ� �˻��Ͽ� �����ϴ� �˰���
	//�ð� ���⵵ O(n^2)

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

#pragma region ���� ����
	// ���ĵ��� ���� �����͵鿡 ���� ����
	// ���� �����͸� ã�Ƽ� ���� �տ� �ִ� �����Ϳ� ��ȯ�ϴ�
	// �˰����Դϴ�.

	// �ð����⵵ O(n^2)

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