namespace Lesson_5
{
    internal class Cat
    {
        public string Nickname { get; set; }
        public int Age { get; set; }
        public bool Gender { get; set; }
        public int Energy { get; set; }
        public double Price { get; set; }
        public int MealQuantity { get; set; }

        public void Eat()
        {
            if (MealQuantity == 100)
                Console.WriteLine("The cat is not hungry.");
            else
            {
                MealQuantity += 10;
                Price += 1;
                Console.WriteLine("The cat is eating...");
            }
        }
        public void Sleep()
        {
            if (Energy == 100)
            {
                Console.WriteLine("The cat is full of energy and does not want to sleep.");
            }
            else
            {
                Energy = 100;
                Console.WriteLine("The cat is sleeping.");
            }
        }
        public void Play()
        {
            if (Energy >= 10 && MealQuantity >= 10)
            {
                Console.WriteLine("Playing...");
                Energy -= 10;
                MealQuantity -= 10;
            }
            if (Energy <= 0)
            {
                Console.WriteLine("The cat wants to sleep.");
            }
            if (MealQuantity <= 0)
            {
                Console.WriteLine("The cat wants to eat.");
            }
        }

    }
}
