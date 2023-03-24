#include <stdio.h>
#define QUIT 9999

int main () {

	for (;;) {
		int a, b, c,d,e;
		double f;
		printf ("Enter first number: ");
		scanf("%d", &a);
		if (a == QUIT){
			break;
		}
		printf ("Enter second number: ");
		scanf("%d", &b);
		c = a + b;
		d = a - b;
		e = a * b;
		f = (double)a / (double)b;
		printf ("%d+%d=%d\n",a,b,c);
		printf ("%d-%d=%d\n",a,b,d);
		printf ("%d*%d=%d\n",a,b,e);
		printf ("%d/%d=%f\n",a,b,f);

	}
}
