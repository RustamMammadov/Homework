using Lesson6;
using PostNamespace;

namespace AdminNamespace
{
    public class Admin
    {
        public Admin(string username, string password, string email)
        {
            Id += 1;
            Email = email;
            Username = username;
            Password = password;
        }

        public List<Notification> notifications = new();

        public List<Post> posts = new();
        public int Id { get; }
        public string Email { get; set; }
        public string Username { get; set; }
        public string Password { get; set; }
    }
}
