namespace PostNamespace
{
    public class Post
    {
        public Post(string content, DateTime dt)
        {
            Id += 1;
            LikeCount = default;
            ViewCount = default;
            CreationDateTime = dt;
            Content = content;
        }
        public int Id { get; }
        public int LikeCount { get; set; } = default;
        public int ViewCount { get; set; } = default;
        public DateTime CreationDateTime { get; set; }
        public string Content { get; set; }
        public void PrintPost()
        {
            Console.WriteLine($"Id {Id}");
            Console.WriteLine($"Like : {LikeCount} ");
            Console.WriteLine($"View : {ViewCount} ");
            Console.WriteLine($"Date : {CreationDateTime}");
            Console.WriteLine(Content);
        }
    }
}
