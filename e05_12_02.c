// entab�����s�ڂ���^�u�X�g�b�v�����œ��삳����
// �R�}���h���C����������+m -n�̌`�œ���
// ���{�ꂪ���������đ�ӕs��
#include<stdio.h>
#include<stdlib.h>

int tabnum = 0;
int spnum = 0;
void entab(int, int, int);

int main(int argc, char *argv[]){
	int tablin=1;				// ���삷��s��(����l:1)
	int tabstop=4;			// �^�u�X�g�b�v����(����l:4)
	int inputchk;				// ���̓`�F�b�N
	int mchk=0;					// +m�̉񐔃`�F�b�N
	int nchk=0;					// -n�̉񐔃`�F�b�N
	int chr=0;					// �s�̕�����
	int space=0;				// �󔒕�����
	int state_char=1;		// 0:�� 1:������
	int lin=1;					// �ǂݍ��ݍs��
	char c;
	
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
			else{
				inputchk = 0;
				break;
			}
			// m, n��2��ȏ���͂���邱�Ƃ�h��
			if(mchk>1||nchk>1){
				inputchk = 0;
				break;
			}
			// �����~�X��e��
			if(tablin==0 || tabstop==0){
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
		while(1){
			c=getchar();
			if(c==' '){
				chr++;
				space++;
				state_char = 0;
			}
			// tab��ǂ񂾂Ƃ�
			else if(c=='\t'){
				if(tablin>lin){
					printf("%c", c);
				}
				chr += tabstop - chr % tabstop;
				space += tabstop - chr % tabstop;
				state_char = 0;
			}
			// ���s��ǂ񂾂Ƃ�
			else if(c=='\n'){
				if(tablin<=lin){
					if(state_char==0){
						entab(chr, space, tabstop);
					}
				}
				lin++;
				chr = 0;
				space = 0;
				state_char = 1;
				printf("%c", c);
			}
			// �t�@�C������
			else if(c==EOF){
				if(tablin<=lin){
					if(state_char==0){
						entab(chr, space, tabstop);
					}
				}
				break;
			}
			// ������ǂ񂾂Ƃ�
			else{
				if(tablin<=lin){
					if(state_char==0){
						entab(chr, space, tabstop);
					}
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

