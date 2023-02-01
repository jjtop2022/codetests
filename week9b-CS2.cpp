#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <stack>
#include <queue>
using namespace std;
#include "test2.h"

/////////////////////////////////////////////////////////////

student::student(string nname="none",int nage=0,char nmajor[20]="no",int nID=999,float ngrade=0.0) {
		name=nname;
		age =nage;
		strcpy(major,nmajor);
		ID = nID;
		grade = ngrade;
}

void student:: addstudent(string nname,int nage,char nmajor[20],int nID,float ngrade) {
		name=nname;
		age =nage;
		strcpy(major,nmajor);
		ID = nID;
		grade = ngrade;
}

void student:: printstudent() {
		cout <<setiosflags(ios::left);
		cout << "Name:"<<setw(10)<<name<<"Age:"<<setw(3)<<age<<"Major:"
			<<setw(10)<<major<<"ID:"<<setw(8)<<ID<<"Grade:"<<setw(5)<<grade<<endl;
}

void student:: changemajor(char nmajor[20]) {
		strcpy(major,nmajor);
		cout << "Major changed to: "<<major<<endl;

}

int main () {
	student s1("Hess",23,"Software",45655,87.6);
	s1.printstudent();
	student s2;
	s2.printstudent();
	s2.addstudent("Jess",22,"IT",55455,78.6);
	s2.printstudent();
	s2.changemajor("CompSci");
	s2.printstudent();

	/////////////////////////////
	stack<student>s3;
	s3.push(student("Ann",22,"IT",56555,77.56));
	s3.push(student("Bert",21,"Account",76555,89.56));
	s3.push(student("Henry",24,"CS",56555,85.56));
	s3.push(student("Ron",32,"IT",56555,81.5));
	s3.push(student("James",32,"software",9955,89.56));
	s3.push(student());

	cout <<"Number student: "<< s3.size() << endl;
	while (!s3.empty()) {
		s3.top().printstudent();
		s3.pop();

	}
	cout <<"Number student: "<< s3.size() << endl;

	queue<student>s4;
	s4.push(student("Ann",22,"IT",56555,77.56));
	s4.push(student("Bert",21,"Account",76555,89.56));
	s4.push(student("Henry",24,"CS",56555,85.56));
	s4.push(student("Ron",32,"IT",56555,81.5));
	s4.push(student("James",32,"software",9955,89.56));
	s4.push(student("cat",23,"IT",8999,65.7));

	cout <<"Number student: "<< s4.size() << endl;
	while (!s4.empty()) {
		s4.front().printstudent();
		s4.pop();
	}
	cout <<"Number student: "<< s4.size() << endl;

	//////////////////////////////
	/*stack<float>pp;
	pp.push(2.3);
	pp.push(1.2);
	pp.push(65.6);
	pp.push(56.5);
	pp.push(13.4);

	cout << "stack size: "<<pp.size()<<endl;
	
	while (!pp.empty()) {
		cout << pp.top()<<endl;
		pp.pop();
		cout << "stack size: "<<pp.size()<<endl;
	}
	*/


}

