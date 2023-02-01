#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define MAX 8

template<typename tt>
void printout(tt a[]) {
    cout << std::setiosflags(ios::left);
	for (int i=0;i<MAX;i++) {
		cout << setw(7) << a[i];
	}cout << endl;
}

template <class T>
void swapme(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename TT>
void sortme(TT a[]) {
	for (int i=0;i<MAX;i++) {
		for (int j=1;j<MAX;j++) {
			if (a[j-1] < a[j]) {
				//TT temp = a[j-1];
				//a[j-1] = a[j];
				//a[j] = temp;
				swapme(a[j-1], a[j]);
			}
		}
	}
}


void swapme2(char *a[], int i, int j) {
	char *temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void sortme2(char *a[]) {
	for (int i=0;i<MAX;i++) {
		for (int j=1;j<MAX;j++) {
			if (strcmp(a[j-1],a[j]) < 0) {
				char *temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
				//swapme2(a,i,j);
			}
		}
	}
}


int main () {
	int a[]={45,233,122,90,543,989,54,666};
	float b[] = {2.3,1.2,89.6,6.78,.2,31.2,12.8,20.09};
	char c[]="doggiesa";
	string d[]={"eat","dog","cat","egg","horse","rabbit","web","ant"};
    char *e[]={"eat","dog","cat","egg","horse","rabbit","web","ant"};
	
	cout << "unsorted: " << endl;
	printout(a);
	printout(b);
	printout(c);
	printout(d);
	printout(e);

	sortme(a);
	sortme(b);
	sortme(c);
	sortme(d);
	sortme2(e);
	
	cout << "sorted: "<< endl;
	printout(a);
	printout(b);
	printout(c);
	printout(d);
	printout(e);


}
