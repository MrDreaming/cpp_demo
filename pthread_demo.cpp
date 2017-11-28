#include<stdio.h>
#include<pthread.h>
#include<string.h>
// g++ pthread_demo.cpp -lpthread
struct test{
	int no;
	char name[80];
};

class Student{
	public:
		struct test itest;

	public:

	static void pfunc ( void *data)
	{
		struct test* tt = (struct test*)data;
		printf("%d\n", tt->no); // 100
		printf("%s\n", tt->name); // Hello
	}

	void test(){
		pthread_t th;
		itest.no=100;
		strcpy(itest.name,"Hello");
		pthread_create( &th, NULL,(void* (*)(void*))(Student::pfunc), &itest);
		pthread_join(th,NULL);
	}

};

int main()
{
	Student stu;
	stu.test();
	return 0;
}