#include <stdio.h>

int main()
{
	int a = 1;
	printf("%d\n", a<<1); // 2 
	printf("%d\n", a<<2); // 4
	printf("%d\n", a<<3); // 8 
	printf("%d\n", a<<4); // 16

	int b = 16;
	printf("%d\n", b>>1); // 8 
	printf("%d\n", b>>2); // 4
	printf("%d\n", b>>3); // 2 
	printf("%d\n", b>>4); // 1
	return 0;
}