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
                var aritmetic = Console.ReadLine();
                var b = Console.ReadLine();
                Console.WriteLine(" = ");
                float.TryParse(a, out float n1);
                float.TryParse(b, out float n2);
                Console.Clear();
                switch (aritmetic)
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
                        Console.WriteLine("Incorrect Entry");
                        Console.ReadLine();
                        Console.Clear();
                        break;
                }
                Console.ReadLine();
                Console.Clear();
            }
        }
        private static void Plus(float n1, float n2)
        {
            Console.WriteLine($"{n1} + {n2} = {n1 + n2}");
        }
        private static void Minus(float n1, float n2)
        {
            Console.WriteLine($"{n1} - {n2} = {n1 - n2}");
        }
        private static void Multiplicatione(float n1, float n2)
        {
            Console.WriteLine($"{n1} * {n2} = {n1 * n2}");
        }
        private static void Divide(float n1, float n2)
        {
            if (n2 == 0)
            {
                Console.Clear();
                Console.WriteLine("Error...");
                Console.ReadLine();
            }
            else
                Console.WriteLine($"{n1} / {n2} = {n1 / n2}");
        }
    }
}