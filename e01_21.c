// �󔒂��ŏ���tab/blanc�Œu��������
// e01_21<hoge.txt �Ƃ��Ďg�p
#include<stdio.h>
#include<stdlib.h>
#define TABSTOP 4

int tabnum = 0;
int spnum = 0;
void entab(int, int, int);

int main(void){
	int lin=0; // �s�̕�����
	int space=0; // �󔒕�����
	int state_char=1; // 0:�� 1:������
	char c;
	
	// ����
	while(1){
		c=getchar();
		if(c==' '){
			lin++;
			space++;
			state_char = 0;
		}
		// tab��ǂ񂾂Ƃ�
		else if(c=='\t'){
			lin += TABSTOP - lin % TABSTOP;
			space += TABSTOP - lin % TABSTOP;
			state_char = 0;
		}
		// ���s��ǂ񂾂Ƃ�
		else if(c=='\n'){
			if(state_char==0){
				entab(lin, space, TABSTOP);
			}
			lin = 0;
			space = 0;
			state_char = 1;
			printf("%c", c);
		}
		// �t�@�C������
		else if(c==EOF){
			if(state_char==0){
				entab(lin, space, TABSTOP);
			}
			break;
		}
		// ������ǂ񂾂Ƃ�
		else{
			if(state_char==0){
				entab(lin, space, TABSTOP);
			}
			lin++;
			space = 0;
			printf("%c", c);
//			printf("%d", lin);
			state_char = 1;
		}
	}
	
	printf("\n\n");
	printf("tab   : %d\n", tabnum);
	printf("space : %d\n", spnum);
	
	return 0;
}

// �󔒂��當���ɓ���ւ�����Ƃ��A
// �s�̕������ƃX�y�[�X�̐�����œK�ȃ^�u�E�u�����N��}��
void entab(int lin, int space, int tabstop){
	int st; // �󔒊J�n���̍s�̕�����
	st = lin - space;
	if((tabstop-st%tabstop)>space){ // tab�ł̓I�[�o�[�ȂƂ�
		while(space>0){
			printf(" ");
			spnum++;
			space--;
		}
	}
	else{
		do{ // tab�����ȏ�͓����
			printf("\t");
			tabnum++;
			space -= tabstop;
		}while(space>tabstop); // ���ڂ���̓^�u�X�g�b�v���c��X�y�[�X������Γ����
		while(space>0){ // �c��̓X�y�[�X�Ŗ��߂�
			printf(" ");
			spnum++;
			space--;
		}
	}
}

