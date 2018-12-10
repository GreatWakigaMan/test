// tab�𔼊p�X�y�[�X�ɂ���
// �����Ń^�u�X�g�b�v���������
#include<stdio.h>
#include<stdlib.h>

void detab(int);

int main(int argc, char *argv[]){
	int tabstop;
	
	// �����`�F�b�N
	if(argc==1){
		tabstop = 4;
	}
	else if(argc==2){
		tabstop = atoi(argv[1]);
		if(tabstop<1){
			printf("Usage: e05_11_01 tabstop\n");
			return 0;
		}
	}
	else{
		printf("Usage: e05_11_01 tabstop\n");
		return 0;
	}
	
	detab(tabstop);
	
	return 0;
}

void detab(int tabstop){
	int spnum, lin=0, blanknum=0;
	char c;
	
	// ����
	while((c=getchar())!=EOF){
		// tab��ǂ񂾂Ƃ�
		if(c=='\t'){
			spnum = tabstop - lin % tabstop;
			while(spnum>0){
				printf(" ");
				blanknum++;
				spnum--;
			}
			lin = 0;
		}
		// ���s��ǂ񂾂Ƃ�
		else if(c=='\n'){
			lin = 0;
			printf("%c", c);
		}
		// ���̑���ǂ񂾂Ƃ�
		else{
			lin++;
			printf("%c", c);
		}
	}
	
	printf("\n\n");
	printf("blanknum : %d\n", blanknum);
}
