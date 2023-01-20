using Lesson_5;

PetShop shop = new();
shop.CatHouses.Add(new CatHouse { Name = "First Cat House" });
shop.CatHouses.Add(new CatHouse { Name = "Second Cat House" });
shop.CatHouses[0].AddCat(new Cat { Nickname = "Jony", Age = 1, Energy = 100, Gender = true, MealQuantity = 100, Price = 2 });
shop.CatHouses[0].AddCat(new Cat { Nickname = "Jane", Age = 2, Energy = 100, Gender = false, MealQuantity = 100, Price = 2 });
shop.CatHouses[1].AddCat(new Cat { Nickname = "Jack", Age = 3, Energy = 100, Gender = true, MealQuantity = 100, Price = 2 });


lebel1:
Console.Clear();
Console.WriteLine("1. PetShops");
Console.WriteLine("2. Add CatHouse");
//Console.WriteLine("0. Exit");
var entered = Console.ReadLine();

if (entered == "1")
{
lebelPetShop:
    Console.Clear();
    if (shop.CatHouseCount >= 0)
    {
        int i = 1;
        foreach (var house1 in shop.CatHouses)
        {
            Console.WriteLine($"{i++}: {house1.Name}");
        }
        Console.WriteLine("Back 0");
        Console.WriteLine("Enter : ");
        entered = Console.ReadLine();
        if (entered == "0")
            goto lebel1;
        if (int.TryParse(entered, out int result) && 0 < result && result <= shop.CatHouseCount)
        {

            var house = shop.CatHouses[result - 1];
        lebelHouse:
            Console.Clear();
            Console.WriteLine(house.Name);
            Console.WriteLine("1. All cat");
            Console.WriteLine("2. Add cat");
            Console.WriteLine("0. Back");
            entered = Console.ReadLine();
            Console.Clear();
            if (entered == "1")
            {
            lebelAllCat:
                Console.Clear();
                if (house.CatCount != 0)
                {
                    i = 1;
                    foreach (var cat in house.Cats)
                    {
                        Console.WriteLine($"{i++}: {cat.Nickname}");
                    }
                }
                else
                    Console.WriteLine("There is no cat.");
                Console.WriteLine("0. Back");
                Console.WriteLine("Enter : ");
                if (entered == "0")
                    goto lebelHouse;
                entered = Console.ReadLine();
                if (int.TryParse(entered, out int r) && 0 < r && r <= house.CatCount)
                {
                lebelCat:
                    Console.Clear();
                    var catw = house.Cats[r - 1];
                    Console.WriteLine(catw.Nickname);

                    Console.WriteLine("1. Play");
                    Console.WriteLine("2. Eat");
                    Console.WriteLine("3. Sleep");
                    Console.WriteLine("0. Back");
                    entered = Console.ReadLine();
                    Console.Clear();
                    if (entered == "1")
                    {
                        catw.Play();
                        Console.ReadLine();
                        goto lebelCat;
                    }
                    else if (entered == "2")
                    {
                        catw.Eat();
                        Console.ReadLine();
                        goto lebelCat;
                    }
                    else if (entered == "3")
                    {
                        catw.Sleep();
                        Console.ReadLine();
                        goto lebelCat;
                    }
                    else if (entered == "0")
                        goto lebelAllCat;
                    else
                        goto lebelCat;
                }
                else
                    goto lebelAllCat;

            }
            else if (entered == "2")
            {
                Console.Clear();
                Console.WriteLine("Nickname : ");
                string cat_name = Console.ReadLine();
            lebelAge:
                Console.Clear();
                Console.WriteLine("Age : ");
                string cat_age = Console.ReadLine();
                int.TryParse(cat_age, out int int_cat_age);
                if (int_cat_age <= 0)
                {
                    goto lebelAge;
                }
            lebelGender:
                Console.Clear();
                Console.WriteLine("Gender : Male (0) or Female(1)");
                string cat_gender = Console.ReadLine();
                bool bool_cat_gender;
                if (cat_gender == "0")
                    bool_cat_gender = false;
                else if (cat_gender == "1")
                    bool_cat_gender = true;
                else
                    goto lebelGender;
                lebelPrice:
                Console.Clear();
                Console.WriteLine("Price : ");
                string cat_price = Console.ReadLine();
                int.TryParse(cat_price, out int int_cat_price);
                if (int_cat_price <= 0)
                {
                    goto lebelPrice;
                }
                shop.CatHouses[result - 1].AddCat(new Cat { Nickname = cat_name, Age = int_cat_age, Energy = 100, Gender = bool_cat_gender, MealQuantity = 100, Price = int_cat_price });
                goto lebelHouse;
            }
            else if (entered == "0")
                goto lebelPetShop;
            else
                goto lebelHouse;
        }
        else
            goto lebelPetShop;
    }
    else
    {
        Console.Clear();
        Console.WriteLine("No cat house");
        Console.ReadLine();
        goto lebel1;
    }
}
else if (entered == "2")
{
    Console.Clear();
    Console.WriteLine("House name: ");
    var name = Console.ReadLine();
    CatHouse ch = new() { Name = name };
    shop.CatHouses.Add(ch);
    goto lebel1;

}
else
{
    Console.Clear();
    goto lebel1;
}
