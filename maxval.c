#include <stdio.h>
 
main()
{
  int a[100], max, size, c, location = 1;
 
  printf("Enter number of int in array\n");
  scanf("%d", &size);
 
  printf("Enter %d integers\n", size);
  for (c = 0; c < size; c++){
    scanf("%d", &a[c]);
  }
  max = a[0];
 
  for (c = 1; c < size; c++){
    if (a[c] > max){
       max  = a[c];
       location = c+1;
    }
  }
   printf("Max element at %d and it's value is %d.\n", location, max);
}

