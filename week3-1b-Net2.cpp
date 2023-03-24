#include <stdio.h>

int main () {
	char name[20];
	int age;
	//1. 
	for (;;) {
		printf ("Enter name: ");
		scanf("%s", name);
		printf ("Enter age: ");
		scanf("%d", &age);
		if (age == 999) {
			break; 
		}
		//2.
		printf ("Name: %s Age: %d\n", name,age);
	}
}