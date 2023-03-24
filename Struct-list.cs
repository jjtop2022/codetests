using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    struct STUDENT {
        public string myname;
        public int age;
        public string major;
        public double grade;
    }
    class Program
    {
        public void addstudent(ref STUDENT s,string newname, int newage, string newmajor, double newgrade)
        {
            s.myname = newname; s.age = newage; s.major = newmajor; s.grade = newgrade;
        }
        public void display(STUDENT s) {
            Console.WriteLine("Name:"+s.myname + " Age:" + s.age + " Major:" + s.major + " Grade:" + s.grade);
        }

        public void changemajor(ref STUDENT s, string newmajor)
        {
            s.major = newmajor;
            Console.WriteLine("major changed to: {0}", newmajor);
        }
        void printstu(ArrayList stulist)
        {
            foreach (STUDENT slist in stulist)
            {
                display(slist);
            }
            Console.WriteLine();
        }

     static void Main(string[] args)
     {
         ArrayList ar = new ArrayList();
         STUDENT s0 = new STUDENT(){myname = "John",age = 23,major = "CS",grade=78.5};
         STUDENT s1 = new STUDENT(){myname = "Lisa",age = 21, major = "CS",grade=89.5};
         STUDENT s2 = new STUDENT(){myname = "Jenny",age = 22, major = "CS",grade=67.2};
         STUDENT s3 = new STUDENT();
         STUDENT s4 = new STUDENT() { myname = "Henry", age = 24, major = "MIS", grade = 87.2 };
         //s3.myname = "Hihi"; s3.age = 24; s3.major = "MIS"; s3.grade = 89.5;
         Program pp = new Program();
         pp.addstudent(ref s3, "James", 22, "MIS", 78.5);
         ar.Add(s0); ar.Add(s1); ar.Add(s2); ar.Add(s3);
         pp.printstu(ar);

         ar.Reverse();
         pp.printstu(ar);

         ar.Insert(0, s4);
         pp.printstu(ar);

         ///////////////////////////////
         List<STUDENT> lstu = new List<STUDENT>();
         lstu.Add(s0); lstu.Add(s1); lstu.Add(s2); lstu.Add(s3);
         Console.WriteLine();
         //pp.printstu(lstu);

         lstu.Insert(3, s4);
         Console.WriteLine();
         foreach (STUDENT slist in lstu)
         {
             pp.display(slist);
         }
         lstu.Reverse();
         Console.WriteLine();
         foreach (STUDENT slist in lstu)
         {
             pp.display(slist);
         }



        }
    }
}
