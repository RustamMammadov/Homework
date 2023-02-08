using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lesson_7_._Bank
{
    internal class Costumer
    {
        public Costumer(string name, string surname, int age, double salary, Card bankAccount)
        {
            id = ++Id;
            Name = name;
            Surname = surname;
            Age = age;
            Salary = salary;
            BankAccount = bankAccount;
        }
        private int Id = 0;
        public int id;
        public string Name { get; set; }
        public string Surname { get; set; }
        public int Age { get; set; }
        public double Salary { get; set; }
        public Card BankAccount { get; set; }
    }
}
