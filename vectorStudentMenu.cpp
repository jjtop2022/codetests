#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class STUDENT {
public:
	STUDENT(char sname[30], int sage, char *smajor, int sID);
	void printstudent() const;
private:
	char name[30];
	int age;
	char *major;
	int ID;
};

STUDENT::STUDENT(char sname[30]="noname", int sage=0, char *smajor="no major", int sID=99999)
	     : age(sage), major(smajor), ID(sID) {
		strcpy(name,sname);
}
void STUDENT:: printstudent() const{
	    cout << setiosflags(ios::left);
		cout << "name: "<<setw(8)<<name<<" age: "<<setw(3)<<age<<" major: "<<setw(15)<<major<<" id: "<<setw(8)<<ID<<endl;
}



int main () {
	////////////////1. declare vector of students
	vector<STUDENT>students;

	////////////////2. add some students
	students.push_back(STUDENT());
	students.push_back(STUDENT("Jamie",23,"Comp Science",65655));
	students.push_back(STUDENT("Mike",22,"Comp Science",73255));
	students.push_back(STUDENT("Lisa",23,"Business",46255));

	//////////////////////////// Menu Loop
	while (1) {
		int i=0;
		cout << endl;
		cout << "1 - print students, 2 - clear students, 3 - check if empty, " << endl;
		cout << "4 - check size, 5 -remove last student, 6 - add student, 7 -quit "<<endl;
		cin >> i;
		if (i == 1) {
			////////////////Printout students
			for (auto i=students.cbegin(); i<students.cend(); i++){
				i->printstudent();
			}
		}else if (i == 2) {
			students.clear();
			cout << "All students are deleted"<<endl;

		}else if (i == 3) {
			////////////////Check if vector empty
			if (students.empty()) {
				cout << "no students on list"<< endl;
			}else
				cout << "There are students on list" << endl;

		}else if (i == 4) {
			//////////////// vector size
			cout << "number of students: "<< students.size() << endl;

		}else if (i ==5) {
			//////////////// remove last student
			students.pop_back();
		    cout << "last student removed" << endl;

		}else if (i ==6) {
			///////////////// add a student
			cout << "enter name, age, major, ID of student: "<<endl;
			char name[20]=""; int age; char major[20]=""; int ID;
			cin >> name >> age >> major >> ID;
			students.push_back(STUDENT(name,age,major,ID));
			cout << " student added successfully "<<endl;

		}else if (i ==7) {
			cout << "quit program" << endl;
			break;
		}else
			cout << "Invalid choice"<< endl;

	}

}