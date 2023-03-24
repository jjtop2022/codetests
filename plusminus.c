#include <stdio.h>
main () {
	int a=6;
	int d = a+=a-=a*a;
	a=6;
	int b = a+=a;
	a=6;
	int c = a-=a;
	
	printf ("%d %d %d\n",d,b,c);
	
}
