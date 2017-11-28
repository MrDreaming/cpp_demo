#include<stdio.h>
#include<stdlib.h>
// 64bit Ubuntu
int main(){
	printf("%02ld ", sizeof(char)); // 01
	printf("%02ld ", sizeof(short));	// 02
	printf("%02ld ", sizeof(int)); // 04
	printf("%02ld ", sizeof(short int)); // 02 
	printf("%02ld ", sizeof(long int)); // 08
	printf("%02ld ", sizeof(long)); // 08 
	printf("%02ld ", sizeof(float)); // 04
	printf("%02ld ", sizeof(long long)); // 08 
	printf("%02ld \n", sizeof(long double)); // 16
	printf("---------------\n");
	printf("%02ld ", sizeof(int)); // 04
	printf("%02ld ", sizeof(short int)); // 02
	printf("%02ld ", sizeof(long int)); // 08
	printf("\n");
	printf("---------------\n");
	printf("%02ld ", sizeof(short)); // 02
	printf("%02ld ", sizeof(int)); // 04
	printf("%02ld ", sizeof(double)); // 08
	printf("\n");
	printf("---------------\n");
	printf("%02ld ", sizeof(long)); // 08
	printf("%02ld ", sizeof(unsigned long)); // 08
	printf("%02ld ", sizeof(int)); // 04
	printf("%02ld ", sizeof(unsigned int)); // 04
	printf("\n");
	printf("wchar_t = %02ld \n", sizeof(wchar_t)); // wchar_t = 04
	printf("char = %02ld \n", sizeof(char)); // char = 01
	return 0;
}