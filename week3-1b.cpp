#include <stdio.h>

int main () {
	//1.
	char n[20];
	int a;
	//2. 
	printf ("Type your name: ");
	scanf("%s", n);
	printf ("Enter age: ");
	scanf("%d", &a);
	//3.
	printf ("Your name: %s , your age: %d\n", n,a);

}
