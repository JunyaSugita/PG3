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
		printf("[要素の操作]\n");
		printf("1.要素の表示\n");
		printf("2.要素の編集\n");
		printf("3.要素の追加\n");
		printf("4.要素の削除\n");
		scanf_s("%d", &menuNum);
		system("cls");
		switch (menuNum)
		{
		case 1:
			printf("[要素の表示]\n");
			printf("1.要素の一覧表示\n");
			printf("9.要素操作に戻る\n");

			scanf_s("%d", &menuNum);
			system("cls");

			switch (menuNum)
			{
			case 1:
				index(&head);
				printf("------------------------------\n");
				printf("要素数　: %d\n", CellNum(&head));

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
			printf("何番目のセルを変更するか\n");
			scanf_s("%d", &iterator);

			printf("文字を入力\n");
			scanf_s("%s", str, sizeof(head.str));



			system("cls");
			break;

		case 3:
			printf("何番目のセルの後ろに入力するか\n");
			scanf_s("%d", &iterator);

			printf("文字を入力\n");
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
//	printf("[要素の操作]\n");
//	printf("1.要素の表示\n");
//	printf("2.要素の編集\n");
//	printf("3.要素の追加\n");
//	printf("4.要素の削除\n");
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
//	printf("[要素の表示]\n");
//	printf("1.要素の一覧表示\n");
//	printf("9.要素操作に戻る\n");
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
//	printf("\n要素数 : %d \n\n");
//
//	printf("---------------\n");
//	printf("1.要素の表示に戻る\n");
//	printf("2.要素の操作に戻る\n");
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
//	printf("編集する場所(最後の場所は%d)\n");
//	int addNum;
//	scanf_s("%d", &addNum);
//
//
//	printf("変更するワード\n");
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
//	printf("入れる場所(最後の場所は%d)\n");
//	int addNum;
//	scanf_s("%d", &addNum);
//
//
//	printf("入れるワード\n");
//	char newWord[11];
//	scanf_s("%10s", newWord,11);
//
//	pFunc = &MainMenu;
//	system("cls");
//}
//
//void SubFactor()
//{
//	printf("消す場所(最後の場所は%d)\n");
//	int addNum;
//	scanf_s("%d", &addNum);
//
//	printf("消したワード\n");
//
//	pFunc = &MainMenu;
//	system("cls");
//}
