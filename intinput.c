#include <stdio.h>

main () {
	int input;
	char c;
	while (scanf("%d",&input) != 1){
		 while ((c=getchar()) != '\n') {
 			putchar(c);
 		}
		printf ("\nNot integer,enter integer again!\n");
		
	}
	printf ("You entered %d\n",input);
}
