#include <stdio.h>
#include <stdarg.h>

int debug_print(int level, const char * format, ...) {
	va_list arg;
	va_start(arg, format);
	char string[256];
	vsprintf(string,format,arg);
	printf("%s", string);
	va_end(arg);
}

int main(){
	debug_print(1, "Hello World, %d, %s, %d, %s, %s\n", 888, "test", 666, __FILE__, __FUNCTION__);
	// Hello World, 888, test, 666, va_list_demo.c, main
	return 0;
}
