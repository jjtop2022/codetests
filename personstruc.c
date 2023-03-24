#include <stdio.h>
#define MAXNUM 50

struct student {
   char id[MAXNUM];
   char name[MAXNUM];
   char major[MAXNUM];
   int num;
};
	
	
main () 
{
   int i;
   struct student s1[3];
 
	 for (i=0;i<3;i++){
		   printf ("Enter student information:\n");
		   printf ("Enter ID: ");
		   gets(s1[i].id);
		   printf ("Enter name: ");
		   gets(s1[i].name);
		   printf ("Enter major: ");
		   gets(s1[i].major);
		   s1[i].num=i;
	 }
 
	 for(i=0;i<3;i++){
		   printf ("\nShow information:\n");
		   printf ("Name: %s\n",s1[i].name);
		   printf ("ID: %s\n",s1[i].id);
		   printf ("Major: %s\n", s1[i].major);
		   printf ("number: %d\n",s1[i].num);
		   printf ("\n");
	}

}
