using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[1000001];

            long min, max, num = 0;
            long smax, i, j;
            string s = Console.ReadLine();
            string[] ss = s.Split();

            min = Convert.ToInt64(ss[0]);
            max = Convert.ToInt64(ss[1]);

            smax = (long)Math.Sqrt((double)max);

            for (i = 2; i <= smax; i++)
            {
                for (j = 2 * i; j <= smax; j += i)
                {
                    if (arr[i] == 0)
                        arr[j]++;
                    else if (arr[i] > 1)
                        arr[j]--;
                }

                num -= (max / (i * i) - (min - 1) / (i * i)) * (arr[i] - 1);
            }

            Console.WriteLine(Convert.ToString(max - min - num + 1));
        }
    }
}
