#include <iostream>
#include <limits.h>
using namespace std;

int main () {
	long i=56890;
	unsigned long j=56890;
	cout << i << " " << j << endl;

	short k=-890; 
    unsigned short l=-890;
	
	cout << k << " " << l << endl;
	signed short n=56890; 
    unsigned short m=56890;
	cout << n << " " << m << endl;

	char cc='*';
	char dd='K';
	double ddd=34534543573;
	float  fff=34534543573;
	cout << ddd << " " << fff << endl;
	printf ("%lf %lf\n",ddd,fff);

	cout << SHRT_MIN << " " << SHRT_MAX << endl;
	cout << USHRT_MAX << endl;
	cout << LONG_MIN << " " << LONG_MAX << endl;
	cout << INT_MIN << " " << INT_MAX << endl;
	cout << ULONG_MAX << " " << UINT_MAX << endl;
	cout << CHAR_MIN << " " << CHAR_MAX << endl;
	cout << UCHAR_MAX << endl;
	cout << FLT_MAX << " " << DBL_MAX << endl;
	cout << FLT_MIN << " " << DBL_MIN << endl;
	printf ("%lf %lf %lf\n",FLT_MIN,FLT_MAX, DBL_MAX);

}
