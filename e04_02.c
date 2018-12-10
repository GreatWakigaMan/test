// atof‚Ée‚ğ—p‚¢‚½‹L–@‚ğ‹–‚·
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <tgmath.h>
#include <ctype.h>
#define MAX 64

double at0f(char []);
double atof_(char []);

int main() {
  double f, g;
  char s[MAX] = "  -10.5e-2";

  f = at0f(s);
  g = atof_(s);
  printf("%s\n", s);
  printf("%.4f\n", f);
  printf("%.4f\n", g);

  return 0;
}

double at0f(char s[]){
  double val, power;
  int i, sign;

  for(i=0; isspace(s[i])!=0; i++); // ‹ó”’‚ğ”ò‚Î‚·
  if(s[i]=='-'){
    sign = -1;
  }
  else{
    sign = 1;
  }
  if(s[i]=='-' || s[i]=='+'){
    i++;
  }
  for(val=0.0; isdigit(s[i])!=0; i++){
    val = 10.0 * val + (s[i] - '0');
  }
  if(s[i]=='.'){
    i++;
  }
  for(power=1.0; isdigit(s[i])==1; i++){
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  printf("esign = %f\n", sign * val / power);
  return sign * val / power;
}

double atof_(char s[]){
  double val, power;
  int i, sign, esign, p=0;

  for(i=0; isspace(s[i])!=0; i++); // ‹ó”’‚ğ”ò‚Î‚·
  if(s[i]=='-'){
    sign = -1;
  }
  else{
    sign = 1;
  }
  if(s[i]=='-' || s[i]=='+'){
    i++;
  }
  for(val=0.0; isdigit(s[i])!=0; i++){
    val = 10.0 * val + (s[i] - '0');
  }
  if(s[i]=='.'){
    i++;
  }
  for(power=1.0; isdigit(s[i])==1; i++){
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  // e}n‚Ìˆ—
  if(s[i]=='e'){
    i++;
  }
  if(s[i]=='-'){
    esign = -1;
    i++;
  }
  else if(s[i]=='+'){
    esign = 1;
    i++;
  }
  else{
    return sign * val / power; // "e3"‚Æ‚©“ü‚Á‚Ä‚½‚çreturn
  }
  for(p=0.0; isdigit(s[i])!=0; i++){
    p = 10.0 * p + (s[i] - '0');
  }
  return sign * val / power * pow(10.0, p*esign);
}
