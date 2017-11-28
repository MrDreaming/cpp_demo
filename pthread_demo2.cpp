#include<stdio.h>
#include<pthread.h>
#include<string.h>
// // g++ pthread_demo2.cpp -lpthread
struct test{
int no;
char name[80];
};

void pfunc ( void *data){
	struct test* tt = (struct test*)data;
	printf("%d\n", tt->no); // 100
	printf("%s\n", tt->name); // Hello
}

int main(){
	struct test itest;
	pthread_t th;

	itest.no=100;
	strcpy(itest.name,"Hello");
	pthread_create( &th, NULL,(void* (*)(void*))pfunc, &itest );
	pthread_join(th,NULL);
	return 0;
}