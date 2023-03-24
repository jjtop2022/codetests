#include <stdio.h>

int main() {
	printf ("hello world\n");
	printf ("hello world2\n");

	int a=896;
	int b=700;
	int c = a+b;
	printf("%d\n",a);
	printf ("%d+%d=%d\n",a,b,c);
	c = c - 200;
	printf ("%d\n", c);
	c = c * 2;
	printf ("%d\n", c);
	c = (c + a) - b;
	printf ("%d\n", c);

	float d=5.678;
	printf ("%.3f\n", d);
	float e=3.14;
	float f= d+e;
	printf ("%.2f %.3f\n",e,f);

}

