#include <stdio.h>
#define MAX 5

void ppp(int x[]){
  for (int i=0;i<MAX;i++) {
		printf ("%d ",x[i]);
	}
  printf ("\n");
}

void aaa() {
	printf ("Good morning\n");
	printf ("How are you\n");

}

int add3(int a, int b, int c) {
	int t = a + b + c;
	return t;
}

int add1(int a) {
	int z=a;
	z = (z*2)+6;
	return z;
}

int main () {
	int a[]={4,67,23,656,88};
	int b[]={2,32,11,222,54};
	aaa();
	ppp(a);
	ppp(b);
	ppp(a);
	aaa();

	int x=7,y=8,z=34;
	int p = add3(x,y,z);
	printf ("%d+%d+%d=%d\n",x,y,z,p);
	printf ("%d+%d+%d=%d\n",x,y,z,add3(x,y,z));
	printf ("%d+%d+%d=%d\n",34,78,89,add3(34,78,89));
	
	int aa = add1(2);
	printf ("%d %d\n", add1(2),aa);
	int aaa = add1(4);
	printf ("%d %d\n", add1(4),aaa);

}

