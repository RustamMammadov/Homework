namespace UserNamespace
{
    public class User
    {
        public User(string username, string name, string surname, byte age, string email, string password)
        {
            Id += 1;
            Name = name;
            Surname = surname;
            Username = username;
            Age = age;
            Email = email;
            Password = password;
        }
        public int Id { get; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public string Username { get; set; }
        public byte Age { get; set; }
        public string Email { get; set; }
        public string Password { get; set; }
    }
}
