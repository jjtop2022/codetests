#include<stdio.h>
#include <string.h>
main (){
	char s[20]="morning";
	while (1){
		char input[20];
		printf ("Enter password: ");
		scanf("%s",input);
		if (strcmp(input,s) == 0) {
			printf ("success\n");
			break;
		}else{
			printf ("no match\n");
		}
	}
	printf ("continue playing\n");
}


