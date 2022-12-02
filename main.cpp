#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

struct CELL {
	char str[128];
	struct CELL* prev = nullptr;
	struct CELL* next = nullptr;
};

//�֐��̃v���g�^�C�v�錾
void create(CELL* currentCell, const char* str);
void Chenge(CELL* currentCell, const char* str);
void Delete(CELL* currentCell);
void DeleteChangeNull(CELL* currentCell);
void index(CELL* endCell);
void indexOne(CELL* endCell, int ite);
const char* ReturnStr(CELL* endCell);
CELL* getInsertListAddress(CELL* Cell, int ite);
int CellNum(CELL* endCell);

int main() {
	//�C�e���[�^�[
	int iterator;
	//�A�h���X�擾�p
	CELL* indsertCell;
	//���͗p
	char str[128];
	//�ŏ��̗v�f���쐬
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;
	//���X�g�̑���p
	bool isLoop;
	int backNum;
	int menuNum = 0;

	//�ŏ��ɗv�f�����Ă���(3��)
	indsertCell = getInsertListAddress(&head, 0);
	create(indsertCell, "banana");
	indsertCell = getInsertListAddress(&head, 1);
	create(indsertCell, "apple");
	indsertCell = getInsertListAddress(&head, 2);
	create(indsertCell, "orange");

	while (true) {
		//�������
		printf("[�v�f�̑���]\n");
		printf("1.�v�f�̕\��\n");
		printf("2.�v�f�̒ǉ�\n");
		if (CellNum(&head) != 0) {
			printf("3.�v�f�̕ҏW\n");
			printf("4.�v�f�̍폜\n");
		}
		printf("\n------------------------\n");
		printf("�����I�����Ă�������\n");

		scanf_s("%d", &menuNum);
		system("cls");
		isLoop = true;
		switch (menuNum)
		{
		case 1:
			while (isLoop) {
				//�v�f�̕\��
				printf("[�v�f�̕\��]\n");
				printf("1.�v�f�̈ꗗ�\��\n");
				printf("2.���Ԃ��w�肵�ėv�f��\��\n");
				printf("9.�v�f����ɖ߂�\n");
				printf("\n�����I�����Ă�������\n");

				scanf_s("%d", &menuNum);
				system("cls");

				switch (menuNum)
				{
				case 1:
					//�v�f�̈ꗗ�\��
					printf("[�v�f�̈ꗗ�\��]\n");
					printf("�v�f�ꗗ:{\n");
					index(&head);
					printf("}\n\n");
					printf("�v�f���@: %d\n", CellNum(&head));
					printf("------------------------------\n");
					printf("1.�v�f�̕\���ɖ߂�\n");
					printf("2.�v�f�̑���ɖ߂�\n");
					scanf_s("%d", &backNum);
					if (backNum == 2) {
						isLoop = false;
					}

					system("cls");
					break;

				case 2:
					//�v�f�̎w��
					printf("�\���������v�f�̏��Ԃ��w�肵�Ă�������\n");
					scanf_s("%d", &iterator);

					printf("------------------------------\n");
					indexOne(&head, iterator);
					printf("------------------------------\n");
					printf("1.�v�f�̕\���ɖ߂�\n");
					printf("2.�v�f�̑���ɖ߂�\n");
					scanf_s("%d", &backNum);
					if (backNum == 2) {
						//���[�v�𔲂��ď�����ʂɖ߂�
						isLoop = false;
					}
					system("cls");
					break;

				case 9:
					//���[�v�𔲂��ď�����ʂɖ߂�
					system("cls");
					isLoop = false;
					break;

				default:
					system("cls");
					break;
				}


			}
			break;
		case 2:
			//�v�f�̑}��
			printf("[���X�g�v�f�̑}��]\n");
			printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B(�Ō���ɓ��͂���ꍇ��%d�ȏ����͂��Ă�������)\n",CellNum(&head));
			scanf_s("%d", &iterator);

			printf("�ǉ�����v�f�̒l����͂��Ă�������\n");
			scanf_s("%s", str, sizeof(head.str));

			indsertCell = getInsertListAddress(&head, iterator);
			create(indsertCell, str);

			if (iterator > CellNum(&head)) {
				iterator = CellNum(&head) - 1;
			}
			printf("�v�f\"%s\"��%d�Ԗڂɑ}������܂���\n", str, iterator);
			system("pause");
			system("cls");
			break;

		case 3:
			//�v�f�̕ҏW
			printf("[�v�f�̕ҏW]\n");
			printf("�ҏW�������v�f�̔ԍ����w�肵�Ă��������B\n");
			scanf_s("%d", &iterator);

			if (CellNum(&head) >= iterator) {
				printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B\n",iterator);
				scanf_s("%s", str, sizeof(head.str));

				indsertCell = getInsertListAddress(&head, iterator + 1);
				Chenge(indsertCell, str);

				printf("%d�Ԗڂ̗v�f�̒l��\"%s\"�ɕύX����܂����B\n", iterator, str);
				system("pause");
			}
			else
			{
				printf("%d�Ԗڂ̗v�f�͌�����܂���ł����B\n", iterator);
				system("pause");
			}

			system("cls");
			break;

		case 4:
			//�v�f�̍폜
			printf("[�v�f�̍폜]\n");
			printf("���Ԗڂ̃Z�����폜���邩\n");
			scanf_s("%d", &iterator);

			if (CellNum(&head) > iterator + 1) {
				indsertCell = getInsertListAddress(&head, iterator + 1);
				printf("%d�Ԗڂ̗v�f\"%s\"���폜���܂����B\n", iterator, ReturnStr(indsertCell));
				indsertCell = getInsertListAddress(&head, iterator);
				Delete(indsertCell);
			}
			else if (CellNum(&head) == iterator + 1) {
				indsertCell = getInsertListAddress(&head, iterator + 1);
				printf("%d�Ԗڂ̗v�f\"%s\"���폜���܂����B\n", iterator, ReturnStr(indsertCell));
				indsertCell = getInsertListAddress(&head, iterator);
				DeleteChangeNull(indsertCell);
			}
			else {
				printf("%d�Ԗڂ̗v�f��������܂���ł����B\n", iterator);
			}


			system("pause");


			system("cls");
			break;

		default:
			break;
		}
	}

	system("pause");
	return 0;
}


