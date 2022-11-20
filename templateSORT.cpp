#include <iostream>
using namespace std;
#define MAX 5

template <class T>
void printme(T a[]) {
	for (int i=0; i<MAX; i++)
		 cout << a[i] << " ";
	cout << endl;
}

template <class T>
void swap(T *a, T *b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <class T>
void sort (T a[]){
	for (int i=0; i<MAX;i++) {
		for (int j=1; j<MAX; j++) {
			if (a[j-1] > a[j])
				swap(&a[j-1],&a[j]);
		}
	}
}


void main () {
	int a[] = {20,3,4,6,88};
	float b[] = {343.3,5.7,8.7,6.3,90.78};
	double d[] = {1111.233,2.343343,5.343433,12.2221111,11.11111111};
	char c[] = "HELLOME";
	printme(a);
	printme(b);
	printme(c);
	printme(d);
	cout << "sorted: " <<endl;
	sort (a);
	sort (b);
	sort (c);
	sort (d);
	printme(a);
	printme(b);
	printme(c);
	printme(d);
}


