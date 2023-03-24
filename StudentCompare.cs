using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        // IComparable - for sorting
        class Student : IComparable
        {
        public Student(string nname, int nage, string nmajor, double ngrade)
        {
            myname = nname; age = nage; major = nmajor; grade = ngrade;
        }
        public void pprint()
        {
            Console.WriteLine("NAME:"+myname + " AGE:"+age + " MAJOR:"+major+" GRADE:" + grade);
        }

        public int CompareTo(object obj)
        {
            Student temp = (Student)obj;
            if (this.grade < temp.grade)
                return -1;
            else if (this.grade > temp.grade)
                return 1;
            else
                return 0;
        }
        string myname;
        int age;
        string major;
        double grade;
    }

    static void display(ArrayList stulist) {
       Console.WriteLine("Show Student: ");

       foreach (Student s in stulist,string mesg)
       {
           Console.WriteLine(mesg);
           s.pprint();
       }
    }

     static void Main(string[] args)
     {
            Student s1 = new Student("jenny", 23, "CS", 97.8);
            Student s2 = new Student("lisa", 22, "Accounting", 57.7);
            Student s3 = new Student("hank", 21, "CS", 87.2);
            s3.pprint();
            /////////////// put into ArrayList ////////////////
            ArrayList ss = new ArrayList();
            ss.Add(s1); ss.Add(s2); ss.Add(s3);
            display(ss,"UNSORTED");
            ss.Sort();
            display(ss, "SORTED");
            ss.Reverse();
            display(ss, "REVERSE");
            
        }
    }
}
