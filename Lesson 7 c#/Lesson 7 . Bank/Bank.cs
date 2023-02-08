using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lesson_7_._Bank
{
    internal class Bank
    {
        public List<Costumer> costumer = new();
        public void ShowCardBalance(Card card)
        {
            Console.WriteLine(card.Balance);
        }
    }
}
