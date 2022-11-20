#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 30
#define STU 9
struct student {
   int num;
   char id[MAXLINE];
   char name[MAXLINE];
   char major[MAXLINE];	
   char telephone[MAXLINE];
};
void search(struct student []);
void printstu(struct student []);
void readtostruc(struct student[],FILE *fp);
void selection(struct student[]);

main (){
   FILE *fp;
   struct student st[STU];

   //read filename open to read
   char name[20];
   printf("enter filename: ");
   gets(name);
   fp = fopen(name,"r");
   
   if (fp == NULL) {
   	  printf ("no file!");
   }else {
      //read data to struct
	  readtostruc(st,fp);  
      //functions
      selection(st);
   }
}

void selection(struct student st[]){
	while (1) {
	      	int k;
	      	printf ("enter 1 or 2: ");
	      	scanf("%d",&k);
	      	if (k == 1) {
		      	printstu(st);
	        }else if (k == 2){
			   //search
			   search(st); 
	        }else{
	        	break;
	        }
	     }		
}

void readtostruc(struct student st[],FILE *fp){
	int i; char *p; char lines[50];
      for (i=0;i<STU;i++){
      	  //num
      	  p = fgets(lines,50,fp);
      	  int h = atoi(lines);
      	  st[i].num = h;
      	  //id
      	  p = fgets(lines,50,fp);
      	  strcpy(st[i].id,lines);
      	  //name
      	  p = fgets(lines,50,fp);
      	  strcpy(st[i].name,lines);
      	  //major
      	  p = fgets(lines,50,fp);
      	  strcpy(st[i].major,lines);
      	  //phone
      	  p = fgets(lines,50,fp);
      	  strcpy(st[i].telephone,lines);
      }
}

void printstu (struct student st[]){
  int i;
  for (i=0;i<STU;i++){
		printf ("NUM: %d\n", st[i].num);
		printf ("ID: %s", st[i].id);
		printf ("NAME: %s", st[i].name);
		printf ("MAJOR: %s", st[i].major);
		printf ("TELEPHONE: %s", st[i].telephone);
		printf ("\n");
  }
}

void search(struct student st[]){
	while(1){
	    char stid[20];
		printf ("enter student ID: ");
		gets(stid);
		if (strncmp(stid,"exit",4) == 0){
			break;
		}
		int i;
		for (i=0;i<STU;i++){
		    if (strncmp(st[i].id,stid,8) == 0){
	    		printf ("NUM: %d\n", st[i].num);
	    		printf ("ID: %s", st[i].id);
	    		printf ("NAME: %s", st[i].name);
	    		printf ("MAJOR: %s", st[i].major);
	    		printf ("TELEPHONE: %s", st[i].telephone);
	    	}
		}
	}
}
