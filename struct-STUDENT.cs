using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication2
{
    struct STUDENT
    {
        public string name;
        public int age;
        public string major;
    }

    class Program
    {
        
        public void printstudent(STUDENT s1)
        {
            for (int i = 0; i < num; i++)
            {
                Console.WriteLine("NAME:{0}, AGE:{1}, MAJOR:{2}", s1.name, s1.age, s1.major);
            }
        }
        static void Main(string[] args)
        {
            List<STUDENT> slist = new List<STUDENT>() {
                new STUDENT() {name="Jenny W",age=23,major="CSC"},
                new STUDENT() {name="Harry X",age=23,major="CS"},
                new STUDENT() {name="John",age=22,major="SE"},
                new STUDENT() {name="Goo",age=21,major="EE"},
            };

           
            STUDENT s0 = new STUDENT() { name = "John", age = 23, major = "CS" };
            STUDENT s1 = new STUDENT() { name = "Lisa", age = 21, major = "CS" };
            STUDENT s2 = new STUDENT() { name = "Jenny", age = 22, major = "CS" };

            Program pp = new Program();
            pp.printstudent(s0);
            pp.printstudent(s1);
            pp.printstudent(s2);


        }
    }
}
