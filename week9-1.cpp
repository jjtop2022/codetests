#include <stdio.h>
#include <stdlib.h>
#define MAX 12
#define QUIT 9999

void prints(int a[]) {
    for (int i=0;i<MAX;i++) {
		printf ("%d ",a[i]);
	} printf ("\n");
}

int search (int a[], int num) {
	int found=0;
	for (int i=0;i<MAX;i++){
		if (a[i] == num) {
			found = 1;
		}
	} 
	return found;
}


int main () {
	int a[]={111,122,123,135,145,166,188,199,211,222};
	prints(a);

	while(1) {
		char num2[20];
		printf ("Enter a number: ");
		scanf("%s", num2);

		int num = atoi(num2);

		if (num == QUIT) {
			printf ("Finished\n");
			break;
		}

		int f = search(a,num);

		if (f == 1) {
			printf ("Number: %d is FOUND\n",num);
		}else{
			printf ("Number: %d is NOT FOUND\n",num);
		}
	}

}