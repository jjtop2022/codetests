#include <stdio.h>
#define MAXNUM 200
int getline(char line[], int maxline);
int numwords(char s[], int linelength);

int main () {

  char myline[MAXNUM];
  int length, numword;
  printf ("Enter a line, press enter to stop:\n");

  /* get line, then find number of words */
  length = getline(myline, MAXNUM);
  numword = numwords(myline,length);

  printf ("%d is the line length of: %s\n",length,myline);
  printf ("Number of words is: %d\n", numword);
}


/* read a line into s, return length */
int getline(char s[], int limit) {
	  int c, i;

	  for (i=0; i<limit-1 && (c=getchar())!='\n'; i++) {
  		  s[i] = c;
	  }
      if (c == '\n') {
      	 s[i] = c;
      	 i++;
      }
      s[i] = '\0';
      return i;
}

/* assume 1 space per word */
int numwords(char s[], int linelength) {
   int i, count=1;
   for (i=0; i<linelength; i++){
      if (s[i] == ' '){
        count++;
      }
   }
   return count;
}




