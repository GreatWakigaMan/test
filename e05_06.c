#include <stdio.h>
#define NMAX 100

int getline_(char *, int);
int atoi(char *);
void itoa(int, char *);
void itob(int, char *, int);
void reverse(char *);
int strindex(char *, char *);

int main(void)
{
   char s1[NMAX] = "tamago yaki uma uma";
   int n1;
   printf("----------getline----------\n");
   
   n1 = getline_(s1, NMAX);
   
   printf("s = %s\n", s1);
   printf("n = %d\n", n1);
   
   char s2[NMAX] = "180xxx";
   int n2;
   printf("\n----------atoi----------\n");
   
   n2 = atoi(s2);

   printf("s = %s\n", s2);
   printf("n = %d\n", n2);
   
   char s3[NMAX] = "";
   int n3 = -23566;
   printf("\n----------itoa----------\n");
   
   itoa(n3, s3);

   printf("s = %s\n", s3);
   printf("n = %d\n", n3);
   
   char s4[NMAX] = "";
   int n4 = -65535;
   int b = 16;
   printf("\n----------itob----------\n");
   
   itob(n4, s4, b);

   printf("s = %s\n", s4);
   printf("n = %d\n", n4);
   
   char s5[NMAX] = "tamago";
   printf("\n----------reverse----------\n");
   printf("s1 = %s\n", s5);
   
   reverse(s5);

   printf("s2 = %s\n", s5);
   
   char s6[NMAX] = "tamagoyaki tabetai";
   char t6[NMAX] = "aki";
   int n6;
   printf("\n----------strindex----------\n");
   
   n6 = strindex(s6, t6);
   
   printf("s = %s\n", s6);
   printf("t = %s\n", t6);
   printf("index no.%d\n", n6);

   return 0;
}

// 文字列ｓの長さ(＝文字数)を返す
int getline_(char *s, int lim){
   int n=0;
   while(*s){
      s++;
      n++;
      if(n>=lim){
         break;
      }
   }
   return n;
};

// 文字列ｓを整数に変換して返す
int atoi(char *s){
   int n=0;
   while(*s){
      if('0'<=*s&&*s<='9'){
         n = n*10 + (*s - '0');
      }
      else{
         break;
      }
      s++;
   }
   return n;
};

// 整数ｎを文字列ｓに格納する
void itoa(int n, char *s){
   int sign, i=0;
   char t[NMAX] = "";
   // 符号チェック
   sign = n;
   if(sign<0){
      n = -n;
   }
   while(n>0){
      // ポインタのアドレスを進めながら最下桁の値を入れる
      *s++ = n % 10 + '0';
      n /= 10;
      i++;
   }
   if(sign<0){
      *s++ = '-';
   }
   *s = '\0';
   for(; i>=0; i--, s--);
   reverse(s);
};

// 整数ｎをｂ進数に直し、文字列ｓに格納する
void itob(int n, char *s, int b){
   int sign, i=0;
   char t[NMAX] = "";
   // 符号チェック
   sign = n;
   if(sign<0){
      n = -n;
   }
   while(n>0){
      // ポインタのアドレスを進めながら最下桁の値を入れる
      if(n%b+'0'<='9'){
         *s++ = n % b + '0';
      }
      else{
         *s++ = n % b + '0' + ('A' - '9' - 1);
      }
      n /= b;
      i++;
   }
   if(sign<0){
      *s++ = '-';
   }
   *s = '\0';
   for(; i>=0; i--, s--);
   reverse(s);
};

// 文字列ｓを反転
void reverse(char *s){
   char *t;
   char c;
   t = s;
   while(*s){
      s++;
   }
   // 指すアドレスを頭と末尾で分けるためにｔを使用
   // 末尾の値をｃに一時的に格納して先頭の値に代入
   // 頭と末尾が一文字ずつ反転していく
   while(t<s){
      c = *--s;
      *s = *t;
      *t++ = c;
   }
};

// 文字列ｓにおける文字列ｔの字数を返す
// ｔが見当たらなければ-1を返す
int strindex(char *s, char *t){
   int i, j, flag;
   for(i=0; *(s+i); i++){
      flag = 0;
      for(j=0; *(t+j); j++){
         // ｔと完全に一致しているｓのインデックスを探す
         if(*(s+i+j)==*(t+j)){
            // ｔの末尾まで一致していたらフラグを立てる
            if(*(t+j+1)=='\0'){
               flag = 1;
            }
         }
         else{
            break;
         }
      }
      if(flag==1){
         return i+1; // 添え字番号と字数の差
      }
   }
   return -1; // 不一致で-1を返す
};
