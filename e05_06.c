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

// �����񂓂̒���(��������)��Ԃ�
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

// �����񂓂𐮐��ɕϊ����ĕԂ�
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

// �������𕶎��񂓂Ɋi�[����
void itoa(int n, char *s){
   int sign, i=0;
   char t[NMAX] = "";
   // �����`�F�b�N
   sign = n;
   if(sign<0){
      n = -n;
   }
   while(n>0){
      // �|�C���^�̃A�h���X��i�߂Ȃ���ŉ����̒l������
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

// �����������i���ɒ����A�����񂓂Ɋi�[����
void itob(int n, char *s, int b){
   int sign, i=0;
   char t[NMAX] = "";
   // �����`�F�b�N
   sign = n;
   if(sign<0){
      n = -n;
   }
   while(n>0){
      // �|�C���^�̃A�h���X��i�߂Ȃ���ŉ����̒l������
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

// �����񂓂𔽓]
void reverse(char *s){
   char *t;
   char c;
   t = s;
   while(*s){
      s++;
   }
   // �w���A�h���X�𓪂Ɩ����ŕ����邽�߂ɂ����g�p
   // �����̒l�����Ɉꎞ�I�Ɋi�[���Đ擪�̒l�ɑ��
   // ���Ɩ������ꕶ�������]���Ă���
   while(t<s){
      c = *--s;
      *s = *t;
      *t++ = c;
   }
};

// �����񂓂ɂ����镶���񂔂̎�����Ԃ�
// ������������Ȃ����-1��Ԃ�
int strindex(char *s, char *t){
   int i, j, flag;
   for(i=0; *(s+i); i++){
      flag = 0;
      for(j=0; *(t+j); j++){
         // ���Ɗ��S�Ɉ�v���Ă��邓�̃C���f�b�N�X��T��
         if(*(s+i+j)==*(t+j)){
            // ���̖����܂ň�v���Ă�����t���O�𗧂Ă�
            if(*(t+j+1)=='\0'){
               flag = 1;
            }
         }
         else{
            break;
         }
      }
      if(flag==1){
         return i+1; // �Y�����ԍ��Ǝ����̍�
      }
   }
   return -1; // �s��v��-1��Ԃ�
};
