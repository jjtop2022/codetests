#include <iostream>
using namespace std;

int main () {
	int i=8, j=9;
	int a[]={3,4,56,89,900};
	int *p;
    p = &i;
	cout << *p << " " << i << " " << j <<endl;
	*p = 56;
	cout << *p << " " << i << " " << j <<endl;
	p = &j;
	*p = 90;
	cout << *p << " " << i << " " << j <<endl;
	p = &a[1];
	cout << *p <<  endl;
	*p++;
	cout << *p <<  endl;
	cout << *p << " "<< *(p+1) << " " << *(p+2) << endl;
	cout << *p << endl;
	*p = 67;
	for (int i=0;i<5;i++) {
		cout << a[i] << " ";
	}cout << endl;
	p = a;
	*p = 11;
	for (int i=0;i<5;i++) {
		cout << a[i] << " ";
	}cout << endl;
	cout << *p << " "<< *(p+1) << " " << *(p+2) << " "<< *(p+3) << endl;
	p = p +1;
	cout << *p << " "<< *(p+1) << " " << *(p+2) << " "<< *(p+3) << endl;
	*p = *p +2;
	cout << *p << " "<< *(p+1) << " " << *(p+2) << " "<< *(p+3) << endl;
	cout << p << " " << &a[1] << endl;
	cout << *p << " " << a[1] << endl;

}
