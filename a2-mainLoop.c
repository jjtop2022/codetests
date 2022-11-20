#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100
#define NUMPROTEINS 64
//typedef enum boolean {false, true} bool;

bool isBasePair (char neu1, char neu2);
bool isItaDnaSequence (char strand1 [SIZE], char strand2 [SIZE]);
void reverse (char aStrand [SIZE]);
void complementIt (char aStrand [SIZE]);
bool isItPalindrome (char aStrand [SIZE]);
bool isStrandDnaPalindrome (char aStrand [SIZE]);
int howMany (char aStrand [SIZE], char neu);
void dnaToMrna (char aSeq [SIZE], char mRNA [SIZE]);
void translateDnaToMrnaProteins (char aSeq [SIZE]);

int main () {

       /****************************************/
       /* function 1 test */
       char seq1, seq2;
       printf ("Function 1 - Enter a char: ");
       seq1 = getchar();
       getchar();
       printf ("Enter another char: ");
       seq2 = getchar();

       printf ("seq1: %c, seq2: %c\n", seq1, seq2);
        bool testme;
        testme = isBasePair(seq1,seq2);
        if (testme == false){
            printf ("FALSE!\n");
        }else{
            printf ("TRUE!\n");
         }

          /****************************************/
          //function 2 test

          char test1[5], test2[5];
          printf ("Function 2 enter 2 sequences: ");
          scanf ("%s%s", test1, test2);
          printf ("test1: %s, test2 %s\n", test1,test2);
          bool b2;
          b2 = isItaDnaSequence(test1, test2);
          if (b2 == false){
            printf ("FALSE!\n");
          }else{
             printf ("TRUE!\n");
          }

          /***********************************/
          // function 3 test

          char stest[10];
          printf ("function 3 - enter a string for reversing\n");
          scanf ("%s", stest);
          reverse(stest);
          printf ("Reversed: %s\n", stest);

          /*************************************/
          /* function 4 test */
          char f4test[10];
          printf ("function 4 - enter a string for compliment: ");
          scanf ("%s", f4test);
          complementIt(f4test);
          printf ("Compliment: %s\n", f4test);


          /*************************************/
          /* function 5 test */
          char palind[SIZE];
          printf ("function 5 - enter a string to check palindrome: ");
          scanf ("%s", palind);
          bool b5;
          b5 = isItPalindrome(palind);
          if (b5 == true){
            printf ("%s It is a palindrome!\n", palind);
          }else{
            printf ("%s It is NOT a palindrome!\n", palind);
          }

          /* function 6 test */
          printf ("Function 6: -- test\n");
          bool b6;
          char test6[SIZE]="GGATCC";
          char test66[SIZE]="AT";
          char test662[SIZE]="AG";
          char test664[SIZE]="GGCCGG";
          b6 = isStrandDnaPalindrome(test6);
          if (b6 == true){
              printf ("%s is a DNAPalindrome!\n", test6);
          }else{
              printf ("%s Not a DNA Palindrome!\n", test6);
          }
          b6 = isStrandDnaPalindrome(test66);
            if (b6 == true){
              printf ("%s is a DNAPalindrome!\n", test66);
          }else{
              printf ("%s Not a DNA Palindrome!\n", test66);
          }
          b6 = isStrandDnaPalindrome(test662);
          if (b6 == true){
              printf ("%s is a DNAPalindrome!\n", test662);
          }else{
              printf ("%s Not a DNA Palindrome!\n", test662);
          }
          b6 = isStrandDnaPalindrome(test664);
          if (b6 == true){
              printf ("%s is a DNAPalindrome!\n", test664);
          }else{
              printf ("%s Not a DNA Palindrome!\n", test664);
          }


          /* function 7 test */
          //char strand7[SIZE];
          printf ("Function 7 - testing a strand: \n");
          //scanf("%s", strand7);
          int countme = howMany("GGCCGGGG", 'G');
          printf ("Count: %d\n", countme);
          countme = howMany("GGCCCCGG", 'C');
          printf ("Count 2: %d\n", countme);
          countme = howMany("TTTCCT", 'T');
          printf ("Count 3: %d\n", countme);

          /**** function 8 ********/
          char tempstring1[SIZE]="";
          dnaToMrna("CGTAGGCAT", tempstring1);
          printf ("FUNCTION 8: %s %s\n", "CGTAGGCAT", tempstring1);
          char temp2[SIZE];
          dnaToMrna("CATG", temp2);
          printf ("FUNC 8: %s %s\n","CATG",temp2);

          /***** function 9 ********/
        printf ("Function 9:\n");
        translateDnaToMrnaProteins ("CGTAGGCAT");
        translateDnaToMrnaProteins ("CACGC");
        translateDnaToMrnaProteins ("CAXGC");


}

