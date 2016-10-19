#define ERROR 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "MT.h"


int hideNumBox[4]; /*あてるべきすうじおきば*/
int inputNumBox[4]; /*いれるすうじおきば*/

int Cnt = 0;

void resetNum(int* hideBox, int*inputNum) {
	for (int i = 0; i < 4; i++)
	{
		hideBox[i] = 0;
		inputNum[i] = 0;
	}
	return;
}

void makeNum(void) {
RESTART:
	init_genrand((unsigned)time(NULL));
	for (int i = 0; i < 4; i++) {
		hideNumBox[i] = (genrand_int32() % 9) + 1;
	}
	for (int first = 0; first < 3; first++) {
		for (int second = first + 1; second < 4; second++) {
			if (hideNumBox[first] == hideNumBox[second]) {
				goto RESTART;
			}
		}
	}
	return;
}

int inputNum(void)
{
	int inputNum;
	scanf_s("%d", &inputNum);
	//危険入力回避
	if (inputNum > 9999 || inputNum < 1000) {
		printf("その入力は許可しないッ！\n『ゲームオーバー』だ…！\n");
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

void judge(void)
{

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



bool roopcheck(int* judge_1, int* judge_2)
{
	for (int i = 0; i < 4; i++) {
		if (judge_1[i] != judge_2[i]) {
			return false;
		}
	}
	return true;
}

void fin(void)
{
	printf("Congratulations!\n");
	if (Cnt <= 10) printf("たったの%d回で当てるとは…\nいや、恐れいったよ\n", Cnt);
	else printf("%d回目でようやく当たったようだな…\nその『忍耐力』は褒めてやる\n", Cnt);
	getchar();
	return;
}


int main(void)
{

	resetNum(hideNumBox, inputNumBox);
	printf("\n私と『ゲーム』をしよう…ﾌﾌ\nルールは簡単 バラバラの『四桁』の『数字』を当ててもらう\n");
	printf("1〜9までのバラバラの『四桁』だ…\n四桁のうちにその数字が含まれていれば『EAT』！さらに場所も合っていれば『BITE』ッ！\n");
	printf("つまり『4EAT』すれば君の勝ちというわけだ…\n");
	makeNum();
	printf("Open the GAME!\n");

	while (!roopcheck(hideNumBox, inputNumBox))
	{
		if (Cnt == 5)  printf("\nこれは『試練』だ\n人の成長は…　未熟な過去に打ち勝つことだ…\nえ？お前もそうだろう？\n");
		if (Cnt == 10) printf("\n『素数』を数えて落ち着くんだ…\n『素数』は1と自分の数でしか割れない数字…\n勇気を与えてくれる\n");
		if (Cnt == 15) printf("\n『ひとりの囚人は壁を見ていた』\n『もうひとりの囚人は 鉄格子からのぞく星をみていた』\nお前はどっちだ？\n");
		printf("\nさあ、数字を入力したまえ…\n");
		Cnt++;
		if (inputNum() == ERROR) goto END;
		judge();
	}
	fin();
END:
	getchar();

	getchar();
	return 0;
}






