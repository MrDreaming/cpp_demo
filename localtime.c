#include <stdio.h>
#include<time.h>

void printTime1();
void printTime2();

int main()
{
	printTime1();
	printTime2();
	return 0; 
}

void printTime1(){
	time_t timep;
	time (&timep);
	// TIME1 = Thu May 18 14:50:47 2017
	printf("TIME1 = %s",ctime(&timep)); 
}

void printTime2(){
	time_t t; 
	struct tm * a; 
	time(&t); 
	a=localtime(&t); 
	// TIME2 = 2017-05-18 14:50:47
	printf("TIME2 = %4d-%02d-%02d %02d:%02d:%02d\n",
		1900+a->tm_year,1+a->tm_mon,a->tm_mday,
		a->tm_hour,a->tm_min,a->tm_sec); 
}

