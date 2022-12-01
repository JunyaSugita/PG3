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

void create(CELL* currentCell, const char* str);
void Chenge(CELL* currentCell, const char* str);
void index(CELL* endCell);
CELL* getInsertListAddress(CELL* Cell, int ite);
int CellNum(CELL* endCell);

int menuNum = 0;

int main() {

	int iterator;
	int inputValue;
	CELL* indsertCell;

	char str[128];
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (true) {
		printf("[�v�f�̑���]\n");
		printf("1.�v�f�̕\��\n");
		printf("2.�v�f�̕ҏW\n");
		printf("3.�v�f�̒ǉ�\n");
		printf("4.�v�f�̍폜\n");
		scanf_s("%d", &menuNum);
		system("cls");
		switch (menuNum)
		{
		case 1:
			printf("[�v�f�̕\��]\n");
			printf("1.�v�f�̈ꗗ�\��\n");
			printf("9.�v�f����ɖ߂�\n");

			scanf_s("%d", &menuNum);
			system("cls");

			switch (menuNum)
			{
			case 1:
				index(&head);
				printf("------------------------------\n");
				printf("�v�f���@: %d\n", CellNum(&head));

				system("pause");
				system("cls");
				break;

			case 9:
				system("cls");
				break;

			default:
				break;
			}
			break;

		case 2:
			printf("���Ԗڂ̃Z����ύX���邩\n");
			scanf_s("%d", &iterator);

			printf("���������\n");
			scanf_s("%s", str, sizeof(head.str));



			system("cls");
			break;

		case 3:
			printf("���Ԗڂ̃Z���̌��ɓ��͂��邩\n");
			scanf_s("%d", &iterator);

			printf("���������\n");
			scanf_s("%s", str, sizeof(head.str));

			indsertCell = getInsertListAddress(&head, iterator);
			create(indsertCell, str);

			index(&head);
			system("cls");
			break;

		case 4:

			system("cls");
			break;

		default:
			break;
		}
	}

	return 0;
}

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

void index(CELL* endCell)
{
	int no = 1;
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d : ", no);
		printf("%s\n", endCell->str);
		no++;
	}
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
	}
	return num;
}

//void MainMenu()
//{
//	printf("[�v�f�̑���]\n");
//	printf("1.�v�f�̕\��\n");
//	printf("2.�v�f�̕ҏW\n");
//	printf("3.�v�f�̒ǉ�\n");
//	printf("4.�v�f�̍폜\n");
//	int num;
//	scanf_s("%d", &num);
//
//	switch (num)
//	{
//	case 1:
//		pFunc = &ListViewMenu;
//		system("cls");
//		break;
//
//	case 2:
//		pFunc = &EditFactor;
//		system("cls");
//		break;
//
//	case 3:
//		pFunc = &AddFactor;
//		system("cls");
//		break;
//
//	case 4:
//		pFunc = &SubFactor;
//		system("cls");
//		break;
//
//	default:
//		break;
//	}
//}
//
//void ListViewMenu()
//{
//	printf("[�v�f�̕\��]\n");
//	printf("1.�v�f�̈ꗗ�\��\n");
//	printf("9.�v�f����ɖ߂�\n");
//
//	scanf_s("%d", &menuNum);
//
//	switch (menuNum)
//	{
//	case 1:
//		pFunc = &ListView;
//		system("cls");
//		break;
//
//	case 9:
//		pFunc = &MainMenu;
//		system("cls");
//		break;
//
//	default:
//		break;
//	}
//}
//
//void ListView()
//{
//	printf("\n�v�f�� : %d \n\n");
//
//	printf("---------------\n");
//	printf("1.�v�f�̕\���ɖ߂�\n");
//	printf("2.�v�f�̑���ɖ߂�\n");
//	scanf_s("%d", &menuNum);
//
//	switch (menuNum)
//	{
//	case 1:
//		pFunc = &ListViewMenu;
//		system("cls");
//		break;
//
//	case 2:
//		pFunc = &MainMenu;
//		system("cls");
//		break;
//
//	default:
//		break;
//	}
//}
//
//void EditFactor()
//{
//
//	printf("�ҏW����ꏊ(�Ō�̏ꏊ��%d)\n");
//	int addNum;
//	scanf_s("%d", &addNum);
//
//
//	printf("�ύX���郏�[�h\n");
//	char newWord[11];
//	scanf_s("%10s", newWord, 11);
//
//	pFunc = &MainMenu;
//	system("cls");
//}
//
//void AddFactor()
//{
//
//	printf("�����ꏊ(�Ō�̏ꏊ��%d)\n");
//	int addNum;
//	scanf_s("%d", &addNum);
//
//
//	printf("����郏�[�h\n");
//	char newWord[11];
//	scanf_s("%10s", newWord,11);
//
//	pFunc = &MainMenu;
//	system("cls");
//}
//
//void SubFactor()
//{
//	printf("�����ꏊ(�Ō�̏ꏊ��%d)\n");
//	int addNum;
//	scanf_s("%d", &addNum);
//
//	printf("���������[�h\n");
//
//	pFunc = &MainMenu;
//	system("cls");
//}
