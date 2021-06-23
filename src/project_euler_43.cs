using System;
using System.Collections.Generic;

namespace pe43
{
    class Program
    {
        static bool Check(string inp)
        {
            if (Convert.ToInt16(inp.Substring(1, 3)) % 2 != 0) return false;
            if (Convert.ToInt16(inp.Substring(2, 3)) % 3 != 0) return false;
            if (Convert.ToInt16(inp.Substring(3, 3)) % 5 != 0) return false;
            if (Convert.ToInt16(inp.Substring(4, 3)) % 7 != 0) return false;
            if (Convert.ToInt16(inp.Substring(5, 3)) % 11 != 0) return false;
            if (Convert.ToInt16(inp.Substring(6, 3)) % 13 != 0) return false;
            if (Convert.ToInt16(inp.Substring(7, 3)) % 17 != 0) return false;
            return true;
        }
        static int i = 1;
        static void GeneratePermuations<A>(List<A> digits, ref List<string> result, string current)
        {
            if (digits.Count == 0)
            {
                result.Add(current);
                return;
            }

            List<A> digitsCopy = new List<A>(digits);

            for (int i=0; i<digits.Count; i++)
            {
                A x = digitsCopy[i];
                string currentCopy = current + digitsCopy[i].ToString();
                digitsCopy.RemoveAt(i);
                GeneratePermuations(digitsCopy, ref result, currentCopy);
                digitsCopy.Insert(i, x);
            }
        }
        public static void print<T>(List<T> list)
        {
            Console.WriteLine("[" + string.Join(',', list) + "]");
        }
        public static void print(in List<int> list)
        {
            print<int>(list);
            list.Add(i++);
        }
        static void Main(string[] args)
        {
            List<string> permutations = new List<string>();

            GeneratePermuations(new List<int>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, ref permutations, "");

            long sum = 0;

            foreach (string x in permutations)
            {
                if (Check(x))
                    sum += Convert.ToInt64(x);
            }

            Console.WriteLine(sum);
        }
    }
}
