#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;

class student {
public:
	//student() { }
	student(string nname="none",int nage=0,char nmajor[20]="no",int nID=999,float ngrade=0.0) {
		name=nname;
		age =nage;
		strcpy(major,nmajor);
		ID = nID;
		grade = ngrade;
	}
	void addstudent(string nname,int nage,char nmajor[20],int nID,float ngrade) {
		name=nname;
		age =nage;
		strcpy(major,nmajor);
		ID = nID;
		grade = ngrade;
	}
	void printstudent() {
		cout <<setiosflags(ios::left);
		cout << "Name:"<<setw(10)<<name<<"Age:"<<setw(3)<<age<<"Major:"
			<<setw(10)<<major<<"ID:"<<setw(8)<<ID<<"Grade:"<<setw(5)<<grade<<endl;
	}
	void changemajor(char nmajor[20]) {
		strcpy(major,nmajor);
		cout << "Major changed to: "<<major<<endl;

	}

private:
	string name;
	int age;
	char major[20];
	int ID;
	float grade;
};


int main () {
	student s1("Hess",23,"Software",45655,87.6);
	s1.printstudent();
	student s2;
	s2.printstudent();
	s2.addstudent("Jess",22,"IT",55455,78.6);
	s2.printstudent();
	s2.changemajor("CompSci");
	s2.printstudent();




}

