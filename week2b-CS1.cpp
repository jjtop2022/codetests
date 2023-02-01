#include <iostream>
#include <cstring>
using namespace std;
#define QUIT 9999

int main () {
	while (true) {
	   char name[20];  char myage[5];
	   int age;
	   cout << "Enter name: ";
	   cin >> name;
	   cout << "enter age: ";
	   cin >> myage;
	   age = atoi(myage);
	   //cout << "name: "<< name << " age: "<<age<< endl;
	   if (age == QUIT && strcmp(name,"quit") == 0) {
		   cout << "program quit"<<endl;
		   break;
	   }

	   if (age >= 0 && age < 8) {
		   cout << name << " your young child" << endl;
	   }else if (age >= 8 && age < 19) {
		   cout << name << " your child" << endl;
	   }else if (age >= 19 && age <= 35) {
		   cout << name << " your young adult" << endl;
	   }else if (age >= 36 && age <= 60) {
		   cout << name << " your working age" << endl;
	   }else if (age >= 61 && age <=120) {
		   cout << name << " Your retired"<<endl;
	   }else{
		   cout << "invalid"<<endl;
	   }

	}

}

