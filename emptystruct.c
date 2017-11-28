#include <stdio.h>

struct osip_thread;

int main(){
	struct osip_thread* pdemoThread; // no error , no warming
	struct osip_thread demoThread; // error: storage size of ¡®demoThread¡¯ isn¡¯t known
	printf("Test empty struct\n");
	return 0;
}
