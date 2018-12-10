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

// •¶š—ñ‚“‚ÌI‚í‚è‚É‚”‚ª‚ ‚ê‚Î‚P‚ğ•Ô‚·A‚È‚¯‚ê‚Î‚O‚ğ•Ô‚·
int strend(char *s, char *t){
  int flag = 1;
  int i=0;
  // s, t‚ÌƒAƒhƒŒƒX‚ğ•¶š—ñ––”ö‚Ü‚Å‘—‚é
  // •¶š”i‚ğ‹‚ß‚Ä‚¨‚­
  while(*s){
    s++;
  }
  s--;
  while(*t){
    i++;
    t++;
  }
  t--;

  // •¶š—ñ––”ö‚©‚ç‹t‚É’H‚Á‚ÄA*t‚Ìæ“ª‚Ü‚Åˆê’v‚·‚é‚©”Û‚©’²‚×‚é
  // i‚Í•¶š”
  for(; i>0; i--){
    printf("*t = %c", *t);
    printf("\t*s = %c\n", *s);

    // ˆê’v‚µ‚Ä‚¢‚½‚çflag‚É1‚ğ‚©‚¯‚é
    if(*t==*s){
      flag *= 1;
    }
    // ˆê’v‚µ‚È‚©‚Á‚½‚çflag‚É0‚ğ‚©‚¯‚é
    // ˆê•¶š‚Å‚àˆê’v‚µ‚È‚©‚Á‚½‚çflag‚Í0‚Æ‚È‚é
    else{
      flag *= 0;
    }
    // Ÿ‚Ì•¶š‚Ö
    t--;
    s--;
  }

  // ‘S‚Äˆê’v‚·‚ê‚Î1‚ğA‚µ‚È‚¯‚ê‚Î0‚ğ•Ô‚·
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
