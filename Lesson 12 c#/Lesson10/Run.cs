using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lesson10
{
    public delegate void Function(string s);
    public class Run
    {
        public void runFunc(Function func, string str)
        {
            func.Invoke(str);
        }
    }
}
