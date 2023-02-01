#include <iostream>
using namespace std;

class Box {
public:
	Box(char newcolor[20]="nocolor") {
		strcpy(color,newcolor);
		
		countme++;

	}
	void addcolor(char newcolor[20]) {
		strcpy(color,newcolor);
		cout << "Color add: "<<color<<endl;
	}

	void printcolor() {
		cout << "Box color: "<< color << endl;

	}
    static int getcount() {
		return countme;
	}


private:
	char color[20];
	static int countme;

};

int Box::countme =0;

int main () {

	cout << "Box count: "<<Box::getcount()<<endl;
	Box b1;
	b1.printcolor();
	b1.addcolor("orange");
	b1.printcolor();
	cout << "Box count: "<<b1.getcount()<<endl;

	Box b2("green");
	b2.printcolor();
	b2.addcolor("yellow");
	b2.printcolor();
	cout << "Box count: "<<b1.getcount()<<endl;

	Box b3("red");
	b3.printcolor();
	cout << "Box count: "<<Box::getcount()<<endl;

	Box b4[10];
	b4[0].printcolor();
	cout << "Box count: "<<b3.getcount()<<endl;




}
