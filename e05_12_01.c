// detab�����s�ڂ���^�u�X�g�b�v�����œ��삳����
// �R�}���h���C����������+m -n�̌`�œ���
// ���{�ꂪ���������đ�ӕs��
#include<stdio.h>
#include<stdlib.h>

void detab(int, int);

int main(int argc, char *argv[]){
	int tablin=1;				// ���삷��s��(����l:1)
	int tabstop=4;			// �^�u�X�g�b�v����(����l:4)
	int inputchk;				// ���̓`�F�b�N
	int mchk=0;					// +m�̉񐔃`�F�b�N
	int nchk=0;					// -n�̉񐔃`�F�b�N
	
	// �����`�F�b�N
	if(argc==1){
		inputchk = 1;
	}
	else if(argc<=3){
		inputchk = 1;
		while(*++argv){
			if(**argv=='+'){
				tablin = atoi(*argv);
				mchk++;
			}
			else if(**argv=='-'){
				tabstop = -1 * atoi(*argv);
				nchk++;
			}
			// m, n��2��ȏ���͂���邱�Ƃ�h��
			if(mchk>1||nchk>1){
				inputchk = 0;
				break;
			}
		}
	}
	else{
		inputchk = 0;
	}
	printf("m: %d, n: %d\n\n", tablin, tabstop);
	
	// ����������Ă�����I��
	if(inputchk==0){
		printf("Usage: e05_12_01 +m -n\n");
		printf("m: line\n");
		printf("n: tabstop\n");
		return 0;
	}
	// ���������detab����
	else{
		detab(tablin, tabstop);
		return 0;
	}
}

void detab(int tablin, int tabstop){
	int lin=1; // �ǂݍ��ݍs��
	int spnum, chr=0, blanknum=0;
	char c;
	
	// ����
	while((c=getchar())!=EOF){
		// tab��ǂ񂾂Ƃ�
		if(c=='\t'){
			if(tablin<=lin){
				spnum = tabstop - chr % tabstop;
				while(spnum>0){
					printf(" ");
					blanknum++;
					spnum--;
				}
				chr = 0;
			}
			else{
				printf("%c", c);
				chr = 0;
			}
		}
		// ���s��ǂ񂾂Ƃ�
		else if(c=='\n'){
			lin++;
			chr = 0;
			printf("%c", c);
		}
		// ���̑���ǂ񂾂Ƃ�
		else{
			chr++;
			printf("%c", c);
		}
	}
	
	printf("/n/nblanknum : %d\n", blanknum);
}
