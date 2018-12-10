// “ñ•ª’Tõ‚ÌŒvZŠÔ”äŠr
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 256
#define FLAG 1
#define LOOP 10000000

int binsearch(int, int []);
int binsearch_(int, int []);

int main(){
  int i, v[MAX];
  int x = 15;
  int index;

  for(i=0; i<MAX; i++){
    v[i] = i*2-1;
  }

  clock_t start,end;
  start = clock();

  switch(FLAG){
    case 1:
      for(i=1; i<=LOOP; i++){
        index = binsearch(x, v);
      }
      break;
    case 2:
      for(i=1; i<=LOOP; i++){
        index = binsearch_(x, v);
      }
      break;
  }
  printf("bin number : %d\n", index);

  end = clock();
  printf("%.3f•b‚©‚©‚è‚Ü‚µ‚½\n",(double)(end-start)/CLOCKS_PER_SEC);

  return 0;
}

// if•¶2‰ñ”Å
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

// if•¶1‰ñ”Å
int binsearch_(int x, int v[]){
  int low, high, mid;
  low = 0;
  high = MAX - 1;
  while(x!=v[(low+high)/2]){
    while(low<=high){
      mid = (low+high) / 2;
      if(x<v[mid]){
        high = mid - 1;
      }
      else{
        low = mid + 1;
      }
    }
    return (low+high)/2;
  }
  return -1;
}
