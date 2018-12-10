#include<stdio.h>

static char daytab[][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int, int, int);
int month_day(int, int, int *, int *);

int main(void){
	int y1, d1, m1, s1;
	y1 = 1988;
	m1 = 3;
	d1 = 20;
	printf("--------day_of_year--------\n");
	s1 = day_of_year(y1, m1, d1);
	if(s1!=-1){
		printf("%d/%d/%d : %d日目\n", y1, m1, d1, s1);
	}
	else{
		printf("Invalid date.\n");
	}

	
	int y2, d2, m2, s2, chk;
	y2 = 1988;
	s2 = 180;
	printf("\n--------month_day--------\n");
	chk = month_day(y2, s2, &m2, &d2);
	if(chk!=-1){
		printf("%d年%d日目 : %d/%d\n", y2, s2, m2, d2);
	}
	else{
		printf("Invalid date.\n");
	}
}

int day_of_year(int year, int month, int day){
	int i, frac, leap;
	// 年月日の下限チェック
	if(year<0 || month<1 || day<1){
		return -1;
	}
	
	// 31日で終わる月チェック
	switch(month){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		frac = 1;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		frac = 0;
		break;
	}

	if(day>30+frac){
		return -1;
	}
	
	leap = ((year%4==0 && year%100!=0) || year%400==0); // うるう年か否か？
	
	// 二月のチェック
	if(month==2 && day>28+leap){
		return -1;
	}
	
	for(i=1; i<month; i++){
		day += daytab[leap][i];
	}
	return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday){
	int i, leap;
	// 年と日数の下限チェック
	if(year<0 || yearday<1){
		return -1;
	}
	
	leap = ((year%4==0 && year%100!=0) || year%400==0); // うるう年か否か？
	if(yearday>365+leap){
		return -1;
	}
	
	for(i=1; yearday>daytab[leap][i]; i++){
		yearday -= daytab[leap][i];
	}
	*pmonth = i;
	*pday = yearday;
}
