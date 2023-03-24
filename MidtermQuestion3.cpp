#include <stdio.h>
#define MAX 6
#define MAX2 10

int main () {
	int a[MAX2+1][MAX+1] = {}; //*
	int b[MAX2+1][MAX+1] = {}; //+

	// * input  ‰»Î
	for (int i=1;i<=MAX2;i++) {
		for (int j=1;j<=MAX;j++) {
			a[i][j] = i *j;
		}
	}
	//output shuchu
	for (int i=1;i<=MAX2;i++) {
		for (int j=1;j<=MAX;j++) {
			printf ("%d*%d=%d ",i,j,a[i][j]);
		}
		printf ("\n");
	}
	printf ("\n");
	// +
	for (int i=1;i<=MAX2;i++) {
		for (int j=1;j<=MAX;j++) {
			a[i][j] = i +j;
		}
	}
	//output shuchu
	for (int i=1;i<=MAX2;i++) {
		for (int j=1;j<=MAX;j++) {
			printf ("%d+%d=%d ",i,j,a[i][j]);
		}
		printf ("\n");
	}




}