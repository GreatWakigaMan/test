// tab�𔼊p�X�y�[�X�ɂ���
// �����Ń^�u�X�g�b�v���������
#include<stdio.h>
#include<stdlib.h>

int tabnum = 0;
int spnum = 0;
void entab(int, int, int);

int main(int argc, char *argv[]){
	int tabstop;
	
	// �����`�F�b�N
	if(argc==1){
		tabstop = 4;
	}
	else if(argc==2){
		tabstop = atoi(argv[1]);
		if(tabstop<1){
			printf("Usage: e05_11 tabstop\n");
			return 0;
		}
	}
	else{
		printf("Usage: e05_11 tabstop\n");
		return 0;
	}
	
	int chr=0; // �s�̕�����
	int space=0; // �󔒕�����
	int state_char=1; // 0:�� 1:������
	char c;
	
	// ����
	while(1){
		c=getchar();
		if(c==' '){
			chr++;
			space++;
			state_char = 0;
		}
		// tab��ǂ񂾂Ƃ�
		else if(c=='\t'){
			chr += tabstop - chr % tabstop;
			space += tabstop - chr % tabstop;
			state_char = 0;
		}
		// ���s��ǂ񂾂Ƃ�
		else if(c=='\n'){
			if(state_char==0){
				entab(chr, space, tabstop);
			}
			chr = 0;
			space = 0;
			state_char = 1;
			printf("%c", c);
		}
		// �t�@�C������
		else if(c==EOF){
			if(state_char==0){
				entab(chr, space, tabstop);
			}
			break;
		}
		// ������ǂ񂾂Ƃ�
		else{
			if(state_char==0){
				entab(chr, space, tabstop);
			}
			chr++;
			space = 0;
			printf("%c", c);
//			printf("%d", chr);
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
void entab(int chr, int space, int tabstop){
	int st; // �󔒊J�n���̍s�̕�����
	st = chr - space;
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
			space -= (tabstop-st%tabstop);
		}while(space>tabstop); // ���ڂ���̓^�u�X�g�b�v���c��X�y�[�X������Γ����
		while(space>0){ // �c��̓X�y�[�X�Ŗ��߂�
			printf(" ");
			spnum++;
			space--;
		}
	}
}

