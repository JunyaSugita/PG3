#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

typedef void (*newType)();

typedef struct cell{
	char str[8];
	int val;
	struct cell* prev;
	struct cell* next;
}CELL;

void create(CELL *currentCell,int val);
void index(CELL *endCell);
CELL* getInsertListAddress(CELL *Cell,int ite);

string sellList[3] = {
		"apple",
		"banana",
		"pine"
};

int menuNum = 0;

void MainMenu();
void ListViewMenu();
void ListView();
void EditFactor();
void AddFactor();
void SubFactor();

newType pFunc = &MainMenu;

int main() {

	//int iterator;
	//int inputValue;
	//CELL* indsertCell;

	//CELL head;
	//head.next = nullptr;
	//head.prev = nullptr;

	while (1) {
		pFunc();

		//printf("何番目のセルの後ろに挿入するか\n");
		//scanf_s("%d", &iterator);

		//printf("挿入する値を入力してください\n");
		//scanf_s("%d", &inputValue);

		//indsertCell = getInsertListAddress(&head,iterator);
		//create(indsertCell, iterator);

		//index(&head);
	}

	return 0;
}

void create(CELL* currentCell, int val)
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next) {
		CELL* nextCell = currentCell->next;
		nextCell->next = newCell;
	}
	currentCell->next = newCell;
}

void index(CELL* endCell)
{
	int no = 1;
	while(endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d", no);
		printf("%p", endCell->prev);
		printf("%5d ", endCell->val);
		printf("(%p)", endCell);
		printf("%p\n", endCell->next);
		no++;
	}
}

CELL* getInsertListAddress(CELL* Cell, int ite)
{
	return nullptr;
}

void MainMenu()
{
	printf("[要素の操作]\n");
	printf("1.要素の表示\n");
	printf("2.要素の編集\n");
	printf("3.要素の追加\n");
	printf("4.要素の削除\n");
	int num;
	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		pFunc = &ListViewMenu;
		break;

	case 2:
		pFunc = &EditFactor;
		break;

	case 3:
		pFunc = &AddFactor;
		break;

	case 4:
		pFunc = &SubFactor;
		break;

	default:
		break;
	}
}

void ListViewMenu()
{
	printf("[要素の表示]\n");
	printf("1.要素の一覧表示\n");
	printf("9.要素操作に戻る\n");

	scanf_s("%d", &menuNum);

	switch (menuNum)
	{
	case 1:
		pFunc = &ListView;
		break;

	case 9:
		pFunc = &MainMenu;
		break;

	default:
		break;
	}
}

void ListView()
{
	printf("\n要素数 : %d \n\n");

	printf("---------------\n");
	printf("1.要素の表示に戻る\n");
	printf("2.要素の操作に戻る\n");
	scanf_s("%d", &menuNum);

	switch (menuNum)
	{
	case 1:
		pFunc = &ListViewMenu;
		break;

	case 2:
		pFunc = &MainMenu;
		break;

	default:
		break;
	}
}

void EditFactor()
{

	printf("編集する場所(最後の場所は%d)\n");
	int addNum;
	scanf_s("%d", &addNum);


	printf("変更するワード\n");
	char newWord[11];
	scanf_s("%10s", newWord, 11);

	pFunc = &MainMenu;

}

void AddFactor()
{

	printf("入れる場所(最後の場所は%d)\n");
	int addNum;
	scanf_s("%d", &addNum);


	printf("入れるワード\n");
	char newWord[11];
	scanf_s("%10s", newWord,11);

	pFunc = &MainMenu;

}

void SubFactor()
{
	printf("消す場所(最後の場所は%d)\n");
	int addNum;
	scanf_s("%d", &addNum);

	printf("消したワード\n");

	pFunc = &MainMenu;
}
