using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lesson_7_._Bank
{
    internal class Card
    {
        public Card(string bankname, string fullname, string pan, string pin, string cvc, string expireDate, double balance)
        {
            BankName = bankname;
            FullName = fullname;
            PAN = pan;
            PIN = pin;
            CVC = cvc;
            ExpireDate = expireDate;
            Balance = balance;
        }
        public string BankName { get; set; }
        public string FullName { get; set; }
        public string PAN { get; set; }
        public string PIN { get; set; }
        public string CVC { get; set; }
        public string ExpireDate { get; set; }
        public double Balance { get; set; }
    }
}