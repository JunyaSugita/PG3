#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

typedef void (*newType)();

struct CELL {
	char str[128];
	//struct CELL* prev = nullptr;
	struct CELL* next = nullptr;
};

void create(CELL *currentCell,const char* str);
void index(CELL *endCell);
CELL* getInsertListAddress(CELL *Cell,int ite);

string sellList[3] = {
		"apple",
		"banana",
		"pine"
};

int menuNum = 0;

//void MainMenu();
//void ListViewMenu();
//void ListView();
//void EditFactor();
//void AddFactor();
//void SubFactor();

//newType pFunc = &MainMenu;

int main() {

	//int iterator;
	//int inputValue;
	//CELL* indsertCell;
	char str[128];
	CELL head;
	head.next = nullptr;
	//head.prev = nullptr;

	while (true) {
		printf("���������\n");
		scanf_s("%s", str,sizeof(head.str));

		create(&head, str);

		index(&head);

		//pFunc();

		//printf("���Ԗڂ̃Z���̌��ɑ}�����邩\n");
		//scanf_s("%d", &iterator);

		//printf("�}������l����͂��Ă�������\n");
		//scanf_s("%d", &inputValue);

		//indsertCell = getInsertListAddress(&head,iterator);
		//create(indsertCell, iterator);

		//index(&head);
	}

	return 0;
}

void create(CELL* currentCell,const char* str)
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	strcpy_s(newCell->str, sizeof(newCell->str), str);
	//newCell->prev = currentCell;
	newCell->next = nullptr;

	while (currentCell->next != nullptr) {
		currentCell = currentCell->next;
	}
	//if (currentCell->next) {
	//	CELL* nextCell = currentCell->next;
	//	//nextCell->prev = newCell;
	//}
	currentCell->next = newCell;
}

void index(CELL* endCell)
{
	int no = 1;
	while(endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d :", no);
		//printf("%p", endCell->prev);
		printf("%s \n", endCell->str);
		//printf("(%p)", endCell);
		//printf("%p\n", endCell->next);
		no++;
	}
}

CELL* getInsertListAddress(CELL* Cell, int ite)
{
	//for (int i = 0; i < iterator; i++) {
	//	if (endCELL->next) {
	//		endCELL = endCELL->next;
	//	}
	//	else {
	//		break;
	//	}
	//}
	//return endCELL;
	return nullptr;
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
//		break;
//
//	case 2:
//		pFunc = &EditFactor;
//		break;
//
//	case 3:
//		pFunc = &AddFactor;
//		break;
//
//	case 4:
//		pFunc = &SubFactor;
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
//		break;
//
//	case 9:
//		pFunc = &MainMenu;
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
//		break;
//
//	case 2:
//		pFunc = &MainMenu;
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
//
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
//
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
//}
