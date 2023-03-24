#include <stdio.h>
#define MAX 7
#define MAX2 15


int main () {
		
	///////////////////////////////////
	int d[MAX2+1][MAX+1]={}; // *
	int e[MAX2+1][MAX+1]={};  //+

	///////////////////////////////////
	///1.* input //////////////////////////
	for (int i=1;i<=MAX2;i++) {
		for (int j=1;j<=MAX;j++) {
			d[i][j] = i*j;
		}
	}

	///2. *output///////////////////////////
	printf ("\n");
	for(int i=1;i<=MAX2;i++) {
		for(int j=1;j<=MAX;j++) {
			printf ("%d*%d=%d ",i,j,d[i][j]);
		}
		printf ("\n");
	}
	////1. + input//////////////////////////
	for (int i=1;i<=MAX2;i++) {
		for (int j=1;j<=MAX;j++) {
			e[i][j] = i+j;
		}
	}
	/////2. + output ///////////////////////
	printf ("\n");
	for(int i=1;i<=MAX2;i++) {
		for(int j=1;j<=MAX;j++) {
			printf ("%d+%d=%d ",i,j,e[i][j]);
		}
		printf ("\n");
	}


}
