#include <stdio.h>

#define MSDOS_

#ifdef MSDOS 
#pragma message("###################")
#else 
#pragma message("=========================")
#endif

int main(){
	printf("%s, Hello world\n", __FILE__);
	return 0;
}
