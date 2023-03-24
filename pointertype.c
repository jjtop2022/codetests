#include <stdio.h>
main (){
	int *p[4];
	int *(s[4]);
	int (*f)[4];
	int a=7;
	p[0]=&a;
	printf ("%d\n",*p[0]);
	s[0]=&a;
	printf ("%d\n", *s[0]);
	*f[0]=5;
	*f[1]=6;
	*f[0] = a;
	printf ("%d %d\n",*f[0],*f[1]);
	
}
