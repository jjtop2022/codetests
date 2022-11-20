#include <iostream>
using namespace std;

template<typename t1, typename t2>
class USEME {
public:

	USEME() { 
	   sum = 0;
	}
	USEME(t1 aa, t2 bb) {
		sum = aa + bb;
	}
	void addme(t1 aa, t2 bb) {
		sum = aa + bb;
		cout << "added: ";
	}
	void multiply(t1 aa, t2 bb) {
		sum = aa * bb;
		cout << "multiply: ";
	}
	void divide(t1 aa, t2 bb) {
		sum = aa / bb;
		cout << "divide: ";
	}
	void minus(t1 a, t2 b) {
		sum = a - b;
		cout <<"minus: ";
	}

	void printsum() {
		cout << "The sum is: "<< sum<<endl;
	}



private:
	t1 sum;
};

int main () {

	USEME<int,float>u1(76.7,9.2);
	u1.printsum();
	u1.minus(7.8,80.1);
	u1.printsum();
	u1.multiply(6,7.2);
	u1.printsum();

    USEME<float,int>u2(76.7,9.2);
	u2.printsum();
	u2.minus(7.8,80.1);
	u2.printsum();

	USEME<float,float>uu2(76.7,9.2);
	uu2.printsum();
	uu2.minus(7.8,80.1);
	uu2.printsum();
	uu2.multiply(6,7.2);
	uu2.printsum();


    USEME<char, int>u3('a',4);
	u3.printsum();


	USEME<int, char>u4('a',4);
	u4.printsum();

	USEME<double,float>u5(9.78,5.9);
	u5.printsum();
  


}

