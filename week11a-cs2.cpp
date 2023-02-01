#include <iostream>
using namespace std;

template<typename t1, typename t2>
class USEME {
public :
	USEME() {
		sum = 0;
	}
	// + 
	USEME(t1 mynum, t2 mynum2) {
		sum = mynum + mynum2;
	}
	void addme(t1 a, t2 b) {
		sum = a+b;
	}
	void minus(t1 a, t2 b) {
		sum = a-b;
	}
	void multiply(t1 a, t2 b) {
		sum = a*b;
	}
	void divide(t1 a, t2 b) {
		sum = a/b;
	}

	void printme() {
		cout << "Result is: " << sum << endl;
	}

private:

	t1 sum;
};


int main () {

	USEME<double, float>u1;
	u1.printme();
	u1.addme(6.8,7);
	u1.printme();
	u1.minus(90,900);
	u1.printme();
	u1.multiply(8.8,3);
	u1.printme();
	u1.divide(7,5);
	u1.printme();



	cout << endl;
	USEME<float, int>u2(7.8,5);
	u2.printme();

	USEME<int,float>u3(7.8,5);
	u3.printme();

	USEME<char, int>u4('A',3);
	u4.printme();

	USEME<int, char>u5('A',3);
	u5.printme();


	USEME<double,float>u6(8,3.5);
    u6.printme();


}