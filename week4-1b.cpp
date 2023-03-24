#include <stdio.h>
#include <string.h>
#define QUIT 999
#define NQUIT "quit"

int main () {

	for (;;) {
		int age;
		printf ("enter age: ");
		scanf ("%d", &age);
		if (age == QUIT) {	
			break;
		}
		
		if (age >= 0 && age < 7) {
			printf ("young child\n");
		}else if (age >= 7 && age <= 14) {
			printf ("teenage kids\n");
		}else if (age > 14 && age <= 30) {
			printf ("young person\n");
		}else if (age > 30 && age <= 60) {
			printf ("middle age person\n");
		}else if (age > 60 && age <= 110) {
			printf ("senior citizen\n");
		}else {
			printf ("Invalid\n");
		}
		
	}
	 printf ("program quit\n");
}

