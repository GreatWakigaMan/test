#include <stdio.h>

int strend(char *, char *);

int main(void)
{
  char s[] = "germanium onsen";
  char t[] = "sen";
  int flag;

  printf("s = %s\n", s);
  printf("t = %s\n", t);

  flag = strend(s, t);

  printf("flag = %d", flag);

  return 0;
}

// 文字列ｓの終わりにｔがあれば１を返す、なければ０を返す
int strend(char *s, char *t){
  int flag = 1;
  int i=0;
  // s, tのアドレスを文字列末尾まで送る
  // 文字数iを求めておく
  while(*s){
    s++;
  }
  s--;
  while(*t){
    i++;
    t++;
  }
  t--;

  // 文字列末尾から逆に辿って、*tの先頭まで一致するか否か調べる
  // iは文字数
  for(; i>0; i--){
    printf("*t = %c", *t);
    printf("\t*s = %c\n", *s);

    // 一致していたらflagに1をかける
    if(*t==*s){
      flag *= 1;
    }
    // 一致しなかったらflagに0をかける
    // 一文字でも一致しなかったらflagは0となる
    else{
      flag *= 0;
    }
    // 次の文字へ
    t--;
    s--;
  }

  // 全て一致すれば1を、しなければ0を返す
  if(flag==1){
    return 1;
  }
  else if(flag==0){
    return 0;
  }
  else{
    return -1;
  }
}
