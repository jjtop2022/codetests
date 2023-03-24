using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    struct STUDENT
    {
        public string name;
        public int age;
        public string major;
    }
    class Program
    {
        public void printstudent(STUDENT s)
        {
            Console.WriteLine("NAME:{0}, AGE:{1}, MAJOR:{2}", s.name, s.age, s.major);
        }

        static void Main(string[] args)
        {
            

            STUDENT s1 = new STUDENT() { name = "test12", age = 23, major = "CS" };
            STUDENT s2 = new STUDENT() { name = "test2", age = 23, major = "CS" };
            STUDENT s3 = new STUDENT() { name = "test1", age = 21, major = "CS" };

            List<STUDENT> liststu = new List<STUDENT>();
            liststu.Add(s1); liststu.Add(s2);liststu.Add(s3);
            liststu.Add(s1); liststu.Add(s2);

            Program pp = new Program();
            pp.printstudent(s1);
            pp.printstudent(s2);
            Console.WriteLine();

            foreach (STUDENT s in liststu)
            {
                pp.printstudent(s);
            }
            Console.WriteLine(liststu.Count);
            liststu.Reverse();

            foreach (STUDENT s in liststu)
            {
                pp.printstudent(s);
            }


        }
    }
}
