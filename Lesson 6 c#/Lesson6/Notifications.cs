using UserNamespace;

namespace Lesson6

{
    public class Notification
    {
        public Notification(string text, DateTime dt, User fUser)
        {
            Id += 1;
            FromUser = fUser;
            DateTime = dt;
            Text = text;
        }
        public int Id { get; }
        public User FromUser { get; set; }
        public DateTime DateTime { get; set; }
        public string Text { get; set; }
        public void PrintNotification()
        {
            Console.WriteLine($"Id : {Id} ");
            Console.WriteLine($"Date : {DateTime}");
            Console.WriteLine(Text);
        }
    }
}
