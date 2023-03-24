#include <stdio.h>
#include <string.h>

int main () {
	//1. strcpy, strncpy - string copy
	int i=67, j;
	j = i;
	printf ("%d %d\n", i, j);
	char a='a';
	char b;
	b = a;
	printf ("%c %c\n", a,b);
	char n[10]="hello";
	char m[40]="";
	strcpy(m,n);
	printf ("%s %s\n",n,m);
	strcpy(m,"**************");
	printf ("%s %s\n",n,m);
	strncpy(m,"aaa",3);
	printf ("%s %s\n",n,m);

	//////////2. strcat - string concantenate
	char y[20]=" morning";
	char x[50]="good";
	strcat(x,y);
	printf ("%s\n", x);
	strcat(x," everyone");
	printf ("%s\n", x);
	strncat(x," how are",2);
	printf ("%s\n", x);

	////3. strlen -string length 
	int d = strlen(y);
    printf ("x length: %d %d\n", d, strlen(x));
	printf ("length of aaaa: %d\n", strlen("aaaa"));
	if (strlen(x) <= 20) {
		printf ("under 20 \n");
	}else
		printf ("over 20\n");

	////4. //strcmp, strncmp - string compare //////////
	char q[]="quit";
	char name[20];
	printf ("Enter name: ");
	scanf ("%s", name);
	if (strcmp(name,q) == 0) {
		printf ("Your name: quit\n");
	
	}else{
		printf ("NOT QUIT\n");
	}
	///strncmp
	if (strncmp(name,q,3) == 0) {
		printf ("Your name: quit\n");
	
	}else{
		printf ("NOT QUIT\n");
	}
}
