#include <stdio.h>
#define MAX 5

void ppp(int x[]){
  for (int i=0;i<MAX;i++) {
		printf ("%d ",x[i]);
	}
  printf ("\n");
}

int main () {
	int a[]={45,2,1,56,99};
	float b[]={1.2,3.6,7.6,8.5,9.4};
	char c[]="haass";
	ppp(a);

	for (int i=0;i<MAX;i++) {
		printf ("%.1f ",b[i]);
	}
    printf ("\n");
	for (int i=0;i<MAX;i++) {
		printf ("%c ",c[i]);
	}
    printf ("\n");

	for (int i=MAX-1;i>=0;i--) {
		printf ("%.1f ",b[i]);
	}
    printf ("\n");
	for (int i=MAX-1;i>=0;i--) {
		printf ("%c ",c[i]);
	}
    printf ("\n");

}