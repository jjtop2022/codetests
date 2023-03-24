#include <stdio.h>
#include <limits.h>
#include <float.h>

int main () {
	long i=7;
	short j=78;
	printf ("%d %d\n", i, j);
	short k=68800;
	long n=68800;
	printf ("%d %d\n",k, n);
	signed short m=68800;
	unsigned long nn=68800;
	printf ("%d %d\n",m,nn);
	unsigned short b=-678;
	short c=-678;
	printf ("%d %d\n", b,c);
	unsigned short d=46500;
	short e=46500;
	printf ("%d %d\n",d,e);
	char z='K';
	unsigned char v='K';
	printf ("%c %c\n", z, v);
	int t=3149009009;
	printf ("%d %u\n", t,t);
	double p=89887667862;
	printf ("%.0lf %lf\n",p,p);


	printf ("Largest char: %d\n",CHAR_MAX);
	printf ("Smallest char %d\n",CHAR_MIN);
	printf ("unsigned largest %d\n",UCHAR_MAX);

	printf ("Largest signed short: %d\n", SHRT_MAX);
	printf ("Largest unsignedshort: %d\n", USHRT_MAX);
	printf ("smallest signed short: %d\n", SHRT_MIN);

	printf ("Largest signed int(long): %d\n", INT_MAX);
	printf ("Largest unsigned int(long): %u\n", UINT_MAX);
	printf ("smallest signed int(long): %d\n", INT_MIN);

	printf ("Largest float max: %f\n", FLT_MAX);
	printf ("Smallest float min: %f\n",FLT_MIN);
	printf ("Largest double max: %lf\n", DBL_MAX);
	printf ("Smallest double min: %lf\n",DBL_MIN);

}