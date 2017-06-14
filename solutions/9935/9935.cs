using System;
using System.Text;

class Program
{
    static void Main(string[] args)
    {
        string str = Console.ReadLine();
        string bomb = Console.ReadLine();
        int length = str.Length;

        StringBuilder stack = new StringBuilder(str.Length);

        foreach (var c in str)
        {
            stack.Append(c);

            if (stack.Length >= bomb.Length)
            {
                int pos = 0;
                while (pos < bomb.Length)
                {
                    if (bomb[pos] != stack[stack.Length - bomb.Length + pos])
                        break;

                    pos++;
                }

                if (pos == bomb.Length)
                {
                    stack.Length = stack.Length - bomb.Length;
                }
            }
        }

        if (stack.Length == 0)
            Console.WriteLine("FRULA");
        else
            Console.WriteLine(stack.ToString());
    }
}