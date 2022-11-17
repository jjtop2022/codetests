#include <stdio.h>
#include <stdlib.h>
struct student {
   int num;
   char id[30];
   char name[30];
   char major[30];
};

main () {
    struct student s1[3];
	FILE *fp;
    char lines[100];
    char *c;
    char name[20];
    int j=0;
    printf ("enter a filename: ");
    gets(name);
    fp = fopen(name,"r");
    
    if (fp == NULL) {
    	printf ("no file!");
    }else{
    	
    	for (j=0;j<3;j++){
		  c = fgets(lines,50, fp);
		  int i = atoi(lines);
		  s1[j].num = j; 
		  c= fgets(lines,50,fp);
		  strcpy(s1[j].id,lines);
		  c = fgets(lines,50,fp);	
		  strcpy(s1[j].name,lines);
		  c = fgets(lines,50,fp);
		  strcpy(s1[j].major,lines);      
    	}
    }	
    fclose(fp);
    
    //printout structure
    for (j=0;j<3;j++){
  	    printf ("number: %d\n",s1[j].num);
	    printf ("Name: %s",s1[j].name);
	    printf ("ID: %s",s1[j].id);
	    printf ("Major: %s", s1[j].major);
	    printf ("\n");
    }
}

