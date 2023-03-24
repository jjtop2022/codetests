#include <stdio.h>
#include <string.h>

int main () {
	//1. strcpy, strncpy -
	char n[10]="hello";
	char m[40]="";
	printf ("%s %s\n",n,m);
	strcpy(m,n);
	printf ("%s %s\n",n,m);
	
	//////////2. strcat - 
	char y[20]=" morning";
	char x[50]="good";
	strcat(x,y);
	printf ("%s\n", x);
	strcat(x," everyone");
	printf ("%s\n", x);

	////3. strlen -
	int d = strlen(x);
    printf ("x length: %d %d\n", d, strlen(x));
	printf ("length of aaaa: %d\n", strlen("aaaa"));

	////4. //strcmp, 
	char q[]="Jack";
	char name[10];
	printf ("Enter name: ");
	scanf ("%s", name);
	if (strcmp(name,q) == 0) {
		printf ("Your name Jack\n");
	
	}else{
		printf ("NOT Bill\n");
	}
	
}
