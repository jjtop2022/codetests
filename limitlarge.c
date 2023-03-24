#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
	
  int sum = 1;
  int count=0;
  puts ("Enter some letters, Enter to stop: ");
  
  while (count < 16) {
  	 sum = sum * 2;
  	 count++;
  	 printf ("count: %d\n",count);
  }
   printf ("sum: %d \n", sum);
   
   printf ("largest char: %d\n",CHAR_MIN); 
   printf ("largest dec: %d\n", SHRT_MAX);
   printf ("smallest dec: %d\n", SHRT_MIN);
   
   printf ("%.2f\n", 12.8886);
   char mystring[]= "aa67";
   printf ("%15s\n", mystring);
   printf ("%10s\n","aaa");
   
  
}


   
   
   
