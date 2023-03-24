#include <stdio.h>
main () {
    FILE *fp;
	char s[100];
	char *p;
	char name[20];
	printf ("enter name: ");
	//scanf("%s",name);
	gets(name);
	fp = fopen(name,"r");	
	if (fp == NULL){
		printf ("no file!");
	}else{
		do {
		  p = fgets(s,100,fp);
		  if (p != NULL){
  			printf ("%s",s);
  		  }
			
		}while(p != NULL);
	}
	fclose(fp);
}
