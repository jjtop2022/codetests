using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Rectangle
    {
        // member variables
        double length;
        double width;

        public Rectangle(double len, double wid)
        {
            length = len; width = wid;
        }
        
        public double GetArea()
        {
            return length * width;
        }

        public void Display()
        {
            Console.WriteLine("Length: {0}", length);
            Console.WriteLine("Width: {0}", width);
            Console.WriteLine("Area: {0}", GetArea());
        }
    }
  
    class Program
    {
        static void Main(string[] args)
        {
            double len, width;
            Console.WriteLine("Enter length width: ");
            len = double.Parse(Console.ReadLine());
            width = double.Parse(Console.ReadLine());
            Rectangle r = new Rectangle(len, width);
             r.Display();
            
        }
    }
}
