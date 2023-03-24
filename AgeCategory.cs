using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                string myage;
                int age;
                Console.WriteLine("Enter your age: ");
                myage = (Console.ReadLine());

                if (!int.TryParse(myage, out age))
                {
                    Console.WriteLine("age numbers only!");
                }
                //////////////////////////////////////////
                //1.  exit loop
                if (age == 9999)
                {
                    Console.WriteLine("finished\n");
                    break;
                }
                ///////////////////////////////////////////
                if (age >= 0 && age <= 6)
                {
                    Console.WriteLine("are you {0} old, you are young kids", age);
                }
                else if (age >= 7 && age <= 18)
                {
                    Console.WriteLine("are you {0} old, you are child", age);
                }
                else if (age >= 19 && age <= 30)
                {
                    Console.WriteLine("are you {0} old, you are young adult", age);
                }
                else if (age >= 31 && age <= 60)
                {
                    Console.WriteLine("are you {0} old, you are working adult", age);
                }
                else if (age > 60 && age <= 120)
                {
                    Console.WriteLine("are you {0} old, you are retired", age);
                }
                else
                {
                    Console.WriteLine("Invalid age!\n");
                }

            }


        }
    }
}
