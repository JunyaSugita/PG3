#include "stdio.h"
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

typedef int (*newType)(int num);

int Wait(newType pFunc, int second, int num) {
	//�^�C�}�[
	Sleep(second * 1000);

	pFunc(num);

	return 0;
}

int Output(int input) {
	if (input == 1) {
		printf("������I");
	}
	else {
		printf("�͂���...");
	}

	return 0;
}

int main() {
	//����
	srand(time(nullptr));
	//typedef�p
	newType pFunc;
	//�����_���ŏo���������̎󂯓n��
	int randNum = rand();
	//����̎󂯓n���p
	bool isHit = 0;

	//�v���C���[�̓���
	//�ϐ��錾
	int num = 0;

	//�v���C���[�Ɉē���\��
	printf("�������Ǝv���Ȃ�0���A����Ǝv���Ȃ�1�����\n");

	//���͂��󂯂�
	scanf_s("%d", &num);

	//���͂�\��
	printf("����-> %d\n", num);

	if (num == 0) {
		printf("���Ȃ��̓���-> ����\n");
	}
	else {
		printf("���Ȃ��̓���-> �\n");
	}

	if (randNum % 2 == num) {
		isHit = true;
	}
	else {
		isHit = false;
	}

	//3�b�҂��Č��ʂ��o��
	pFunc = &Output;
	Wait(pFunc, 3, isHit);

	return 0;
}