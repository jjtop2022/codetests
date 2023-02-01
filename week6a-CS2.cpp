#include <iostream>
#include <iomanip>
using namespace std;

struct STUDENT {
	char name[20];
	int age;
	char major[20];
	int ID;
	float grade;

};

void printstudent(STUDENT s) {
	cout << setiosflags(std::ios::left);
	cout << "NAME:"<<setw(10)<<s.name<<" AGE:"<<setw(3)<<s.age<<" MAJOR:"
		<<setw(12)<<s.major<<" ID:"<<setw(7)<<s.ID<<" GRADE:"<<
		setw(5)<<s.grade<<endl;

}

void addstudent(STUDENT &s,char sname[20],int sage,char smajor[20],int sID,float sgrade) {
	strcpy(s.name,sname);
	s.age = sage;
	strcpy(s.major,smajor);
	s.ID = sID;
	s.grade = sgrade;
}

void changemajor(STUDENT &s, char newmajor[20]) {
    strcpy(s.major,newmajor);
	cout << s.name<<" major changed to: "<< s.major << endl;
}

void changegrade(STUDENT &s, float newgrade) {
    s.grade = newgrade;
	cout << s.name<<" grade changed to: "<< s.grade << endl;
}

int main () {

	
	STUDENT s1={"Lisa",23,"CompScience",64454,87.8};
	STUDENT s2;
	addstudent(s2,"Helen",22,"Software",465565,87.4);
	STUDENT s3={"Mike",23,"CompScience",94454,81.2};

	printstudent(s1);
	printstudent(s2);
	printstudent(s3);
	
	changemajor(s2,"Accounting");
	printstudent(s2);
	changegrade(s1,90.5);
	printstudent(s1);
	

}

