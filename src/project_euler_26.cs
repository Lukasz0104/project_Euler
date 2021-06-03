using System;
using System.Collections.Generic;

namespace pe26
{
    class Program
    {
        static int CycleLength(int den)
        {
            List<int> previousRemainders = new List<int>();

            int num = 1;

            while (num < den)
                num *= 10;

            int remainder = num % den;

            num = remainder;

            if (remainder == 0)
                return 0;

            do
            {
                previousRemainders.Add(remainder);
                num = remainder;
                num *= 10;
                remainder = num % den;
                if (remainder == 0)
                    return 0;

            } while (!previousRemainders.Contains(remainder));

            return previousRemainders.Count - previousRemainders.IndexOf(remainder);
        }

        static void Main(string[] args)
        {
            int longest = 0, number = 1;
            for (int i = 2; i < 10000; i++)
            {
                int x = CycleLength(i);
                if (x > longest)
                {
                    longest = x;
                    number = i;
                }
            }
            Console.WriteLine($"{number} gives cycle of length {longest}");
        }
    }
}
