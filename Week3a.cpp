#include <iostream>
using namespace std;

int main () {
	char name[20]="Lisa";
	char *namep = "James";

    strcpy(name, namep);
	cout << name << " " << namep << endl;
	 
	strcat (name, " hi");
	cout << name << " " << endl;

	int k = strlen(name);
	cout << "length: " << strlen(name) << " " << k<< endl;

	int g = strcmp(name, "James hi");
	cout << g << endl;
	if (strcmp(name, "James hi") == 0) {
		cout << "same"<<endl;
	}else
		cout << "not same" << endl;


}

