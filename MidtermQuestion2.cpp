#include <stdio.h>
#include <string.h>

int main () {

	while(1) {
		char name[20];
		int age;
		printf ("Enter name: ");
		scanf("%s",name);
		printf ("Enter age: ");
		scanf("%d", &age);
		if (age == 999 && (strcmp(name,"quit") == 0)) {
			break;
		}
		printf ("Your name: %s, age: %d\n",name,age);
		if (age >= 0 && age < 6) {
			printf ("young child\n");
		}else if (age >= 6 && age <19) {
			printf ("child\n");
		}else if (age >= 19 && age <= 35) {
			printf ("Young adult\n");
		}else if (age >35 && age < 66) {
			printf ("working age\n");
		}else if (age >= 66 && age <=120) {
			printf ("retired\n");
		}else{
			printf ("invalid\n");
		}



	}

}