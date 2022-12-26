using System.Diagnostics;
using System.Threading;

namespace Calculator_Lesson_2
{

    internal class Calculator
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.Write("Calculator\n\n");
                var a = Console.ReadLine();
                var arititmetic = Console.ReadLine();
                var b = Console.ReadLine();
                Console.WriteLine(" = ");
                int.TryParse(a, out int n1);
                int.TryParse(b, out int n2);

                    Console.Clear();
                switch (arititmetic)
                {
                    case "+":
                        Plus(n1, n2);
                        break;
                    case "-":
                        Minus(n1, n2);
                        break;
                    case "/":
                        Divide(n1, n2);
                        break;
                    case "*":
                        Multiplicatione(n1, n2);
                        break;
                    defoult:
                        //Console.Clear();
                        Console.WriteLine("Incorrect Entry");
                        Thread.Sleep(3000);
                        Console.Clear();
                        break;
                }
                Thread.Sleep(3000);
                Console.Clear();
            }
        }

        private static void Plus(int n1, int n2)
        {
            Console.WriteLine($"{n1} + {n2} = {n1 + n2}");
        }
        private static void Minus(int n1, int n2)
        {
            Console.WriteLine($"{n1} - {n2} = {n1 - n2}");
        }
        private static void Multiplicatione(int n1, int n2)
        {
            Console.WriteLine($"{n1} * {n2} = {n1 * n2}");
        }
        private static void Divide(int n1, int n2)
        {
            if (n2 == 0)
            {
                Console.Clear();
                Console.WriteLine("Error...");
                Thread.Sleep(3000);

            }
            else
                Console.WriteLine($"{n1} / {n2} = {n1 / n2}");
        }
    }
}