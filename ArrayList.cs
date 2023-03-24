using System;
using System.Collections;
using System.Linq;
using System.Text;

namespace ConsoleApplication1 {

    // main driver program
    class Program
    {
        //driver main
        static void Main(string[] args)
        {
            ArrayList aa = new ArrayList();
            aa.Add("aaaa");
            aa.Add("43");
            aa.Add("555");
            aa.Add("455");
            aa.Add("zzzz");
            foreach (string s in aa)
            {
                Console.Write("{0} ", s);
            } Console.WriteLine();

            aa.Sort();
            foreach (string s in aa)
            {
                Console.Write("{0} ", s);
            } Console.WriteLine();
            aa.Remove("455");
            foreach (string s in aa)
            {
                Console.Write("{0} ", s);
            } Console.WriteLine();
            aa.RemoveAt(0);
            foreach (string s in aa)
            {
                Console.Write("{0} ", s);
            } Console.WriteLine();



        }
    }


}
