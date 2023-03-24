using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace myCsharptest
{
    class Printout
    {
        
        public void printout()
        {
            int[] p = { 6, 7, 8, 57, 88 };
            Console.WriteLine("Printing out array: ");
            foreach (int i in p)
            {
                Console.Write("{0} ", i);
            }
            Console.WriteLine();
            for (int i = 0; i < p.Length; i++)
            {
                Console.Write("{0} ", p[i]);
            }
            Console.WriteLine();
        }

        // printout list
        public void listprint() {

            List<string> stringlist = new List<string>();
            stringlist.Add("test1");
            stringlist.Add("test2");
            stringlist.Add("test3");

            stringlist.Insert(0, "test0");

            foreach (string user in stringlist)
            {
                Console.Write("{0} ", user);
            } Console.WriteLine();

            stringlist.Reverse();
            foreach (string user in stringlist)
            {
                Console.Write("{0} ", user);
            } Console.WriteLine();

        }



    }

    class Program {

        static void Main(string[] args) {
            Console.WriteLine("testing");

            int[] p = { 6, 7, 8, 57, 88 };

            //foreach (int i in p) {
            //    Console.Write("{0} ", i);
            //}
            //Console.WriteLine();
            //for (int i = 0; i < p.Length; i++)
            //{
            //    Console.Write("{0} ", p[i]);
            //}
            //Console.WriteLine();

            Printout pp = new Printout();
            pp.printout();
            // printout list
            pp.listprint();
            

        }
    }
}
