#include <stdio.h>
#define MAX 10

void printme(int a[]) {
	for (int i=0;i<MAX;i++) {
		printf ("%d ",a[i]);
	}
	printf("\n");
}

void swapme(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;

}

void sort(int a[]) {
	for (int i=0;i<MAX;i++) {
		for (int j=1;j<MAX;j++) {
			if (a[j-1] > a[j]) {
				int t = a[j-1];
				a[j-1] = a[j];
				a[j] = t;
				//swapme(&a[j-1],&a[j]);
			}
		  //printme(a);
		}
	}

}

int main () {
	int a[]={34,2,1,88,9,101,5,77,3,10};
	printf ("Unsorted: ");
    printme(a);
	
	sort(a);
	printf ("Sorted: ");
	printme(a);

}
