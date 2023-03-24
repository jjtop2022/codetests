#include <stdio.h>
typedef struct student {
	char id[30];
	char name[30];
	char major[30];
	int num;
}student;

main () {
	FILE *fp;
	student *x;
	long i;
	int j;
	x =(student *)malloc (sizeof(student));
	
	fp = fopen("student.txt","r");
	i = fseek (fp, 0L, SEEK_SET);
    i= ftell (fp);
    
    for (j=0;j<3;j++) {
	  j = fread (x, sizeof (student), 1, fp);
	  j = ftell(fp);
      printf ("ID: %s\n", x->id);
	  printf ("NAME: %s\n", x->name);
      printf ("MAJOR: %s\n", x->major);
      printf ("Number: %d\n", x->num);	
      printf ("\n");
    	
    }
	fclose(fp);
}

