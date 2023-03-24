#include <stdio.h>
#include <string.h>
int factorial(int);
main () {
	char s[20]="heel ";
	char m[]="world";
	int i;
	strcat(s,m);
	i = strlen(s);
	printf ("%s %d\n",s,i);
    i = factorial(6);
    printf ("6! =%d\n",i);
    int j = factorial2(6);
    printf ("6! = %d\n",j);
}
int factorial(int n){
	if (n != 1)
	  return n*factorial(n-1);
}

int factorial2(int n) {
	int i,f=1;
	for (i=1;i<=n;i++){
		f=f*i;
	}
	return f;
}

