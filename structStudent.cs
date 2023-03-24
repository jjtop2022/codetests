using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace myCsharptest
{

    // student information
    struct Students
    {
        public string Name;
        public int Age;
        public string Major;
        public int ID { get; set; }
    }

    class Printout {
        
        public void printout() {
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
        public void listprint(){

            List<string> stringlist = new List<string>();
            stringlist.Add("test44");
            stringlist.Add("test2");
            stringlist.Add("test34");

            stringlist.Insert(0, "test0");

            foreach (string user in stringlist)
            {
                Console.Write("{0} ", user);
            } Console.WriteLine();

            //reverse list
            stringlist.Reverse();
            foreach (string user in stringlist)
            {
                Console.Write("{0} ", user);
            } Console.WriteLine();

            //sort list
            stringlist.Sort();
            foreach (string user in stringlist)
            {
                Console.Write("{0} ", user);
            } Console.WriteLine();

        }
        // print student list
        public void printstudent()
        {
            //initialize students
            List<Students> studentlist = new List<Students>() {
                new Students() {Name="Jenny W",Age=23,Major="CSC",ID=56565},
                new Students() {Name="Harry X",Age=23,Major="CS",ID=76565},
                new Students() {Name="John",Age=22,Major="SE",ID=66565},
                new Students() {Name="Goo",Age=21,Major="EE",ID=86565},
            };
            // print students
            for (int i = 0; i < studentlist.Count; i++)
            {
                Console.WriteLine("Name:\t" + studentlist[i].Name + "\tAge:" + studentlist[i].Age +
                    "\tMajor: " + studentlist[i].Major + "\tID: " + studentlist[i].ID);
            } Console.WriteLine();

            //sort students
            //studentlist.Sort(); 
            for (int i = 0; i < studentlist.Count; i++)
            {
                Console.WriteLine("Name: " + studentlist[i].Name + " Age: " + studentlist[i].Age +
                    " Major: " + studentlist[i].Major + " ID: " + studentlist[i].ID);
            }
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
            pp.printstudent();


        }
    }

   

}
