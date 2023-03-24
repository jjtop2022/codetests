#include <stdio.h>

int main () {
	int x=89;
	float y=23.897;
	int a[]={2,4,56,78,5,12,4,90};
	
	printf ("%d\n", x);
	printf ("%.2f\n", 100.87);
	printf ("%.3f\n", y);
    printf ("%d %d %d %d %d\n", a[0],a[1],a[2],a[3],a[4]);
	for (int i=0;i<8;i++) {
		printf ("%d ",a[i]);
	} printf ("\n");
	////////////////////////////////
	int i=1;
	printf ("%d\n", i);
	i = i+1;
	printf ("%d\n", i);
	i++;
	printf ("%d\n", i);
	i += 1;
	printf ("%d\n", i);
	i = i +3;
	printf ("%d\n", i);
	i += 3;
	printf ("%d\n", i);
	i--;
	printf ("%d\n", i);
	i = i - 1;
	printf ("%d\n", i);
	i -= 1;
	printf ("%d\n", i);
	i = i *2;
	printf ("%d\n", i);
	i *= 2;
	printf ("%d\n", i);
	i /= 2;
	printf ("%d\n", i);
    printf ("%d\n", i++);
	 printf ("%d\n", i);
	 printf ("%d\n", ++i);
	 printf ("%d\n", i--);
	 printf ("%d\n", --i);
	 printf ("%d\n", i+=1);



}



