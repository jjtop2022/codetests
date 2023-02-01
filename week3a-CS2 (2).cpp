#include <iostream>
using namespace std;

int main () {
	int i=7, j=67;
	int *p;
	p = new int;
	*p = 78;
	cout << *p << " " << i << " " << j << endl;
	cout << p << " " << &i << " " << &j <<endl;
	delete p;
	cout << *p << " " << i << " " << j << endl;
	p = &j;
	*p = 120;
	cout << *p << " " << i << " " << j << endl;
	cout << p << " " << &i << " " << &j <<endl;
	/////////////////////////////
	char name[]="aaaaa";
	char *pname="aaaaa"; char *pp;
	pp = new char [20];

	cout << name << " " << pname << endl;
	strcpy(name,"AAAAA");
	cout << name << " " << pname << endl;
	name[0]='B';
	cout << name << " " << pname << endl;
	//strcpy(pname,"AAAAA");
	pname = "AAAAA";
	//pname[0]='B';
	cout << name << " " << pname << endl;
	strcpy (pp, "BBBBBB");
	cout << pp << endl;
	pp[0]='C';
	cout << pp << endl;
	delete [] pp;
	cout << pp << endl;
}
