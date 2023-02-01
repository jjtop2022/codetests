#include <stdio.h>

int main () {

    /************************************************************/
    /* This is the main loop,  it is a forever loop and it will only exit when the user
       decides to enter n and not continue */
    while (1) {

        /*************************************************************/
        /* User makes a choice, the valid choices are 0 to 9, otherwise
           it will print a message saying invalid choice */
        int choice;
        printf ("Enter 0 to see all multiplication tables from 1 - 9 OR\n\n ");
        printf ("Enter a number between 1 and 9 to see its multiplication table\n");
        printf ("Enter a choice: ");
        scanf ("%d", &choice);


        if (choice == 0){
            /* User choose 0, printout entire multiplication table, the for loops
               printout each number and its multiplication value from
               1 to 9, then we print newline, repeat until we get to nine */
            printf ("-------- Printing Multiplication Tables 1 - 9 ---------\n");
            printf ("********************************************************************************\n");
            printf ("\tOne\tTwo\tThree\tFour\tFive\tSix\tSeven\tEight\tNine\n");
            printf ("\n");
            int i;
            printf ("One\t");
            for (i=1;i<=9;i++){
                printf ("%4d \t",1*i);
            }
            printf ("\n");

            printf ("Two\t");
            for (i=1;i<=9;i++){
                printf ("%4d \t",2*i);
            }
            printf ("\n");

            printf ("Three\t");
            for (i=1;i<=9;i++){
                printf ("%4d \t",3*i);
            }
            printf ("\n");

            printf ("Four\t");
            for (i=1;i<=9;i++){
                printf ("%4d \t",4*i);
            }
            printf ("\n");

            printf ("Five\t");
            for (i=1;i<=9;i++){
                printf ("%4d \t",5*i);
            }
            printf ("\n");

            printf ("Six\t");
            for (i=1;i<=9;i++){
                printf ("%4d \t",6*i);
            }
            printf ("\n");

            printf ("Seven\t");
            for (i=1;i<=9;i++){
                printf ("%4d \t",7*i);
            }
            printf ("\n");

            printf ("Eight\t");
            for (i=1;i<=9;i++){
                printf ("%4d \t",8*i);
            }
            printf ("\n");

            printf ("Nine\t");
            for (i=1;i<=9;i++){
                printf ("%4d \t",9*i);
            }
            printf ("\n");

            printf ("********************************************************************************\n");
            printf ("\n");

        /*****************************************************/
        /* From here on, we print each multiplication table depending on
           the user choice, we print from 1 -9 */
        }else if (choice == 1){
            printf ("Printing multiplication tables  1 \n");
            int i;
            for (i=1;i<=9;i++) {
                printf ("1 x %d = %d\n", i, 1*i);
            }


        }else if (choice == 2){
            printf ("Printing multiplication tables  2 \n");
            int i;
            for (i=1;i<=9;i++) {
                printf ("2 x %d = %d\n", i, 2*i);
            }

        }else if (choice == 3){
           printf ("Printing multiplication tables  3 \n");
            int i;
            for (i=1;i<=9;i++) {
                printf ("3 x %d = %d\n", i, 3*i);
            }

        }else if (choice == 4){
            printf ("Printing multiplication tables  4 \n");
            int i;
            for (i=1;i<=9;i++) {
                printf ("4 x %d = %d\n", i, 4*i);
            }

        }else if (choice == 5){
            printf ("Printing multiplication tables  5 \n");
            int i;
            for (i=1;i<=9;i++) {
                printf ("5 x %d = %d\n", i, 5*i);
            }

        }else if (choice == 6){
            printf ("Printing multiplication tables  6 \n");
            int i;
            for (i=1;i<=9;i++) {
                printf ("6 x %d = %d\n", i, 6*i);
            }

        }else if (choice == 7){
           printf ("Printing multiplication tables  7 \n");
            int i;
            for (i=1;i<=9;i++) {
                printf ("7 x %d = %d\n", i, 7*i);
            }

        }else if (choice == 8){
            printf ("Printing multiplication tables  8 \n");
            int i;
            for (i=1;i<=9;i++) {
                printf ("8 x %d = %d\n", i, 8*i);
            }

        }else if (choice == 9){
            printf ("Printing multiplication tables  9 \n");
            int i;
            for (i=1;i<=9;i++) {
                printf ("9 x %d = %d\n", i, 9*i);
            }

        }else{
            printf ("Invalid number.\n");
        }

        char cc;
        printf ("Do you wish to continue? ");
        getchar();
        cc = getchar();
        if (cc == 'n'){
            break;
        }
        printf ("\n");


    }


}
