#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;

class student {
public:
	//student() { }
	student(string nname,int nage,string nmajor,int nID,float ngrade);
	void addstudent(string nname,int nage,string nmajor,int nID,float ngrade);
	void printstudent();
	void changemajor(string nmajor);

	friend void changegrade(student& s, float newgrade);
	friend void changemajoroutside(student& s, string newmajor);
private:
	string name;
	int age;
	string major;
	int ID;
	float grade;

};

