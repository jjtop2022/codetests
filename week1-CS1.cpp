#include <iostream>
using namespace std;
#define MAX 8

int main () {

	//1.  /////////////////////
	printf ("Hello world\n");
	cout << "hello world" << endl;

	int i=89;
	float f=5.67;
	double d=5.89654896;
	char c='&';
	char n[]="Jessica";
	char nn[10];
	char *nnn = "Jessica";

	printf ("%d\n", i);
	cout << i << endl;
	printf ("%.2f\n", f);
	cout << f << endl;
	printf ("%.8f\n", d);
	cout << d << endl;
	printf ("%c\n",c);
	cout << c << endl;
	printf ("%s\n", n);
	cout << n << endl;
	printf ("%c%c%c%c\n",n[0],n[1],n[2],n[3]);
	printf ("%s\n", nnn);
	cout << nnn <<endl;

	///2. ////
	char name[20];
	int age;
	cout << "What is your name? ";
	//scanf("%s", name);
	cin >> name;
	cout << "What is your age: ";
	//scanf("%d",&age);
	cin >> age;
	cout << "Your name is: "<< name <<" your age is: "<< age <<endl;

	//3. /////////
	int a[] = {2,30,78,89,900,909,999,7667};
	int aa[10];

	cout << a[0] << " "<< a[1] << " " << a[2] << endl;
	for (int i=0;i<MAX;i++){
		cout << a[i]<<" ";
	}cout << endl;

	aa[0] = 4; aa[1] = 6; aa[2]= 45;
	for (int i=3;i<10;i++) {
		aa[i] = i*2;
	}
	for (int i=0;i<10;i++){
		cout << aa[i]<<" ";
	}cout << endl;

	for (int i=MAX-1;i>=0;i=i-1) {
		cout << a[i] << " ";
	}cout << endl;
	
	int j=0;
	while (j<MAX) {
		cout << a[j] << " ";
		j=j+1;
	}cout << endl;





}