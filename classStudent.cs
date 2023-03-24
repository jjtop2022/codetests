using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace myCsharptest
{

    // student information
    class Students {
       
        public Students(string N="none", int a=0, string M="nomajor", int nID=99999)
        {
            Name = N;
            Age = a;
            Major = M;
            ID = nID;
        }
        ~Students()
        {
            Console.WriteLine("destructor");
        }

        public void addstudent(string N, int a, string M, int nID) {
            Name = N;
            Age = a;
            Major = M;
            ID = nID;
        }
        public void printstudents() {
            Console.WriteLine("Name: " + Name + "\tAge: "+ Age+"\tMajor: "+Major + "\tID: "+ID);
         }

        public void changemajor(string newmajor)
        {
            Major = newmajor;
            Console.WriteLine("Major changed to: " + newmajor);
        }
         
        //private variables
        string Name;
        public int Age; //public variable
        string Major;
        int ID;
    }

    class Program {

        static void Main(string[] args) {

            Students s1 = new Students("Jenny W", 23, "CSC", 56565);
        
            //Age is made public
            s1.Age = 21;
            s1.printstudents();
            s1.changemajor("Account ");
            s1.printstudents();

            Students s2 = new Students();
            s2.printstudents();
            s2.addstudent("Joe W", 22, "EE", 73445);
            s2.printstudents();


        }
    }

   

}
