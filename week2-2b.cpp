#include <stdio.h>

int main () {
	int a=7;
	float b=8.8;
	double c=5.76;
	int dd[10]={2,45,67,89};
	printf ("%d %.1f %.2f\n",a,b,c);
	printf ("%d %d %d %d\n", dd[0],dd[1],dd[2],dd[3]);
	for(int i=0;i<4;i++) {
		printf ("%d ",dd[i]);
	} printf ("\n");
	////////////////////////
	char n='W';
	printf ("%c\n", n);
	char m[30]="good morning";
	printf ("%s\n", m);
	m[0]='G';
	printf ("%s\n", m);
	for (int i=0;i<13;i++) {
		printf ("%c",m[i]);
	} printf ("\n");



}

