using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            //input output
            int a; string name;
            Console.WriteLine("Enter age: ");
            a = int.Parse(Console.ReadLine());
            Console.WriteLine("Your age is: {0}", a);

            Console.WriteLine("Enter name: ");
            name = Console.ReadLine();
            Console.WriteLine("Your name is: {0}", name);
            Console.WriteLine("Your name is: {0}, your age is: {1}", name, a);


            //array
            int [] b = {4,3,45,67};

            foreach (int i in b)
            {
                Console.Write("{0} ", i);
            } Console.Write("\n");

            for (int i = 0; i < b.Length; i++)
            {
                Console.Write("{0} ", b[i]);
            } Console.Write("\n");

            int j=0;
            while (j < b.Length)
            {
                Console.Write("{0} ", b[j]);
                j++;
            } Console.Write("\n");

            /////////////////////////////////////////
            /////////////////////////////////////////
            // 2. string test
            string aa = "abc";
            string bb = "abcd";
            string cc = "cccc";

            //1. compare
            if (string.Compare(aa, bb) == 0)
            {
                Console.WriteLine("same");
            }

            //2. replace
            string z = bb.Replace("ab", "de");
            Console.WriteLine(z);

            //3. insert
            string y = cc.Insert(1,"aa");
            Console.WriteLine(y);

            //4. add, concat
            string x = string.Concat(cc,"cc");
            Console.WriteLine(x);

            //5. remove
            string xx = bb.Remove(0,2);
            Console.WriteLine(xx);

            //6. adding string
            cc = cc + aa;
            Console.WriteLine(cc);


        }
     }
}
