using Lesson_7_._Bank;

Bank bank = new();
Card card1 = new("ABB", "Namiq Resullu", "12345678912345", "1234", "123", "01/2023", 1234);
Card card2 = new("Kapital Bank", "Behruz Nezerov", "23456789123456", "2345", "234", "02/2024", 2345);
Card card3 = new("Uni Bank", "Rustam Mammadov", "34567891234567", "3456", "345", "03/2025", 3456);
Card card4 = new("Xalq Bank", "Islam Salamzade", "45678912345678", "4567", "456", "04/2026", 4567);
Card card5 = new("Access Bank", "Huseyn Mammadov", "56789123456789", "6789", "567", "05/2027", 5678);

Costumer costumer1 = new("Namiq", "Resullu", 27, 27000, card1);
Costumer costumer2 = new("Behruz", "Nezerov", 18, 28000, card2);
Costumer costumer3 = new("Rustam", "Mammadov", 32, 29000, card3);
Costumer costumer4 = new("Islam", "Salamzade", 20, 30000, card4);
Costumer costumer5 = new("Husyen", "Mammadov", 20, 31000, card5);

bank.costumer.Add(costumer1);
bank.costumer.Add(costumer2);
bank.costumer.Add(costumer3);
bank.costumer.Add(costumer4);
bank.costumer.Add(costumer5);

string[] arr = { " *** Balance ***", " *** Cash ***", " *** Transfer money to another card ***" };
string[] arr2 = { "1. 10 AZN", "2. 20 AZN", "3. 50 AZN", "4. 100 AZN", "5. Other" };
void Cout(string[] arr, int size, int m)
{
    for (int i = 0; i < size; i++)
    {
        if (i == m)
        {
            Console.ForegroundColor = ConsoleColor.Green;
        }
        Console.WriteLine(arr[i]);
        Console.ForegroundColor = ConsoleColor.White;
    }
}

Label0:
Console.Clear();
Console.WriteLine("WELCOME TO BANK\n");
Console.WriteLine("\nEnter Pin :");
string str = Console.ReadLine();
bool check = true;

foreach (var item in bank.costumer)
{
    if (check == false)
    {
        Console.WriteLine("Logged out.");
        Thread.Sleep(3000);
        goto Label0;
    }

    if (str == item.BankAccount.PIN)
    {
        Console.Clear();
        Console.WriteLine($"Welcome {item.BankAccount.FullName} ");
        Thread.Sleep(3000);
    Label2:
        int x = 0;
        int z = 0;
    LabelMenu:
        while (true)
        {
            Console.Clear();
            Cout(arr, arr.Length, x);
            var key = Console.ReadKey();

            switch (key.Key)
            {
                case ConsoleKey.DownArrow:
                    x = x == 2 ? 0 : x + 1;
                    break;
                case ConsoleKey.UpArrow:
                    x = x == 0 ? 2 : x - 1;
                    break;
                default:
                    break;
            }
            if (key.Key == ConsoleKey.Enter)
            {
                Console.Clear();
                if (x == 0)
                {
                    Console.WriteLine("Balance : ");
                    Console.WriteLine(item.BankAccount.Balance);
                    Console.ReadLine();
                    goto Label2;
                }
                else if (x == 1)
                {
                    while (true)
                    {
                        Console.Clear();
                        Cout(arr2, arr2.Length, z);
                        key = Console.ReadKey();
                        switch (key.Key)
                        {
                            case ConsoleKey.DownArrow:
                                z = z == 4 ? 0 : z + 1;
                                break;
                            case ConsoleKey.UpArrow:
                                z = z == 0 ? 4 : z - 1;
                                break;
                            default:
                                break;
                        }
                        if (key.Key == ConsoleKey.Enter)
                        {
                            switch (z)
                            {
                                case 1:
                                case 2:
                                case 3:
                                case 4:
                                    Console.Clear();
                                    Console.WriteLine("Operation is performed.");
                                    Thread.Sleep(3000);
                                    Console.WriteLine("Successful operation");
                                    Thread.Sleep(3000);
                                    break;
                                case 5:
                                    Console.Clear();
                                    Console.Write("Enter amount: ");
                                    double.TryParse(Console.ReadLine(), out double m);
                                    item.BankAccount.Balance -= m;
                                    Thread.Sleep(2000);
                                    Console.WriteLine("Successful operation");
                                    break;

                                default:
                                    break;
                            }
                            goto Label2;
                        }
                    }
                }
                else if (x == 2)
                {
                    Console.WriteLine("Enter card number : ");
                    string cardNumber = Console.ReadLine();
                    bool t = false;
                    foreach (var i in bank.costumer)
                    {
                        if (i.BankAccount.PAN == cardNumber)
                        {
                            Console.Write("Amount : ");
                            double.TryParse(Console.ReadLine(), out double y);
                            item.BankAccount.Balance -= y;
                            i.BankAccount.Balance += y;
                            Console.WriteLine("Successful operation");
                            Thread.Sleep(1000);
                            t = true;
                            goto Label2;
                        }
                    }
                    if (t == false)
                    {
                        Console.WriteLine("Wrong PAN code");
                        Thread.Sleep(1000);
                        goto Label2;
                    }

                }
                break;
            }
            else if (key.Key == ConsoleKey.Escape)
            {
                check = false;
                break;
            }
        }
    }
}
Console.Clear();
Console.WriteLine("Wrong Pin ");
Thread.Sleep(1000);
goto Label0;