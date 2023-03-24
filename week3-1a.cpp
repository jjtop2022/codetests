#include <stdio.h>

int main () {
	int i=0;
	while (i < 10) {
		printf ("%d\n", i);
		i = i+1;
	}
	for (int i=0;i<10;i++){
		printf ("%d\n",i);
	}
	i=59;
	float ii=56.44;
	double j=4.544;
	printf ("%.2f\n", ii);
	printf ("%.3f\n", j);
	char n='$';
	printf ("%c\n", n);
	char m[]="good morning";
	printf ("%s\n", m);
	int y[]={3,4,56,78,90};
	for (int i=0;i<5;i++) {
		printf ("%d ",y[i]);
	}printf ("\n");
	printf ("%d %d %d %d %d\n",y[0],y[1],y[2],y[3],y[4]);


}