/****************************/
/*****  FUNCTIONS BELOW *****/
char getCode (char protein [3]) {

    // array allProteins has a list of all 3-triplet amino acids required for this assignment
    char allProteins [NUMPROTEINS][SIZE] = {"GCA", "GCC", "GCG", "GCU", "AGA","AGG", "CGA", "CGC","CGG","CGU","GAC", "GAU","AAC","AAU","UGC","UGU","GAA","GAG","CAA","CAG", "GGA", "GGC","GGG","GGU","CAC", "CAU","AUA","AUC","AUU", "UUA", "UUG","CUA","CUC", "CUG", "CUU", "AAA", "AAG","AUG", "UUC","UUU", "CCA", "CCC", "CCG", "CCU", "AGC","AGU","UCA","UCC","UCG", "UCU","ACA","ACC","ACG", "ACU", "UGG","UAC","UAU", "GUA","GUC","GUG", "GUU"};

    // array allCodes stores the single-letter code of each triplet given in the above array
    char allCodes [NUMPROTEINS] = {'A','A','A','A','R','R','R','R','R','R','D','D','N','N','C','C','E','E','Q','Q', 'G','G','G','G','H','H','I','I','I', 'L','L','L','L','L','L','K','K','M','F','F','P','P','P','P','S','S','S','S','S','S','T','T','T','T', 'W','Y','Y','V','V','V','V'};

    int i;
    for ( i = 0; i < NUMPROTEINS; i++) {

        if  (strncmp (protein, allProteins[i], 3) == 0){
            return allCodes [i];
        }
    }

    return 'Z';   // to indicate an incorrect code - code that doesn't exist in array allCodes
}


/************************************/
/* Function 1 */
bool isBasePair(char neu1, char neu2){
    // check if A, T and C, G are base pairs
    if (neu1 == 'A' && neu2 == 'T'){
        return true;
    }else if (neu1 == 'C' && neu2 == 'G'){
        return true;
    }else if (neu1 == 'T' && neu2 == 'A'){
        return true;
    }else if (neu1 == 'G' && neu2 == 'C'){
        return true;
    }else{
        return false;
    }

}

/**************************************/
/* Function 2 */
bool isItaDnaSequence (char strand1 [SIZE], char strand2 [SIZE]) {

    /* copy first strand into temp1 variable, then add strand2 to the variable */
     char temp1[SIZE]="";

     strcpy(temp1,strand1);

     strcat(temp1,strand2);

     /* check if A, T, C, G are all there then return true */
     if (strchr(temp1, 'A') != NULL && strchr(temp1,'T') != NULL
         && strchr(temp1,'C')!= NULL && strchr(temp1,'G') != NULL){
          return true;
     }else{
          return false;
     }

}

/***************************************/
/* Function 3 - reverse the string */
void reverse (char aStrand [SIZE]){
  int len = strlen (aStrand);
  char temp[SIZE]="";
  int i, j=0;
  for (i=len-1;i>=0;i--){
       temp[j] = aStrand[i];
        j++;
  }

  strcpy(aStrand,temp);

}

