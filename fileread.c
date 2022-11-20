#include <stdio.h>
main () {
	FILE *fp;
    char lines[100];
    char *c;
    fp = fopen("testfile","r");
    
    if (fp == NULL) {
    	printf ("no file!");
    }else{
    	do {
	    	c = fgets(lines,100, fp);
	    	if (c != NULL){
		    	printf ("%s", lines);
		    }
	    }while(c != NULL);
    	
    }	
    fclose(fp);
}

