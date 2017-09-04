#define ERROR 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "MT.h"


int hideNumBox[4]; /*あてるべきすうじおきば*/
int inputNumBox[4]; /*いれるすうじおきば*/

int inputCount = 0;

void initNum(int* hideBox, int* inputNum) {

	//配列　初期化

	for (int i = 0; i < 4; i++)
	{
		hideBox[i] = 0;
		inputNum[i] = 0;
	}

	inputCount = 0;

	return;
}

void generateRandomNum() {

	//4桁数字生成（かぶりなし）

	init_genrand((unsigned)time(NULL));

	int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = sizeof(values) / sizeof(int);

	int i = size;
	while (i > 1) {
		int j = genrand_int31() % i;
		i--;
		int t = values[i];
		values[i] = values[j];
		values[j] = t;
	}

	for (int k = 0; k < 4; k++)
	{
		hideNumBox[k] = values[k];
	}


	//RESTART:
	//	init_genrand((unsigned)time(NULL));
	//	for (int i = 0; i < 4; i++) {
	//		hideNumBox[i] = (genrand_int32() % 9) + 1;
	//	}
	//	for (int first = 0; first < 3; first++) {
	//		for (int second = first + 1; second < 4; second++) {
	//			if (hideNumBox[first] == hideNumBox[second]) {
	//				goto RESTART;
	//			}
	//		}
	//	}
	return;
}

int inputNum()
{
	int inputNum;
	scanf_s("%d", &inputNum);
	//危険入力回避
	if (inputNum > 9999 || inputNum < 1000) {
		inputCount++;
		printf("その入力は許可しないッ！\n");
		getchar();
		getchar();
		return ERROR;
	}
	inputNumBox[3] = inputNum % 10;
	inputNum = inputNum / 10;
	inputNumBox[2] = inputNum % 10;
	inputNum = inputNum / 10;
	inputNumBox[1] = inputNum % 10;
	inputNum = inputNum / 10;
	inputNumBox[0] = inputNum % 10;
	return 0;
}

void judge()
{
	inputCount++;
	int hit = 0, bite = 0;
	//ルール違反ジャッジ
	for (int i = 0; i < 4; i++)
	{
		if (inputNumBox[i] == 0) {
			printf("1~9までの数と言ったはずだッ！\n0を打つのは『ルール違反』だ…！\n");
			return;
		}
		for (int j = i + 1; j < 4; j++)
		{
			if (inputNumBox[i] == inputNumBox[j])
			{
				printf("バラバラの『四桁』と言ったはずだッ！\n同じ数字を打つのは『ルール違反』だ…！\n");
				return;
			}
		}
	}
	//hit bite ジャッジ
	for (int i = 0; i < 4; i++)
	{
		if (inputNumBox[i] == hideNumBox[i]) hit++;
		else for (int n = 0; n < 4; n++)
		{
			if (inputNumBox[i] == hideNumBox[n]) {
				bite++;
			}
		}
	}
	//結果表示
	printf("%dEAT！ %dBITE！\n", hit, bite);
	return;
}



bool inputCheck(int* hideNum, int* inputNum)
{
	for (int i = 0; i < 4; i++) {
		if (hideNum[i] != inputNum[i]) {
			return false;
		}
	}
	return true;
}

void fin()
{
	printf("Congratulations!\n");
	if (inputCount <= 10) printf("たったの%d回で当てるとは…\nいや、恐れいったよ\n", inputCount);
	else printf("%d回目でようやく当たったようだな…\nその『忍耐力』は褒めてやる\n", inputCount);
	getchar();
	return;
}

bool askRetry()
{
	printf("で…どうする？『再び』か？ 再びかァァーッ！！\n");
	printf("（リトライ　= 0 、終了　= 1 を入力）\n");
	int retryInput;
	scanf_s("%d", &retryInput);
	if (retryInput == 0) return true;
	return false;
}


int main(void)
{
	do
	{
		system("cls");
		initNum(hideNumBox, inputNumBox);

		printf("\n私と『ゲーム』をしよう…ﾌﾌ\nルールは簡単 バラバラの『四桁』の『数字』を当ててもらう\n");
		printf("1〜9までのバラバラの『四桁』だ…\n四桁のうちにその数字が含まれていれば『EAT』！さらに場所も合っていれば『BITE』ッ！\n");
		printf("つまり『4EAT』すれば君の勝ちというわけだ…\n");
		generateRandomNum();
		printf("Open the GAME!\n");

		while (!inputCheck(hideNumBox, inputNumBox))
		{
			if (inputCount == 5)  printf("\nこれは『試練』だ\n人の成長は…　未熟な過去に打ち勝つことだ…\nえ？お前もそうだろう？\n");
			if (inputCount == 10) printf("\n『素数』を数えて落ち着くんだ…\n『素数』は1と自分の数でしか割れない数字…\n勇気を与えてくれる\n");
			if (inputCount == 15) printf("\n『ひとりの囚人は壁を見ていた』\n『もうひとりの囚人は 鉄格子からのぞく星をみていた』\nお前はどっちだ？\n");
			printf("\nさあ、数字を入力したまえ…\n");
			if (inputNum() == ERROR) continue;
			judge();
		}
		fin();
		getchar();


	} while (askRetry() == true);

	return 0;
}






