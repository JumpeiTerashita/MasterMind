#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int hideNumBox[4]; /*あてるべきすうじおきば*/
int inputNumBox[4]; /*いれるすうじおきば*/

void makeNum(void); /*すうじつくる*/
void inputNum(void); /*すうじを挿れる*/
void judge(void);/*はんてぃする・みせる*/
void fin(void);  /*フィニッシュする*/
bool roopcheck(int* judge_1,int* judge_2);

int Cnt=0;

int main(void)
{
  makeNum();
  printf("\n私と『ゲーム』をしよう…ﾌﾌ\nルールは簡単 バラバラの『四桁』の『数字』を当ててもらう\n");
  printf("1〜9までのバラバラの『四桁』だ…\n四桁のうちにその数字が含まれていれば『EAT』！さらに場所も合っていれば『BITE』ッ！\n");
  printf("つまり『4EAT』すれば君の勝ちというわけだ…\n");
  printf("Open the GAME!\n");

  while ( !roopcheck(hideNumBox,inputNumBox) )
  {
    if(Cnt == 5)  printf("これは『試練』だ\n人の成長は…　未熟な過去に打ち勝つことだ…\nえ？お前もそうだろう？\n");
    if(Cnt == 10) printf("『素数』を数えて落ち着くんだ…\n『素数』は1と自分の数でしか割れない数字…\n勇気を与えてくれる\n");
    if(Cnt == 15) printf("『ひとりの囚人は壁を見ていた』\n『もうひとりの囚人は 鉄格子からのぞく星をみていた』\nお前はどっちだ？\n");
    printf("さあ、数字を入力したまえ…\n");
    Cnt++;
    inputNum();
    judge();
  }
  fin();
  return 0;
}

void makeNum(void)
{
RESTART:
  srand((unsigned)time(NULL));
  for (int i = 0; i < 4; i++) {
      hideNumBox[i] = (rand()%9) + 1 ;
  }
  for (int first = 0; first < 3; first++) {
    for (int second = first + 1; second < 4; second++) {
        if (hideNumBox[first]==hideNumBox[second]) {
          goto RESTART;
        }
    }
  }
  return;
}

void inputNum(void)
{
  int inputNum;
  scanf("%d",&inputNum);
  if(inputNum>9999||inputNum<1000) {printf("その入力は許可しないッ！\n『ゲームオーバー』だ…！\n"); exit(1);}
  inputNumBox[3] = inputNum%10;
  inputNum = inputNum/10;
  inputNumBox[2] = inputNum%10;
  inputNum = inputNum/10;
  inputNumBox[1] = inputNum%10;
  inputNum = inputNum/10;
  inputNumBox[0] = inputNum%10;
}

void judge(void)
{ int hit= 0,bite = 0;
  if (inputNumBox[0] == hideNumBox[0]) hit++;
  else if ((inputNumBox[0] == hideNumBox[1])||(inputNumBox[0] == hideNumBox[2])||(inputNumBox[0] == hideNumBox[3])) bite++;
  if (inputNumBox[1] == hideNumBox[1]) hit++;
  else if ((inputNumBox[1] == hideNumBox[0])||(inputNumBox[1] == hideNumBox[2])||(inputNumBox[1] == hideNumBox[3])) bite++;
  if (inputNumBox[2] == hideNumBox[2]) hit++;
  else if ((inputNumBox[2] == hideNumBox[0])||(inputNumBox[2] == hideNumBox[1])||(inputNumBox[2] == hideNumBox[3])) bite++;
  if (inputNumBox[3] == hideNumBox[3]) hit++;
  else if ((inputNumBox[3] == hideNumBox[0])||(inputNumBox[3] == hideNumBox[1])||(inputNumBox[3] == hideNumBox[2])) bite++;

  if ((inputNumBox[0] == 0)||(inputNumBox[1] == 0)||(inputNumBox[2] == 0)||(inputNumBox[3] == 0))
    { printf("1〜9までの数と言ったはずだッ！\n0を打つのは『ルール違反』だ…！\n"); }
  if (
      (inputNumBox[0] == inputNumBox[1])||(inputNumBox[0] == inputNumBox[2])||(inputNumBox[0] == inputNumBox[3])||
      (inputNumBox[1] == inputNumBox[2])||(inputNumBox[1] == inputNumBox[3])||
      (inputNumBox[2] == inputNumBox[3])
      )
    printf("バラバラの『四桁』と言ったはずだッ！\n同じ数字を打つのは『ルール違反』だ…！\n");
  if  (
       !(
      (inputNumBox[0] == inputNumBox[1])||(inputNumBox[0] == inputNumBox[2])||(inputNumBox[0] == inputNumBox[3])||
      (inputNumBox[1] == inputNumBox[2])||(inputNumBox[1] == inputNumBox[3])||
      (inputNumBox[2] == inputNumBox[3])
	 )
       &&!((inputNumBox[0] == 0)||(inputNumBox[1] == 0)||(inputNumBox[2] == 0)||(inputNumBox[3] == 0))
       )
  printf("%dEAT！ %dBITE！\n",hit,bite);
}

bool roopcheck(int* judge_1,int* judge_2)
{
  for (int i = 0; i < 4; i++) {
    if (judge_1[i]!=judge_2[i]) {
      return false;
    }
  }
  return true;
}

void fin(void)
{
  printf("Congratulations!\n");
  if (Cnt<=10) printf("たったの%d回で当てるとは…\nいや、恐れいったよ\n",Cnt);
  else printf("%d回目でようやく当たったようだな…\nその『忍耐力』は褒めてやる\n",Cnt);
}
