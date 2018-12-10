#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include <time.h>
#include "myheader.h"

//配列初期化
void arrinit(char t[], int mx){
  int i;
  for(i=0; i<mx; i++){
    t[i] = '\0';
  }
}

//配列tのj番目の要素を削除
void del_digit(char t[], int j){
  while(t[j]!=EOF){
    t[j] = t[j+1];
    j++;
  }
  t[j] = EOF;
}

//配列tのj番目に文字cを挿入
void ins_digit(char t[], int j, char c){
  int k;
  for(k=MAX-1; k>j; k--){
    t[k] = t[k-1];
  }
  t[k] = c;
}

// sからtに含まれる文字をすべて取り除く
void squeeze(char s1[], char s2[]){
  int i, j;
  int count1, count2;
  i = strlen(s2); // s2の長さ
  for(count1=0; count1<=i; count1++){
    j = strlen(s1); // s1の長さ
    for(count2=0; count2<=j; count2++){
      // s1のcount2文字目とs2のcount1文字目が一致していたら削除
      if(s1[count2]==s2[count1]){
        del_digit(s1, count2);
        count2--;
      }
    }
  }
}

// s2の任意の文字がs1の何番目に現れるか
int any(char s1[], char s2[], int index[]){
  int i, j;
  int count1, count2;
  int flag = -1;
  i = strlen(s2); // s2の長さ
  for(count1=0; count1<=i; count1++){
    j = strlen(s1); // s1の長さ
    for(count2=0; count2<=j; count2++){
      // s1のcount2文字目とs2のcount1文字目が一致していたら保存
      if(s1[count2]==s2[count1]){
        index[count1] = count2;
        flag = 0;
        break;
      }
    }
  }
  return flag;
}

// 2ビット桁数チェック
int bitslen(unsigned x){
  int count, d = 1;
  for(count=1; ; count++){
    d *= 2;
    if(x<d){
      break;
    }
  }
  // printf("i = %d\n", count);
  return count;
}

// xのp番目からnビットを取得
unsigned getbits(unsigned x, int p, int n){
  unsigned xpn;
  xpn = (x >> (p-1)) & ~(~0 << n);
  // printf("g = %d\n", xpn);
  return xpn;
}

// xのp番目からnビットをyの右端にセット
unsigned setbits(unsigned x, int p, int n, unsigned y){
  unsigned xpn;
  int len;
  // xのp番目からnビット
  xpn = getbits(x, p, n);
  // xpnが何桁あるかチェック
  len = bitslen(xpn);
  // printf("k = %d\n", (y << len));
  // yを桁上げしてxpsをセット
  return xpn | (y << len);
}

// xのp番目からnビットを反転
unsigned invert(unsigned x, int p, int n){
  unsigned inv=0;
  int i;
  // xのp番目からnビットを潰す
  inv = x >> (p+n-1);
  // printf("inv = %d\n\n", inv);
  // invに反転ビットを加える
  for(i=p+n-1; i>=p; i--){
    inv = setbits(~x, i, 1, inv);
    // printf("inv = %d\n", inv);
  }
  // invにxの先頭ビットを加える
  for(i=p-1; i>=1; i--){
    inv = setbits(x, i, 1, inv);
    // printf("inv = %d\n", inv);
  }
  return inv;
}

// xのnビットローテーション
unsigned rightrot(unsigned x, int n){
  unsigned rot=0;
  unsigned xpn;
  int len;
  len = bitslen(x);
  // 下位nビットを取得
  xpn = getbits(x, 1, n);
  // 上位のgetしていないビットをgetbitsに突っ込む
  rot = setbits(x, n+1, len-n, xpn);
  return rot;
}

// ビット列xの1の数を数える
int bitcount(unsigned x){
  int n;
  while(x != 0){
    x &= (x - 1);
    n++;
  }
  return n;
}

//大文字→小文字変換
int lower(int c){
  c = (c>='A')&&(c<='Z') ? c+32 : c;
  return c;
}

// v[]中のxの二分探索、配列番号を返す
int binsearch(int x, int v[]){
  int low, high, mid;
  low = 0;
  high = MAX - 1;
  while(low<=high){
    mid = (low+high) / 2;
    if(x<v[mid]){
      high = mid - 1;
    }
    else if(x>v[mid]){
      low = mid + 1;
    }
    else{
      return mid;
    }
  }
  return -1;
}

// タブ、改行 → \n, \t
void escape(char s[], char t[]){
  int i, j, len;
  len = strlen(s);
  for(i=0, j=0; i<len; i++, j++){
    switch(s[i]){
      case '\n' : t[j] = '\\';
                  t[++j] = 'n';
                  break;
      case '\t' : t[j] = '\\';
                  t[++j] = 't';
                  break;
      default : t[j] = s[i];
                break;
    }
  }
}

// \n, \t → タブ、改行
void escape_(char s[], char t[]){
  int i, j, len;
  len = strlen(s);
  for(i=0, j=0; i<len; i++, j++){
    if(s[i]=='\\'){
      switch(s[i+1]){
        case 'n' :  t[j] = '\n';
                    i++;
                    break;
        case 't' :  t[j] = '\t';
                    i++;
                    break;
        default : t[j] = s[i];
                  break;
      }
    }
    else{
      t[j] = s[i];
    }
  }
}

//a-z, 0-9の展開
void expand(char s[], char t[]){
  int i, j, k, len;
  char bef, aft;
  len = strlen(s);
  for(i=j=0; i<=len-1; i++, j++){
    if(s[i]=='-'){
      bef = s[i-1];
      aft = s[i+1];
      if(i==0 || i==len){ //最初or最後の文字
        // printf("1");
        t[j] = s[i];
      }else if(bef<aft && bef>='a' && bef<='z' && aft>='a' && aft<='z'){
        // printf("2");
        // a-zのような形を確認
        for(k=1; k<aft-bef; k++, j++){
          t[j] = bef + k;
        }
        j--; //インクリメントを戻す
      }else if(bef<aft && bef>='0' && bef<='9' && aft>='0' && aft<='9'){
        // printf("3");
        // 0-9のような形を確認
        for(k=1; k<aft-bef; k++, j++){
          t[j] = bef + k;
        }
        j--;//インクリメントを戻す
      }else{
        // printf("4");
        t[j] = s[i];
      }
    }else{ //一般の文字
      // printf("5");
      t[j] = s[i];
    }
  }
}

// 文字列反転
void reverse(char s[]){
  int c, i, j;
  for(i=0, j=strlen(s)-1; i<j; i++, j--){
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

// s[]で最後に現れるtの位置
int strrindex(char s[], char t){
  int r, len, i;
  len = strlen(s);

  for(i=len-1; i>=0; i--){
    if(s[i]==t){
      r = i;
      break;
    }
  }
  return r+1; // 配列番号から文字番号に合わせる
}

// 数字→b進数文字列変換
void itob(int n, char s[], int b){
  int i, sign;
  if((sign=n)<0){
    n = -n;
  }
  i = 0;
  do{
    if(n%b+'0'<='9'){
      s[i++] = n % b + '0';
    }
    else{
      s[i++] = n % b + '0' + ('A' - '9' - 1);
    }
  } while((n /= b) > 0);
  if(sign<0){
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}
