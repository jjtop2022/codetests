#include <stdio.h>
#include <string.h>
#define QUIT 9999

int main () {
	while (true) {
		char n[20];
		int a;
		//2. 
		printf ("Type your name: ");
		scanf("%s", n);
		printf ("Enter age: ");
		scanf("%d", &a);
		if ((strcmp(n,"quit") == 0) || a == QUIT) {
			break;
		}
		
		//3.
		printf ("Your name: %s , your age: %d\n", n,a);
	}
}

