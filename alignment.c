#include <stdio.h>

struct Bad {
	char a;
	int b;
	char c;
};

struct Good {
	int a;
	char b;
	char c;
};

void foo(int arr[]) {
	printf("Inside foo (sizeof pointer): %lu\n", sizeof(arr)); 
}

int main() 
{
	int arr[10];
	char *ptr = "hello";
	char str[] = "hello";

	//ptr[1] = 'a'; //(why error!!?)
	str[1] = 'a';
	printf("Size of Bad structure: %zu\n", sizeof(struct Bad));
	printf("Size of Good structure: %zu\n", sizeof(struct Good));

	printf("Size of str: %ld\n", sizeof(str));
	printf("Size of ptr: %ld\n", sizeof(ptr));

	printf("Inside main (sizeof array): %lu\n", sizeof(arr));

	foo(arr);

	return 0;
}