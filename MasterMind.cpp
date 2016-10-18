#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int num[4]; /*あてるべきすうじおきば*/
int impo[4]; /*いれるすうじおきば*/

void mnko(void); /*すうじつくる*/
void cmpo(void); /*すうじを挿れる*/
void panty(void);/*はんてぃする・みせる*/
void fin(void);  /*フィニッシュする*/

int Cnt=0;

int main(void)
{
  mnko();
  printf("\n私と『ゲーム』をしよう…ﾌﾌ\nルールは簡単 バラバラの『四桁』の『数字』を当ててもらう\n");
  printf("1〜9までのバラバラの『四桁』だ…\n四桁のうちにその数字が含まれていれば『EAT』！さらに場所も合っていれば『BITE』ッ！\n");
  printf("つまり『4EAT』すれば君の勝ちというわけだ…\n");


  printf("Open the GAME!\n");

  while ( !( (num[0] == impo[0])&&(num[1] == impo[1])&&(num[2] == impo[2])&&(num[3] == impo[3]))  )
  {
    if(Cnt == 5)  printf("これは『試練』だ\n人の成長は…　未熟な過去に打ち勝つことだ…\nえ？お前もそうだろう？\n");
    if(Cnt == 10) printf("『素数』を数えて落ち着くんだ…\n『素数』は1と自分の数でしか割れない数字…\n勇気を与えてくれる\n");
    if(Cnt == 15) printf("『ひとりの囚人は壁を見ていた』\n『もうひとりの囚人は 鉄格子からのぞく星をみていた』\nお前はどっちだ？\n");
    printf("さあ、数字を入力したまえ…\n");
    Cnt++;
    cmpo();
    panty();
  }
  fin();
}

void mnko(void)
{
  srand((unsigned)time(NULL));
    while (num[0] == 0)
  {
    num[0] = (rand()%9) + 1 ;
  }
    while ((num[0] == num[1])||(num[1] == 0))
  {
    num[1] = (rand()%9) + 1 ;
  }
    while ( (num[2] == num[1])||(num[2] == num[0])||(num[2] == 0) )
  {
    num[2] = (rand()%9) + 1 ;
  }
    while ( (num[3] == num[2])||(num[3] == num [1])||(num[3] == num [0])||(num[3] == 0) )
  {
    num[3] = (rand()%9) + 1 ;
  }

}

void cmpo(void)
{
  int unko;
  scanf("%d",&unko);
  if(unko>9999||unko<1000) {printf("その入力は許可しないッ！\n『ゲームオーバー』だ…！\n"); exit(1);}
  impo[3] = unko%10;
  unko = unko/10;
  impo[2] = unko%10;
  unko = unko/10;
  impo[1] = unko%10;
  unko = unko/10;
  impo[0] = unko%10;
}

void panty(void)
{ int hit= 0,bite = 0;
  if (impo[0] == num[0]) hit++;
  else if ((impo[0] == num[1])||(impo[0] == num[2])||(impo[0] == num[3])) bite++;
  if (impo[1] == num[1]) hit++;
  else if ((impo[1] == num[0])||(impo[1] == num[2])||(impo[1] == num[3])) bite++;
  if (impo[2] == num[2]) hit++;
  else if ((impo[2] == num[0])||(impo[2] == num[1])||(impo[2] == num[3])) bite++;
  if (impo[3] == num[3]) hit++;
  else if ((impo[3] == num[0])||(impo[3] == num[1])||(impo[3] == num[2])) bite++;

  if ((impo[0] == 0)||(impo[1] == 0)||(impo[2] == 0)||(impo[3] == 0)) 
    { printf("1〜9までの数と言ったはずだッ！\n0を打つのは『ルール違反』だ…！\n"); }
  if (
      (impo[0] == impo[1])||(impo[0] == impo[2])||(impo[0] == impo[3])||
      (impo[1] == impo[2])||(impo[1] == impo[3])||
      (impo[2] == impo[3])
      )
    printf("バラバラの『四桁』と言ったはずだッ！\n同じ数字を打つのは『ルール違反』だ…！\n");
  if  (
       !(
      (impo[0] == impo[1])||(impo[0] == impo[2])||(impo[0] == impo[3])||
      (impo[1] == impo[2])||(impo[1] == impo[3])||
      (impo[2] == impo[3])
	 )
       &&!((impo[0] == 0)||(impo[1] == 0)||(impo[2] == 0)||(impo[3] == 0))
       )
  printf("%dEAT！ %dBITE！\n",hit,bite);
}



void fin(void)
{
  printf("Congratulations!\n");
  if (Cnt<=10) printf("たったの%d回で当てるとは…\nいや、恐れいったよ\n",Cnt);
  else printf("%d回目でようやく当たったようだな…\nその『忍耐力』は褒めてやる\n",Cnt);
}
