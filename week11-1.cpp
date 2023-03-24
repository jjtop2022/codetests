#include <stdio.h>
#include <string.h>
#define MAX 5

struct student {
	char name[20];
	int age;
	int ID;
	char major[20];
	float grade;

};

void addstudent(student s1[]) {

    strcpy(s1[0].name,"Jenny Wu");
	s1[0].age = 23;
	s1[0].ID = 454433;
	strcpy(s1[0].major,"Computer");
	s1[0].grade = 78.5;

	strcpy(s1[1].name,"Henry Y");
	s1[1].age = 21;
	s1[1].ID = 645433;
	strcpy(s1[1].major,"Computer");
	s1[1].grade = 75.5;

	strcpy(s1[2].name,"Paul Lo");
	s1[2].age = 21;
	s1[2].ID = 675433;
	strcpy(s1[2].major,"Computer");
	s1[2].grade = 88.5;

	strcpy(s1[3].name,"Ku Lo");
	s1[3].age = 24;
	s1[3].ID = 755433;
	strcpy(s1[3].major,"sofware");
	s1[3].grade = 65.5;

	strcpy(s1[4].name,"Lisa Lo");
	s1[4].age = 26;
	s1[4].ID = 645433;
	strcpy(s1[4].major,"Computer");
	s1[4].grade = 86.5;

}

void printstudent(student s1[]) {
	for (int i=0;i<MAX;i++) {
		printf ("NAME: %s\n",s1[i].name);
		printf ("AGE: %d\n", s1[i].age);
		printf ("ID: %d\n",s1[i].ID);
		printf ("MAJOR: %s\n",s1[i].major);
		printf ("GRADE: %.1f\n",s1[i].grade);
		printf ("\n");
	}
}

int main () {

	student s1[MAX];
	//1.
	addstudent(s1);
	//2.
	printstudent(s1);


}
