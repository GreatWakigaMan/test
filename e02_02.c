#include <stdio.h>
#define MAX   256

int main() {
  int c, i;
  char s[MAX];
  int flag = 0;

  // for(i=0; i<MAX-1 && (c=getchar())!='\n' && c!=EOF; ++i){
  //   s[i] = c;
  // }

  for(i=0; flag==0; i++){
    flag = 0;
    if(i<MAX-1){
      if((c=getchar())!='\n'){
        if(c!=EOF){
          s[i] = c;
        }
        else{
          flag = 1;
        }
      }
      else{
        flag = 1;
      }
    }
    else{
      flag = 1;
    }
  }

  printf("%s", s);

  return 0;
}
