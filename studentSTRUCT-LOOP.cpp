#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;

struct STUDENT {
	int num;
	char name[20];
	int age;
	char major[25];
	float grades;
	int ID;
};

void printstudent(STUDENT s1[],int numstudent) {
	cout << setiosflags(ios::left);
  for (int i=0;i<numstudent;i++) {
		cout << setw(3) << s1[i].num <<setw(10)<<s1[i].name << setw(4)<< s1[i].age<<setw(20)<<
			s1[i].major << setw(5) << s1[i].grades<< setw(8) << s1[i].ID << endl;
		
  }
}

//1.
void addstudent(STUDENT &s, int newnum, char newname[20], int newage, char newmajor[25], 
	            float newgrade, int newID) {
		 s.num = newnum;
         strcpy(s.name,newname);
		 s.age = newage;
		 strcpy(s.major,newmajor);
		 s.grades = newgrade;
		 s.ID = newID;
}

//2.
void enterstudent(STUDENT s[],int numstudent) {
		cout << "Enter name: ";
		cin >> s[numstudent].name;
		cout << "Enter age: ";
		cin >> s[numstudent].age;
		cout << "Enter major: ";
		cin.ignore();
		cin.getline(s[numstudent].major,25,'\n');
		cout << "Enter grade: ";
		cin >> s[numstudent].grades;
		cout << "Enter ID: ";
		cin >> s[numstudent].ID;
		s[numstudent].num = numstudent+1;
}

void changemajor(STUDENT s[]){
	char newmajor[25]; 
	int num;
	cout << "enter student num: ";
	cin >> num;
	cout << "Enter new major: ";
	cin.ignore();
	cin.getline(newmajor,25,'\n');
	strcpy(s[num-1].major,newmajor);
} 

void changegrade(STUDENT s[]) {
	int num;
	float newgrade;
	cout << "enter student num: ";
	cin >> num;
	cout << "Enter new grade: ";
	cin >> newgrade;
	s[num-1].grades = newgrade;
}

void writefile(STUDENT s[], int num) {
	fstream f1;  char filename[20];
	cout << "enter filename: ";
	cin >> filename;

	f1.open(filename, ios::out | ios::app);
	if (f1.is_open()) {
		for (int i=0;i<num;i++) {
			//f1.write(reinterpret_cast<const char *>(&stemp),sizeof(STUDENT));
			  char temp[20]="";
			  itoa(s[i].num, temp, 10);
			  f1.write(temp,2);
			  f1.write(s[i].name,strlen(s[i].name));  f1.write(" ",1);
			  itoa(s[i].age, temp, 10);
			  f1.write(temp,3);
			  f1.write(s[i].major,strlen(s[i].major)); f1.write(" ",1);
			  //itoa(s[i].grades,temp,10);
			  sprintf(temp,"%.1f", s[i].grades);
			  f1.write(temp,6);
			  itoa(s[i].ID, temp, 10);
			  f1.write(temp,10);
			  f1 << "\n";
		}
		cout << "Students written to file: "<< filename << endl;
	}
	f1.close();
}

int main () {
	STUDENT s1[30];
	int num=0;

	while (true) {
		int choose;
		cout << "Enter 1-addstudent, 2-printstudent, 3-changemajor, 4-changegrade, ";
	    cout << "5-writefile, 6-quit: ";
		cin >> choose;
		if (choose == 1) {
			enterstudent(s1,num);
			num++;
			//addstudent(s1[0], 1, "Jenny",22,"Computer science", 87.8, 8767878);
			//addstudent(s1[1], 2, "Joe", 23, "Comp Science", 77.8, 6757676);
		}else if (choose == 2) {
			printstudent(s1,num);
		}else if (choose == 3) {
			changemajor(s1);
		}else if (choose == 4)  {
			changegrade(s1);
		}else if (choose == 5) {
			writefile(s1, num);
		}else if (choose == 6) {
			cout << "quit\n";
			break;
		}else{
			cout << "invalid\n";
		}
	}

}




