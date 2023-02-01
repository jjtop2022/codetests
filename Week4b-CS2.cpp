#include <iostream>
using namespace std;
#include <string> //std::string

template<typename tt>
void printout(tt b[]) {
	for (int i=0;i<5;i++) {
		cout << b[i] << " ";
	}cout << endl;
}

template<class T>
T ppp(T a) {
	T t= a*a;
	return t;
}

template<class T, class T1>
T addme(T a, T1 b) {
	T temp = a + b;
	return temp;
}


double www(double a) {
	double t = a*a;
	return t;
}

int main () {
	int a[]={4,6,74,67,788};
	double b[]={2.3,8.9,78.55,1.22,5.77};
	char *c[]={"aa","qqq","ccc","dd","fff"};
	char d[]="goods";
	printout(a);
	printout(b);
	printout(c);
	printout(d);

	int i=8;
	int k = ppp(i);
	cout << ppp(i) << " " << k << endl;
	double ii=8.8; double j=ppp(ii);
	cout << ppp(ii) << " " << j << endl;

	double iii=8.9;
	char ccc='A';
	cout << addme(iii,i) << endl;
	cout << addme(i,iii) << endl;
	cout << addme(ccc,3) << endl;
	cout << addme(3,ccc) << endl;
	cout << ccc << " " <<(int)ccc <<endl;

}

