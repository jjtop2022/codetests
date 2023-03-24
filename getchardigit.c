
#include <stdio.h>

int main() {
	
  int num =0, num2 = 0;
  int c;
  puts ("Enter some letters, Enter to stop: ");
  
  while ((c = getchar()) != '\n') {
  	  num++;
  	  if (c >= '0' && c <= '9') {
  	     puts ("it is a digit");
  	     num2++;
  	  }
  }
   printf ("You entered %d total characters and %d digits\n", num, num2);

  
}


