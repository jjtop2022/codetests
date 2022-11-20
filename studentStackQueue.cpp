#include <iostream>
#include <string>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;

class STUDENT {
public:
	STUDENT(char newname[15]="noname", int newage=1, char newmajor[25]="nomajor", 
				float newgrade=1.0, int nID=99999){
         strcpy(name,newname);
		 age = newage;
		 strcpy(major,newmajor);
		 grades = newgrade;
		 ID = nID;
	}
	void addstudent(char newname[15], int newage, char newmajor[25], 
				float newgrade, int nID){
         strcpy(name,newname);
		 age = newage;
		 strcpy(major,newmajor);
		 grades = newgrade;
		 ID = nID;
	}
	void printstudent(){
		cout << setiosflags(ios::left);
		cout << "NAME: "<<setw(10)<<name<<"AGE: "<<setw(4)<<age<<"MAJOR: "<<setw(20)<<major
			<<"GRADES: "<<setw(6)<<grades<<"ID: "<<setw(8)<<ID<<endl;
	}
	void changemajor(char newmajor[25]){
		strcpy(major,newmajor);
		cout << "Major changed to: "<< major << endl;
	}
private:
	char name[15];
	int age;
	char major[25];
	float grades;
	int ID;
};


int main () {
	STUDENT s1;
	s1.printstudent();
	s1.addstudent("Jane",22,"IT ",88.5,67666);
	s1.printstudent();
	STUDENT s2("Amy",21,"CS",78.5,56566);
	s2.printstudent();
	////////////////////
	stack<STUDENT>s3;
	s3.push(STUDENT());
	s3.push(STUDENT("Jane",21,"CS",78.5,56566));
	s3.push(STUDENT("Lisa",23,"IT",74.5,76666));
	s3.push(STUDENT("Bob",24,"SE",97.6,89966));
	s3.push(STUDENT("Joe",21,"Accounting",67.5,56566));

	cout << "Number of students on stack: "<< s3.size() << endl;
	while (!s3.empty()) {
		s3.top().printstudent();
		s3.pop();
	}
	cout << "Number of students on stack: "<< s3.size() << endl;
	///////////////////////
	queue<STUDENT>s4;
	s4.push(STUDENT());
	s4.push(STUDENT("Jane",21,"CS",78.5,56566));
	s4.push(STUDENT("Lisa",23,"IT",74.5,76666));
	s4.push(STUDENT("Bob",24,"SE",97.6,89966));
	s4.push(STUDENT("Joe",21,"Accounting",67.5,56566));

	cout << "Number of students on queue: "<< s4.size() << endl;
	while (!s4.empty()) {
		s4.front().printstudent();
        s4.pop();
	}
	cout << "Number of students on queue: "<< s4.size() << endl;
	//////////////////////////////////////////
	queue<float>j;
	j.push(7.6);
	j.push(8.3);
	j.push(1.2);
	j.push(9.454);
	cout << "size of queue: "<< j.size() << endl;
	while (!j.empty()){
		cout << j.front() << endl;
		j.pop();
	}
	cout << "size of queue: "<< j.size() << endl;
	//////////////////////////////////////////
	stack<string>i;
	i.push("amy");
	i.push("bob");
	i.push("mmm");
	i.push("ppp");
	i.push("bbb");

	cout << "Size of stack: "<< i.size() << endl;
	while (!i.empty()){
		cout << i.top() << endl;
		i.pop();
	}
	cout << "Size of stack: "<< i.size() << endl;
	
}





