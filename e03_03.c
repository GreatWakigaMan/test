// a-z�A0-9�̓W�J
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 256

void arrinit(char []);
void expand(char [], char []);

int main(){
  // int i;
  char s[MAX], t[MAX];
  arrinit(s);
  arrinit(t);
  // fgets(s, sizeof(s), stdin);
  // for(i=0;i<=strlen(s);i++){
  //   printf("%d ", s[i]);
  // }
  // printf("\n");

  expand(s, t);

  // printf("\n");

  printf("s : %s", s);
  printf("t : %s", t);

  return 0;
}

//a-z, 0-9�̓W�J
void expand(char s[], char t[]){
  int i, j, k, len;
  char bef, aft;
  len = strlen(s);
  for(i=j=0; i<=len-1; i++, j++){
    if(s[i]=='-'){
      bef = s[i-1];
      aft = s[i+1];
      if(i==0 || i==len){ //�ŏ�or�Ō�̕���
        // printf("1");
        t[j] = s[i];
      }else if(bef<aft && bef>='a' && bef<='z' && aft>='a' && aft<='z'){
        // printf("2");
        // a-z�̂悤�Ȍ`���m�F
        for(k=1; k<aft-bef; k++, j++){
          t[j] = bef + k;
        }
        j--; //�C���N�������g��߂�
      }else if(bef<aft && bef>='0' && bef<='9' && aft>='0' && aft<='9'){
        // printf("3");
        // 0-9�̂悤�Ȍ`���m�F
        for(k=1; k<aft-bef; k++, j++){
          t[j] = bef + k;
        }
        j--;//�C���N�������g��߂�
      }else{
        // printf("4");
        t[j] = s[i];
      }
    }else{ //��ʂ̕���
      // printf("5");
      t[j] = s[i];
    }
  }
}

// �z�񏉊���
void arrinit(char t[]){
  int i;
  for(i=0; i<MAX; i++){
    t[i] = '\0';
  }
}
