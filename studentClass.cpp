#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <queue>
using namespace std;
#include "week9-CS2.h";

student::student(string nname="none",int nage=0,
		string nmajor="no",int nID=999,float ngrade=0.0) {
		name=nname;
		age =nage;
		major=nmajor;
		ID = nID;
		grade = ngrade;
}
	
void student::addstudent(string nname,int nage,
		string nmajor,int nID,float ngrade) {
		name=nname;
		age =nage;
		major=nmajor;
		ID = nID;
		grade = ngrade;
}

void student:: printstudent() {
		cout <<setiosflags(ios::left);
		cout << "Name:"<<setw(10)<<name<<"Age:"<<setw(3)<<age<<"Major:"
		<<setw(10)<<major<<"ID:"<<setw(8)<<ID<<"Grade:"<<setw(5)<<grade<<endl;
}

void student:: changemajor(string newmajor) {
		major=newmajor;
		cout << "Major changed to: "<<major<<endl;
}



///////////c///////////////////////
class GradStudent : public student {
public:
	
	GradStudent(string nname="no",int nage=0,string nmajor="no",
		int nID=999,float ngrade=0.0,string ngradmajor="none"){
         addstudent(nname,nage,nmajor,nID,ngrade);
		 gradmajor=ngradmajor;

	}
	void addgrad(string nname="no",int nage=0,string nmajor="no",
		int nID=999,float ngrade=0.0,string ngradmajor="no"){
        addstudent(nname,nage,nmajor,nID,ngrade);
		 gradmajor=ngradmajor;
	}
	void printgrad(){
		printstudent();
		cout << "Grad major: "<<gradmajor<<endl;
	}

	friend void changeGrad(GradStudent &gs, string newgradm);
	
private:
	string gradmajor;
};

/////d ///////////////// friend function ///
void changeGrad(GradStudent &gs, string newgradm) {
	gs.gradmajor=newgradm;
	cout << "grad major changed to: "<<gs.gradmajor<<endl;

}
void changegrade(student &s, float newgrade){
	s.grade = newgrade;
	cout << "grade changed to: "<<s.grade<<endl;
}

void changemajoroutside(student& s, string newmajor) {
	s.major = newmajor;

}


int main () {
    ///a //////////////////////////////
	student s1;
	s1.printstudent();
	s1.addstudent("James",23,"Software",75456,85.6);
	s1.printstudent();
	cout << "(d)"<<endl;
	changegrade(s1,88.5);
    s1.printstudent();

	student s2("Lisa",22,"CompSc",44544,85.7);
	s2.printstudent();
	s2.changemajor("Database");
	s2.printstudent();
	 
	//c //////////////////////////////
	cout << "(c)"<<endl;
	GradStudent gs("Helen",25,"software",90777,87.7,"Database");
	gs.printgrad();

	GradStudent g2;
	g2.printgrad();
	g2.addgrad("Amy",25,"software",90777,87.7,"Database");
	g2.printgrad();
	////d /////
	changeGrad(g2,"PHP");
	g2.printgrad();

	///b //////////////////////////////
	cout << "(d)"<<endl;
	stack<student>s3;
	queue<student>s4;

	//stack
	s3.push(student("Ann",22,"IT",56550,77.56));
	s3.push(student("Bert",21,"Account",76555,89.56));
	s3.push(student("Henry",24,"CS",36555,85.56));
	s3.push(student("Ron",32,"IT",56585,81.5));

	cout <<"stack student count: "<<s3.size() << endl;
	while (!s3.empty()) {
		s3.top().printstudent();
		s3.pop();
	}
	cout <<"stack student count: "<<s3.size() << endl;
	cout <<endl;
	////queue
	s4.push(student("Ann",22,"IT",26559,77.56));
	s4.push(student("Bert",21,"Account",76555,89.56));
	s4.push(student("Henry",24,"CS",56555,85.56));
	s4.push(student("Ron",32,"IT",90855,81.5));

	cout <<"queue student count: "<<s4.size() << endl;
	while (!s4.empty()) {
		s4.front().printstudent();
		s4.pop();

	}
    cout <<"queue student count: "<<s4.size() << endl;

	/////////////////////////////////////////////////////


}
