#include <stdio.h>
#define MAX 15
void bsort(int [],int);
void printme(int [],int);
int search(int [],int, int);
void swap(int *,int *);

main (){	
	int a[MAX] = {34,6,12,5,65,74,7,356,75,1,2,88,5,11,-9};
	printme(a,MAX);
	bsort(a,MAX);
	printme(a,MAX);	
	while (1){
		int n,f;
		printf ("enter number -1 to exit: ");
		scanf ("%d",&n);
		f = search(a,MAX,n);
		if (n == -1){
			break;
		}
		if (f == 0){
			printf ("not found %d\n", n);
		}else{
			printf ("found %d\n",n);
		}
	
	}
}

//running 
int search(int a[],int max, int num) {
	int i, found=0;
	for (i=0;i<max;i++){
         if (num == a[i]) {
         	found = 1;
         }
	}
	return found;
}

void printme(int xx[],int max){
	int i;
	for (i=0;i<max;i++){
		printf ("%d ",xx[i]);
	}
	printf ("\n");
}

//bubblesort max*max
void bsort(int x[], int max) {
	int i,j;
	//15*15=225 iterations
	for (i=0;i<max;i++){
		for (j=1;j<=max;j++){
			if (x[j] < x[j-1]){
				swap(&x[j], &x[j-1]);
			}
		 //printme(x,MAX);
		}
	}
}
void swap(int *a, int *b){
	int t;
	t =*a;
	*a =*b;
	*b = t;
	
}

