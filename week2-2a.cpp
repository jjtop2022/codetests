#include <stdio.h>

int main () {
	int a[]={3,4,65,78,88};
	for (int i=0;i<5;i++) {
		printf ("%d ", a[i]);
	} printf ("\n");
	for (int i=4;i>=0;i--) {
		printf ("%d ",a[i]);
	} printf ("\n");
	///////////////////////
	//for (;;) {
	//	printf ("hi ");
	//}
	int j=0;
	while(j<5){
		printf ("%d ",a[j]);
	    j=j+1;
	}printf ("\n");
	j=4;
	while(j >= 0) {
		printf ("%d ",a[j]);
		j = j -1;
	} printf ("\n");





}

