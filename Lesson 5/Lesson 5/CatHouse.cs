namespace Lesson_5
{
    internal class CatHouse
    {
        public string Name { get; set; }
        public List<Cat> Cats { get; set; } = new();
        public int CatCount { get => Cats.Count; }
        public void AddCat(Cat cat)
        {
            foreach (var item in Cats)
            {
                if (item.Nickname == cat.Nickname)
                    throw new Exception("This cat already exists.");
            }
            Cats.Add(cat);
        }
        public void RemoveByNickname(string nickname)
        {
            foreach (var item in Cats)
            {
                if (item.Nickname == nickname)
                    Cats.Remove(item);
            }
        }
    }
}
