// ���͂̍Ō��n�s���o�͂���֐�tail
// �R�}���h���C����������-n�̌`�ōs���w��
// e05_13<hoge.txt -n
#include<stdio.h>
#include<stdlib.h>
#define MAXCHAR 100			// ��s�̍ő啶����
#define MAXLINE 100			// �ő�s��

void tail(int);

int main(int argc, char *argv[]){
	int n=10;
	int inputchk;
	
	// �����`�F�b�N
	if(argc==1){
		inputchk = 1;
	}
	else if(argc==2){
		// ��������"-"�Ŏn�܂��Ă�H
		if(**++argv=='-'){
			n = -1 * atoi(*argv);
			if(n==0){
				inputchk = 0;
			}
			else{
				inputchk = 1;
			}
		}
		else{
			inputchk = 0;
		}
	}
	else{
		inputchk = 0;
	}
	
	// ���͂��s���m�ł���΃G���[��Ԃ�
	if(inputchk==0){
		printf("Usage: e05_13 -n\n");
		printf("n: line\n");
	}
	// ���������tail�����s
	else{
		printf("n: %d\n", n);
		tail(n);
	}
}

void tail(int n){
	char c;															// �ǂݎ��������
	char data[MAXLINE+1][MAXCHAR+1]={};	// �f�[�^�i�[
	int lin=1;													// ���݂̍s��
	int chr=0;													// ��s���̌��݂̕�����
	int i;															// ���[�v�p
	int act;														// ���ۂɓ��삳����s��
	// �t�@�C�������܂Ńf�[�^�ǂݍ���
	while((c=getchar())!=EOF){
		chr++;
		if(chr<MAXCHAR){
			*(*(data+lin)+chr-1) = c;
		}
		else{
			printf("Too many char.\n");
			return;
		}
		// ���s����
		if(c=='\n'){
			chr = 0;
			lin++;
			if(lin>MAXLINE){
				printf("Too many line.\n");
				return;
			}
		}
	}
	// ��������n�s�߂���act�s�ڂ�T��
	if(lin<n){
		n = lin;
	}
	act = lin - n + 1;
	// act�s�ڂ��疖���܂ł��o��
	for(i=act; i<lin+1; i++){
		printf("%s", *(data+i));
	}
}
