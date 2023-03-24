#include <stdio.h>
#include <string.h>

int main () {
	int i=6, j;
	j =i;
	printf ("%d %d\n",i,j);
	char c='N';
	char d;
	d = c;
	printf ("%c %c\n",c,d);

	//1. strcpy, strncpy - string copy
	char n[]="hhhh";
	char m[10]="";
	strcpy(m,n);
	printf ("%s %s\n",n,m);
	strcpy(m,"good");
	printf ("%s %s\n",n,m);
	strncpy(m,"aa",1);
	printf ("%s %s\n",n,m);
	//2. strcat strncat - string concantenate
	char x[50]="good ";
	char y[10]="morning";
	strcat(x,y);
	printf ("%s\n",x);
	strcat(x," everybody");
	printf ("%s\n",x);
	strncat(x," now",2);
	printf ("%s\n",x);
	//3. string length - strlen
	int g = strlen(x);
	if (g >= 20) {
		printf ("too long\n");
	}else{
		printf ("ok\n");
	}
	printf ("length: %d %d: %s\n", strlen(x), g, x);
	//4. string compare - strcmp, strncmp
	char q[]="quit";
	char name[20]="";
    printf ("Enter name: ");
	scanf ("%s",name);
	if (strcmp(name,q) == 0) {
		printf ("NAME is: %s\n",name);
	}else{
		printf ("not quit\n");
	}
	/// strncmp
	if (strncmp(name,q,2) == 0) {
		printf ("NAME is: %s\n",name);
	}else{
		printf ("not quit\n");
	}





	




}