/************************************/
/* function 4 */
void complementIt (char aStrand [SIZE]){

 /* A becomes T, C becomes G, G becomes C, T becomes A */
 int len = strlen (aStrand);

  /* loop through the string and change accordingly */
  int i;
  for (i=0;i<len;i++){
        if (aStrand[i]== 'A'){
            aStrand[i] = 'T';
        }else if (aStrand[i] == 'T') {
            aStrand[i] = 'A';
        }else if (aStrand[i] == 'C'){
            aStrand[i] = 'G';
        }else if (aStrand[i] == 'G'){
            aStrand[i] = 'C';
        }
  }

}

/*************************************/
/*  function 5 */
bool isItPalindrome (char aStrand [SIZE]){
    /* copy reverse into temp string */
    int len = strlen (aStrand);
    char temp[SIZE]="";
    int i, j=0;
    for (i=len-1;i>=0;i--){
       temp[j] = aStrand[i];
        j++;
  }
  /* compare if they are the same */
  if (strcmp(temp,aStrand) == 0) {
    /* it is a palindrome */
    return true;
  }else{
    /* It is not a palindrome */
    return false;
  }

}

/*************************************/
/* function 6 */
/* Use function 4 to check if complimentary pair
   Use the palindrome function above to check if palindrome
   */
bool isStrandDnaPalindrome (char aStrand [SIZE]){
   /* get complement of aStrand using function 4 */
   char oldStrand[SIZE]="";
   strcpy(oldStrand,aStrand);
   char aCompliment[SIZE]="";
   complementIt(aStrand);
   strcpy(aCompliment,aStrand);
   printf ("Original: %s, compliment %s\n",oldStrand, aCompliment);

   /* reverse the compliment and check if the same, then true
      otherwise return a false - use function 3*/

   reverse(aCompliment);

   /* Now compare if the string are the same */
   if (strcmp(oldStrand, aCompliment) == 0){
       return true;
   }else{
       return false;

   }

}

/*************************************/
/* function 7 */
int howMany (char aStrand [SIZE], char neu){
   /* returns number of chars in neu contained in aStrand */
   int i, count=0;
   int len = strlen(aStrand);
   for (i=0;i<len;i++){
      if (aStrand[i] == neu){
        count++;
      }
   }
   return count;

}

/**************************************/
/* function 8 */
void dnaToMrna (char aSeq [SIZE], char mRNA [SIZE]){

   /* Use the complementIT function from function 4 */
   char tempstring1[SIZE]="";
   strcpy(tempstring1, aSeq);
   complementIt(tempstring1);

   /* Now change any T's to U's */
   int i;
   int len = strlen(tempstring1);
   for (i=0;i<len;i++){
       if (tempstring1[i] == 'T') {
            tempstring1[i] = 'U';
       }
   }

   /* Copy the result into second parameter */
   strcpy(mRNA,tempstring1);

}


/**************************************/
/* function 9 */
void translateDnaToMrnaProteins (char aSeq [SIZE]){
   /* 1. printout DNA first */
   printf ("DNA: %s\n", aSeq);
   /* 2. Get the corresponding Mrna sequence using function 8 */
   char mtemp[SIZE]="";
   dnaToMrna(aSeq,mtemp);
   /* printout mrna sequence */
   printf ("mRNA: %s, which translates to:\n", mtemp);

   /* Get getcode to translate amino acids */
   int len = strlen(mtemp);
   int i;
   int numtimes = len/3;

   int holder=0;

   /* split the string into 3 chars long each time */
   for (i=0;i<numtimes;i++){
       int j;
       char temp3[3]="";

       /* get 3 chars at a time from the mRNA string and copy */
       for (j=0;j<3;j++){
            temp3[j] = mtemp[holder];
            holder++;
       }
       char s1;
       s1 = getCode(temp3);
       printf ("%s : %c\n", temp3, s1);
       if (s1 == 'Z'){
           printf ("The input sequence has an incorrect base.\n");
       }
   }
   printf ("\n");

}





