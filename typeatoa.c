#include <stdio.h>
#include <stdlib.h>
main()
{
	
	//casting
	float x;
	x = 3/5;
	printf ("%f\n",x);
	
    //itoa
	int a=64565;
    char buffer[20];
    itoa(a,buffer,2);   // here 2 means binary
    printf("Binary value = %s\n", buffer);
    itoa(a,buffer,10);   // here 10 means decimal
    printf("Decimal value = %s\n", buffer);
    
    //atof
    char ap[10] = "3.14";
    float pi = atof(ap);
    printf("Value of pi = %f\n", pi);
    
    //atoi
    char aa[10] = "100";
    int value = atoi(aa);
    printf("Value = %d\n", value);


}

