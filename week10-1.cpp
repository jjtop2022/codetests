#include <stdio.h>
#include <string.h>
#define MAX 6

//2. ///
void rrr(int i) {
	if (i == MAX){
		printf ("Cannot enter website, user, password is wrong\n");
	}else{
		printf ("Can goto website, user,password correct\n");
	}
}


int main () {
	char *user[]={"user1","user2","user3","user4"};
	char *password[]={"112abc","5546b","9990a","87678"};

	int i=0; int u1=0, u2=0, u3=0, u4=0, u5=0;
	//1.
	for (i=0;i<MAX;i++) {
		   char myuser[20];
		   char mypass[20];
           printf ("enter user: ");
		   scanf("%s",myuser);
		   printf ("enter password: ");
		   scanf("%s",mypass);

		   if (strcmp(user[0],myuser) == 0) {
			   if (strcmp(password[0],mypass) == 0) {
				   printf ("user1 and password is correct\n");
				   break;
			   }else{
				   u1++;
				   printf ("user1 password is wrong %d times\n", u1);
			   }
		   }else if (strcmp(user[1],myuser) == 0) {
			   if (strcmp(password[1],mypass) == 0) {
				   printf ("user2 and password is correct\n");
				   break;
			   }else{
				   u2++;
				   printf ("user2 password is wrong %d times\n", u2);
			   }
		   }else if (strcmp(user[2],myuser) == 0) {
			   if (strcmp(password[2],mypass) == 0) {
				   printf ("user3 and password is correct\n");
				   break;
			   }else{
				   u3++;
				   printf ("user3 password is wrong %d times\n", u3);
			   }
		   }else if (strcmp(user[3],myuser) == 0) {
			    if (strcmp(password[3],mypass) == 0) {
				   printf ("user4 and password is correct\n");
				   break;
			   }else{
				   u4++;
				   printf ("user4 password is wrong %d times\n", u4);
			   }
		   }else {
			   u5++;
			   printf ("username is wrong %d times\n", u5);
		   }
	}

	rrr(i);

}