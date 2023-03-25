import java.util.Scanner;

public class Assign2{
     public static void main(String args[]){
    	 System.out.println("Enter 2 numbers:" );
    	 int a, b;
    	 Scanner input = new Scanner(System.in);
    	 a = input.nextInt();
    	 b = input.nextInt();
    	 int c = a+b;
    	 System.out.println("You entered: "+a+"+"+b+" "+"="+c);
     }
	
}
