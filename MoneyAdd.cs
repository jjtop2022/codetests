using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            double a, b, c;
            Console.WriteLine("Enter amount: ");
            a = float.Parse(Console.ReadLine());
            Console.WriteLine("Enter amount: ");
            b = float.Parse(Console.ReadLine());
            c = a + b;
            Console.WriteLine("Total: {0:f3}", c);

        }
    }
}
