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

//関数のプロトタイプ宣言
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
	//イテレーター
	int iterator;
	//アドレス取得用
	CELL* indsertCell;
	//入力用
	char str[128];
	//最初の要素を作成
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;
	//リストの操作用
	bool isLoop;
	int backNum;
	int menuNum = 0;

	//最初に要素を入れておく(3つ)
	indsertCell = getInsertListAddress(&head, 0);
	create(indsertCell, "banana");
	indsertCell = getInsertListAddress(&head, 1);
	create(indsertCell, "apple");
	indsertCell = getInsertListAddress(&head, 2);
	create(indsertCell, "orange");

	while (true) {
		//初期画面
		printf("[要素の操作]\n");
		printf("1.要素の表示\n");
		printf("2.要素の追加\n");
		if (CellNum(&head) != 0) {
			printf("3.要素の編集\n");
			printf("4.要素の削除\n");
		}
		printf("\n------------------------\n");
		printf("操作を選択してください\n");

		scanf_s("%d", &menuNum);
		system("cls");
		isLoop = true;
		switch (menuNum)
		{
		case 1:
			while (isLoop) {
				//要素の表示
				printf("[要素の表示]\n");
				printf("1.要素の一覧表示\n");
				printf("2.順番を指定して要素を表示\n");
				printf("9.要素操作に戻る\n");
				printf("\n操作を選択してください\n");

				scanf_s("%d", &menuNum);
				system("cls");

				switch (menuNum)
				{
				case 1:
					//要素の一覧表示
					printf("[要素の一覧表示]\n");
					printf("要素一覧:{\n");
					index(&head);
					printf("}\n\n");
					printf("要素数　: %d\n", CellNum(&head));
					printf("------------------------------\n");
					printf("1.要素の表示に戻る\n");
					printf("2.要素の操作に戻る\n");
					scanf_s("%d", &backNum);
					if (backNum == 2) {
						isLoop = false;
					}

					system("cls");
					break;

				case 2:
					//要素の指定
					printf("表示したい要素の順番を指定してください\n");
					scanf_s("%d", &iterator);

					printf("------------------------------\n");
					indexOne(&head, iterator);
					printf("------------------------------\n");
					printf("1.要素の表示に戻る\n");
					printf("2.要素の操作に戻る\n");
					scanf_s("%d", &backNum);
					if (backNum == 2) {
						//ループを抜けて初期画面に戻る
						isLoop = false;
					}
					system("cls");
					break;

				case 9:
					//ループを抜けて初期画面に戻る
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
			//要素の挿入
			printf("[リスト要素の挿入]\n");
			printf("要素を追加する場所を指定してください。(最後尾に入力する場合は%d以上を入力してください)\n",CellNum(&head));
			scanf_s("%d", &iterator);

			printf("追加する要素の値を入力してください\n");
			scanf_s("%s", str, sizeof(head.str));

			indsertCell = getInsertListAddress(&head, iterator);
			create(indsertCell, str);

			if (iterator > CellNum(&head)) {
				iterator = CellNum(&head) - 1;
			}
			printf("要素\"%s\"が%d番目に挿入されました\n", str, iterator);
			system("pause");
			system("cls");
			break;

		case 3:
			//要素の編集
			printf("[要素の編集]\n");
			printf("編集したい要素の番号を指定してください。\n");
			scanf_s("%d", &iterator);

			if (CellNum(&head) >= iterator) {
				printf("%d番目の要素の変更する値を入力してください。\n",iterator);
				scanf_s("%s", str, sizeof(head.str));

				indsertCell = getInsertListAddress(&head, iterator + 1);
				Chenge(indsertCell, str);

				printf("%d番目の要素の値が\"%s\"に変更されました。\n", iterator, str);
				system("pause");
			}
			else
			{
				printf("%d番目の要素は見つかりませんでした。\n", iterator);
				system("pause");
			}

			system("cls");
			break;

		case 4:
			//要素の削除
			printf("[要素の削除]\n");
			printf("何番目のセルを削除するか\n");
			scanf_s("%d", &iterator);

			if (CellNum(&head) > iterator + 1) {
				indsertCell = getInsertListAddress(&head, iterator + 1);
				printf("%d番目の要素\"%s\"を削除しました。\n", iterator, ReturnStr(indsertCell));
				indsertCell = getInsertListAddress(&head, iterator);
				Delete(indsertCell);
			}
			else if (CellNum(&head) == iterator + 1) {
				indsertCell = getInsertListAddress(&head, iterator + 1);
				printf("%d番目の要素\"%s\"を削除しました。\n", iterator, ReturnStr(indsertCell));
				indsertCell = getInsertListAddress(&head, iterator);
				DeleteChangeNull(indsertCell);
			}
			else {
				printf("%d番目の要素が見つかりませんでした。\n", iterator);
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


//プロトタイプ関数の中身
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