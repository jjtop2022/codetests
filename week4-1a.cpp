#include <stdio.h>
#include <string.h>
#define QUIT 999
#define NQUIT "quit"

int main () {

	while (true) {
		char name[20];
		int age;
		printf ("Enter name: ");
		scanf("%s", name);
		printf ("Enter age: ");
		scanf("%d", &age);
		if ((age == QUIT) && (strcmp(name,NQUIT) == 0)) {
			break;
		}
		
		printf ("Name: %s, age: %d\n",name,age);
	}




}