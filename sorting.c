#include <stdio.h>
#define MAX 10

void printme(int a[]){
   int i;
   for (i=0;i<MAX;i++){
       printf ("%d ", a[i]);
   }
   printf ("\n");
}
void printme2(char b[]){
   int i;
   for (i=0;i<MAX;i++){
      printf ("%c ",b[i]);
   }
   printf ("\n");
}

void swapme(int *a, int *b){
    int t= *a;
    *a = *b;
    *b = t;
}
void sortme(int a[]){
  int i, j;
  for (i=0;i<MAX;i++){
    for (j=1;j<MAX;j++){
       if (a[j-1] > a[j]){
             //swap
             swapme(&a[j-1], &a[j]);
       }
    }
  }
}
void sortme2(char b[]){
   int i,j;
   for (i=0;i<MAX;i++){
      for (j=1;j<MAX;j++) {
          if (b[j-1] > b[j]){
              char t = b[j-1];
              b[j-1] = b[j];
              b[j] = t;
          }
      }
   }
}

int main () {
    int a[] = {76,9,87,900,1,3,765,896,2,5};
    char b[]="ztyhagdjeb";

    printf ("not sorted:\n");
    printme(a);
    printme2(b);

    sortme(a);
    sortme2(b);

    printf ("sorted:\n");
    printme(a);
    printme2(b);

}