//�v���g�^�C�v�֐��̒��g
void create(CELL* currentCell, const char* str)
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	strcpy_s(newCell->str, sizeof(newCell->str), str);
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}
	currentCell->next = newCell;
}

void Chenge(CELL* currentCell, const char* str)
{
	strcpy_s(currentCell->str, sizeof(currentCell->str), str);
}

void Delete(CELL* currentCell)
{
	currentCell->next = currentCell->next->next;
	currentCell->next->prev = currentCell;
}

void DeleteChangeNull(CELL* currentCell)
{
	currentCell->next = nullptr;
}

void index(CELL* endCell)
{
	int no = 0;
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d : ", no);
		printf("%s\n", endCell->str);
		no++;
	}
}

void indexOne(CELL* endCell, int ite)
{
	int no = 0;
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		if (ite == no) {
			printf("%d : ", no);
			printf("%s\n", endCell->str);
			break;
		}
		no++;
	}
}

const char* ReturnStr(CELL* endCell)
{
	return endCell->str;
}

CELL* getInsertListAddress(CELL* Cell, int ite)
{
	for (int i = 0; i < ite; i++) {
		if (Cell->next) {
			Cell = Cell->next;
		}
		else {
			break;
		}
	}
	return Cell;
}

int CellNum(CELL* endCell) {
	int num = 0;
	while (endCell->next != nullptr) {
		num++;
		endCell = endCell->next;
	}
	return num;
}