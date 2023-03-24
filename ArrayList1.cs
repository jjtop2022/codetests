using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        public void printout(ArrayList aa)
        {
            foreach (string s in aa)
            {
                Console.Write("{0} ", s);
            } Console.WriteLine();
            Console.WriteLine("count:{0} ", aa.Count);
        }

        static void Main(string[] args)
        {
            Program pp = new Program();

            ArrayList aa = new ArrayList();
            aa.Add("dog"); aa.Add("cat"); aa.Add("turtle"); aa.Add("fox"); aa.Add("rabbit");
            pp.printout(aa);

            aa.Insert(aa.Count, "lion");
            pp.printout(aa);

            aa.Remove("rabbit");
            pp.printout(aa);

            aa.RemoveAt(1);
            pp.printout(aa);

            aa.Sort();
            pp.printout(aa);

            aa.Reverse();
            pp.printout(aa);

            aa.Clear();
            pp.printout(aa);

        }
    }
}
