void Sual(int[] check, string sual, string[] cavab, string d_cavab, ref int xal)
{
lebel1:
    Console.Clear();
    Console.WriteLine(sual);
    string[] variant = { "A", "B", "C" };

    InitShuffle(ref check);
    for (int i = 0; i < 3; i++)
    {
        Console.WriteLine($"{variant[i]} : {cavab[check[i]]}");
    }
    var entered = Console.ReadLine();
    int int_entered;

    switch (entered)
    {
        case "a":
        case "A":
            int_entered = 0;
            break;
        case "b":
        case "B":
            int_entered = 1;
            break;
        case "c":
        case "C":
            int_entered = 2;
            break;
        default:
            goto lebel1;
            break;
    }

    Console.Clear();
    Console.WriteLine(sual);
    if (cavab[check[int_entered]] == d_cavab)
    {
        xal += 10;
        for (int i = 0; i < 3; i++)
        {
            if (int_entered == i)
            {
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine($"{variant[i]} : {cavab[check[i]]}");
                Console.ForegroundColor = ConsoleColor.White;
                continue;
            }
            Console.WriteLine($"{variant[i]} : {cavab[check[i]]}");
        }
    }
    else
    {
        if (xal != 0)
        {
            xal -= 10;
        }
        for (int i = 0; i < 3; i++)
        {
            if (int_entered == i)
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine($"{variant[i]} : {cavab[check[i]]}");
                Console.ForegroundColor = ConsoleColor.White;
                continue;
            }
            Console.WriteLine($"{variant[i]} : {cavab[check[i]]}");
        }
    }
    Console.ReadLine();
}

void InitShuffle(ref int[] check)
{
    Random rand = new Random();
    while (check[0] == check[1] || check[0] == check[2] || check[1] == check[2])
    {
        for (int i = 0; i < 3; i++)
        {
            check[i] = rand.Next(0, 3);
        }
    }
}

int[] check = new int[3];
int xal = 0;

string[] suallar =
{
    "1. Şahmatdan başqa hansı digər oyunu şahmat taxtası üzərində oynamaq mümkündür?",
    "2. Qazin mayeye chevrilmesi prosesi nece adlanir?",
    "3. İqtisadçıların fikrincə ticarətin hərəkətverici qüvvəsi nədir?",
    "4. Optimis təyyarə haqqında fikirləşir, bəs pessimist?",
    "5. Hansı ölkənin rəsmi dili yoxdur?",
    "6. 20-ci əsrin ilk günü hansıdır?",
    "7. Dünyanın ən uzun çayı hansıdır? ",
    "8. UEFA Çempionlar Liqasında ən çox kubok qazanmış klub hansıdır?",
    "9. Ən bərk metal hansıdır?",
    "10. Dünyada mövcud olan ən sərt maddə hansıdır?",
};

string[][] cavablar = new string[10][]
{
    new string[]{ "Monopoly", "Dama", "Domino" },
    new string[]{ "Kondensasiya", "Donma", "Buxarlanma" },
    new string[]{ "Reklam", "Sığorta", "Kredit" },
    new string[]{ "Paraşüt", "Vaxt", "Yuxu" },
    new string[]{ "ABŞ", "isveçrə", "İran" },
    new string[]{ "1 Yanvar 1901", "1 yanvar 2000", "1 yanvar 1900" },
    new string[]{ "Nil", "Volqa", "Amazon" },
    new string[]{ "Real Madrid", "Barselona", "Arsenal" },
    new string[]{ "Xrom", "Platin", "Osmium" },
    new string[]{ "Almaz", "Qızıl", "Xrom" },
};

string[] d_cavablar =
{
    "Dama",
    "Kondensasiya",
    "Reklam",
    "Paraşüt",
    "ABŞ",
    "1 Yanvar 1901",
    "Nil",
    "Real Madrid",
    "Xrom",
    "Almaz",
};

for (int i = 0; i < 10; i++)
{
    Sual(check, suallar[i], cavablar[i], d_cavablar[i], ref xal);
    Console.Clear();
    Console.BackgroundColor = ConsoleColor.DarkBlue;
    Console.WriteLine($"imtahan bitmisdir siz {xal}  xal toplamisiniz.");
    Console.BackgroundColor = ConsoleColor.Black;
}