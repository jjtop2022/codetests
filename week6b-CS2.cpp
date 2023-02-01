#include <iostream>
#include <iomanip>
using namespace std;

struct STUDENT {
	int num;
	char name[20];
	int age;
	char major[20];
	int ID;
	float grade;

};

void printstudent(STUDENT s[],int num) {
	cout << setiosflags(std::ios::left);
	for(int i=0;i<num;i++) {
		cout << "NUM:"<<setw(3)<<s[i].num<<" NAME:"<<setw(10)<<s[i].name<<" AGE:"<<setw(3)<<s[i].age
		<<" MAJOR:"<<setw(12)<<s[i].major<<" ID:"<<setw(7)<<s[i].ID
		<<" GRADE:"<<setw(5)<<s[i].grade<<endl;
	}

}

///a /////////////////////////////////////////////////////////////
void addstudent(STUDENT &s,int nnum,char sname[20],int sage,char smajor[20],int sID,float sgrade) {
	s.num = nnum;
	strcpy(s.name,sname);
	s.age = sage;
	strcpy(s.major,smajor);
	s.ID = sID;
	s.grade = sgrade;
}

/// b ///////////////////////////////////////////////////////////
void addstudent2(STUDENT s[], int num){
	char nname[20]; char nmajor[20];
	s[num-1].num = num;
	cout << "enter student name: ";
	cin >> nname;
	strcpy(s[num-1].name, nname);
	cout << "enter age: ";
	cin >> s[num-1].age;
	cout << "enter student major: ";
	cin >> nmajor;
	strcpy(s[num-1].major, nmajor);
	cout<< "enter student ID: ";
	cin >> s[num-1].ID;
	cout << "enter student grade: ";
	cin >> s[num-1].grade;
}



void changemajor(STUDENT s[]) {
	char newmajor[20];
	int num;
	cout << "Enter new major: ";
	cin >> newmajor;
	cout << "Enter num: ";
	cin >> num;
    strcpy(s[num-1].major,newmajor);
	cout << s[num-1].name<<" major changed to: "<< s[num-1].major << endl;
}

void changegrade(STUDENT s[]) {
	float newgrade;
	int num;
	cout << "enter new grade: ";
	cin >> newgrade;
	cout << "enter num: ";
	cin >> num;
    s[num-1].grade = newgrade;
	cout << s[num-1].name<<" grade changed to: "<< s[num-1].grade << endl;
}

int main () {

	STUDENT s[20];
	int numstudent=0;
	///////////////////////////////////////////////
	while(true) {
		int num;
		cout << "Enter action: "<<endl;
		cout <<	"1-addstudent,2-printstudent,3-changemajor,4-changegrade,5-quit ";
		cin >> num;

		if (num == 1) {
			//addstudent(s[0],1,"Helen",22,"Software",465565,87.4);
			//addstudent(s[1],2,"James",21,"CompScience",985565,90.1);
			//addstudent(s[2],3,"Lisa",22,"Accounting",455065,77.2);
			//numstudent=3;
			numstudent++;
			addstudent2(s,numstudent);

		}else if (num == 2) {
			printstudent(s,numstudent);
		}else if (num == 3) {
			changemajor(s);
		}else if (num == 4) {
			changegrade(s);
		}else if (num == 5) {
			cout << "Bye!"<<endl;
			break;

		}else{
			cout << "Invalid!"<<endl;
		}
	}

}

