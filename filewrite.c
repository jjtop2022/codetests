#include <stdio.h>
main (){
     FILE *fp;
    //read a file
    char text[50];
	printf ("enter text: ");
	gets(text);
	fp = fopen("testfile","a");
	
	if (fp == NULL){
		printf ("no file!");
	}else{
	   fprintf(fp,"%s\n",text);
	}
	
    fclose(fp);

}

