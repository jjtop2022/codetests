#include <stdio.h>
#include <string.h>
#define MAX 4

void n(int i, int u1, int u2, int u3, int u4) {
	if (i == MAX || u1 == MAX || u2==MAX || u3 == MAX || u4==MAX) {
		//account locked
		printf ("cannot enter account - sorry try in 1 hour\n");
	}else{
		//success
		printf ("successful, enter website !\n");
	}
}

int main () {
	char *user[] = {"user1","user2","user3","user4"};
	char *password[]={"abc111","9090bbb","ge3344","567234"};
	int i=0, uu=0, u2=0, u3=0, u4=0;

	for (i=0;i<MAX;i++){

			char myuser[20]="";
			char mypass[20]="";
			printf ("enter user: ");
			gets(myuser);
			printf ("enter password: ");
			gets(mypass);

			if (strcmp(user[0],myuser) == 0){
				 if (strcmp(password[0],mypass) == 0){
						printf ("user1 is correct\n");
						break;
				 }else{
					 printf (" %d user1 password wrong\n",uu);
					 uu++;
				 }
			}else if (strcmp(user[1],myuser) == 0) {
				 if (strcmp(password[1],mypass) == 0){
						printf ("user2 is correct\n");
						break;
				 }else{
					 printf ("user2 password wrong\n");
					 u2++;
				 }
			}else if (strcmp(user[2],myuser) == 0) {
				if (strcmp(password[2],mypass) == 0){
						printf ("user3 is correct\n");
						break;
				 }else{
					 printf ("user3 password wrong\n");
					 u3++;
				 }
			}else if (strcmp(user[3],myuser) == 0){
				if (strcmp(password[3],mypass) == 0){
						printf ("user4 is correct\n");
						break;
				 }else{
					 printf ("user4 password wrong\n");
					 u4++;
				 }
			}else {
				printf ("%d incorrect user or password\n",i);

			}

	}
	n(i,uu,u2,u3,u4);
}

