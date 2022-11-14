#include "stdio.h"
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

typedef int (*newType)(int num);

int Wait(newType pFunc, int second, int num) {
	//タイマー
	Sleep(second * 1000);

	pFunc(num);

	return 0;
}

int Output(int input) {
	if (input == 1) {
		printf("あたり！");
	}
	else {
		printf("はずれ...");
	}

	return 0;
}

int main() {
	//乱数
	srand(time(nullptr));
	//typedef用
	newType pFunc;
	//ランダムで出した数字の受け渡し
	int randNum = rand();
	//正誤の受け渡し用
	bool isHit = 0;

	//プレイヤーの入力
	//変数宣言
	int num = 0;

	//プレイヤーに案内を表示
	printf("偶数だと思うなら0を、奇数だと思うなら1を入力\n");

	//入力を受けつけ
	scanf_s("%d", &num);

	//入力を表示
	printf("入力-> %d\n", num);

	if (num == 0) {
		printf("あなたの入力-> 偶数\n");
	}
	else {
		printf("あなたの入力-> 奇数\n");
	}

	if (randNum % 2 == num) {
		isHit = true;
	}
	else {
		isHit = false;
	}

	//3秒待って結果を出力
	pFunc = &Output;
	Wait(pFunc, 3, isHit);

	return 0;
}