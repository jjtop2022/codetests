using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    public class Rectangle
    {
        public Rectangle(double w = 0, double l = 0)
        {
            width = w;
            length = l;
        }
       
        public void printarea()
        {
            Console.WriteLine("width:{0}, length:{1} = Area:{2}", width, length, getarea());
        }
        public virtual double getarea()
        {
            double total = width * length;
            return total;
        }

        protected double width;
        double length;

    }

    public class Circle : Rectangle
    {
        public Circle(double r) : base(r, 0) { }

        public override double getarea()
        {
            return 3.14 * width * width * width;
        }
    }

 
    class Program
    {
        static void Main(string[] args)
        {
            double len, wid;
            Console.Write("Enter width: ");
            wid = double.Parse(Console.ReadLine());
            Console.Write("Enter Length: ");
            len = double.Parse(Console.ReadLine());

            Rectangle r = new Rectangle(wid,len);
            r.printarea();
            Console.WriteLine("Total area: {0}", r.getarea());

            Rectangle rc = new Circle(wid);
            Console.WriteLine("Circle area:{0}",rc.getarea());


        }
    }
}
