#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#define MAX 8
#define QUIT 999

void printout (int a[]) {
	cout <<setiosflags(ios::left);
   for (int i=0;i<MAX;i++) {
		cout << setw(7)<<a[i];
	}
	cout << endl;
}

int search(int a[], int num) {
	int found=0;
	for (int i=0;i<MAX;i++) {
		if (a[i] == num) {
			found = 1;
		}
	}
	return found;
}

void results(int f, int num) {
	if (f == 1) {
		cout << "your number "<<num<<" is found"<<endl;
	}else{
		cout << "your number "<<num<<" is not found"<<endl;
	}
}


int main () {
	int a[]={324,1212,333,655,876,344,121,222};
	printout(a);

	for (;;) {
		int num;
		char num2[10];
		cout << "enter number: ";
		cin >> num2;

		num = atoi(num2);
		if (num == 0) {
			cout << "Error numbers only!"<<endl;
		}

		if (num == QUIT) {
			cout << "program quit"<<endl;
			break;
		}

		int f = search(a,num);
		results(f, num);

	}


}
