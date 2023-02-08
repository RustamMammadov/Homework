using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lesson10
{
    public class MyClass
    {
        public MyClass(string str)
        {
            this.str = str;
        }

        public string str { get; set; }
        public void Space(string str)
        {
            for (int i = 0; i < str.Length; i++)
            {
                Console.Write(str[i]);
                if (i + 1 != str.Length)
                    Console.Write('_');
            }
        }
        public void Reverse(string str)
        {
            Console.WriteLine();
            for (int i = str.Length - 1; i >= 0; i--)
            {
                Console.Write(str[i]);
            }
        }
    }
}
