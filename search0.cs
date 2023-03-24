using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace myCsharptest
{
   
    // search class
    class search1 {
        //printout array
        public void printout(string[] n)
        {
            foreach (string i in n)
            {
                Console.Write("{0} ", i);
            }
            Console.WriteLine();
        }
        // search
        public void searchme(string[] n, string name){
            int found = 0;
            foreach (string i in n)
            {
                if (name.Equals(i))
                {
                    found = 1;
                }
            }
            if (found == 1){
                Console.WriteLine("Found your name: " + name);
            }
            else{
                Console.WriteLine("Not found your name: " + name);
            }
        }

    }

    class Program {

        static void Main(string[] args) {

                string myname;
                string[] names = { "aaa", "bbb", "ccc", "ddd", "eee" };
                // create object
                search1 s = new search1();
                s.printout(names);

                while (true) {
                    Console.Write("Enter string to search: ");
                    myname = Console.ReadLine();
                    if (myname == "quit")
                    {
                        Console.WriteLine("quit program");
                        break;
                    }
                    s.searchme(names, myname);
            }

        }
    }

   

}
