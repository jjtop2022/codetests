using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        const int N=6;
        const int M=10;
        static void Main(string[] args)
        {
            int [,] a = new int[M+1,N+1];
            int [,] b = {{1,1,1,1},{2,2,2,2},{3,3,3,3}};
            
            for (int v=0;v<3;v++) {
                for (int w=0;w<4;w++) {
                    Console.Write("{0} ",b[v,w]);
                }
                Console.WriteLine();
            }
            foreach (int z in b)
            {
                Console.Write("{0} ", z);
            }
            Console.WriteLine();


            for (int i = 0; i <= M; i++)
            {
                for (int j = 0; j <=N; j++){
                    a[i,j] = i + j;
                }
            }
            for (int i = 1; i <= M; i++)
            {
                for (int j = 1; j <= N; j++)
                {
                    Console.Write("{0}+{1}={2} ", i, j, a[i, j]);
                }
                Console.WriteLine();
            }


        }
    }
}
