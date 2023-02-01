#include <iostream>
using namespace std;
#include <string> //std::string

int main () {
	string name2="morning";
	string name3;

	//1. ////////////////////////
	char name[20]="afternoon"; char n[20];
	strcpy(n,name);

	name3 = name2;
	cout << name3 << " " << name2<< endl;
	// 2. ////////////////////////
	strcat (n,"extra");
	cout << n << " " << endl;
	
	name3 = name3 + "extra";
	cout << name3 << endl;
	name3 += "12345";
	cout << name3 << endl;
	name3.append("6789");
	cout << name3 << endl;
	//3. ////////////////////////
	string xx="aaaa a"; string yy="aaa"; 
	char x[20]="aaaaa"; char y[20]="aaa";
	if (strcmp(x,y) == 0) {
		cout << "same"<<endl;
	}else
		cout << "not same"<<endl;

	if (xx == yy) {
		cout << "same"<<endl;
	}else
		cout << "not same" << endl;
	///4. ///////////////////////
	int k = strlen(x);
	cout << strlen(x) << " " << k << endl;

	int j = xx.length();
	cout << xx.length() << " " << j << endl;
	///5. ////////////////////////
	cout << xx << endl;
	xx.insert(4,"AAAA");
	cout << xx << endl;
	//6. ////////////////////////
	cout << xx << endl;
	xx.replace(8,1,"B");
	cout << xx << endl;
	//7. ////////////////////////
	cout << xx <<endl;
	string xxx = xx.substr(4,4);
	cout <<xxx << " " << xx <<endl;
	char pname[30]="aaaaAAAAxxx";
	char lname[30]="";
	for (int i=4;i<8;i++) {
		lname[i-4] = pname[i];
	}
	cout << lname <<endl;
	//8. ///////////////////////
	string yyy="aaaaa";
	if (yyy.empty()) {
		cout << "empty" << endl;
	}else
		cout << "not empty" << endl;
	////////////////////////////
	char *p="aaaa";
	char *aaa[]={"aaaa","bbb","empty","qqq","xxx"};
	string bbb[]={"aaaa","bbb","empty","qqq","xxx"};
	cout << aaa[0] << " " << bbb[0] << endl;
	for (int i=0;i<5;i++) {
		cout << aaa[i] << " " << bbb[i]<< " ";
	}cout <<endl;



}

