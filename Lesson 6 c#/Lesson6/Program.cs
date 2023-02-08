using PostNamespace;
using UserNamespace;
using AdminNamespace;
using Lesson6;
using DatabaseNamespace;


bool CheckHaveAdmin(string str, string password, List<Admin> aList)
{
    if (str.Contains("@"))
    {
        for (int i = 0; i < aList.Count; i++)
        {
            if (str == aList[i].Email)
            {
                if (password == aList[i].Password)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
    else
    {
        for (int i = 0; i < aList.Count; i++)
        {
            if (str == aList[i].Username)
            {
                if (password == aList[i].Password)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
}

bool CheckHavePost(int ind, List<Post> pList)
{
    for (int i = 0; i < pList.Count; i++)
    {
        if (ind == pList[i].Id)
        {
            return true;
        }
    }
    return false;
}

User? User(string username, List<User> uList)
{
    for (int i = 0; i < uList.Count; i++)
    {
        if (username == uList[i].Username)
        {
            return uList[i];
        }
    }
    return null;
}


bool CheckUser(string str, string password, List<User> uList)
{
    if (str.Contains("@"))
    {
        for (int i = 0; i < uList.Count; i++)
        {
            if (str == uList[i].Email)
            {
                if (password == uList[i].Password)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
    else
    {
        for (int i = 0; i < uList.Count; i++)
        {
            if (str == uList[i].Username)
            {
                if (password == uList[i].Password)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
}

Admin admin = new("admin", "admin", "admin@admin.com");
User us = new("Ruso", "Rustam", "Mammadov", 32, "rustam.mammadov.c@gmail.com", "12345");
Database dataB = new();
dataB.listAdmins.Add(admin);
dataB.listUsers.Add(us);
Post post = new("Hakuna Matata", DateTime.Now);
admin.posts.Add(post);

lebel0:
Console.Clear();
Console.WriteLine("\n1.Admin");
Console.WriteLine("2.User");
Console.WriteLine("\nEnter : ");
string? userin = Console.ReadLine();
if (userin == "1")
{
labelAdmins:
    Console.Clear();
    Console.WriteLine("\nEnter username or email : ");
    userin = Console.ReadLine();
    Console.WriteLine("\nEnter password : ");
    string? usIn = Console.ReadLine();
    if (CheckHaveAdmin(userin ?? "null", usIn ?? "null", dataB.listAdmins))
    {
    labelMenu:
        Console.Clear();
        Console.WriteLine("\n1.Posts.");
        Console.WriteLine("2.Notifications.");
        Console.WriteLine("0.Back.");
        Console.WriteLine("\nEnter : ");
        userin = Console.ReadLine();
        if (userin == "1")
        {
        labelposts:
            Console.Clear();
            for (int i = 0; i < dataB.listAdmins[0].posts.Count; i++)
            {
                dataB.listAdmins[0].posts[i].PrintPost();
            }
            Console.WriteLine("\n0.Back");
            Console.WriteLine("Entered post id : ");
            int id = Convert.ToInt32(Console.ReadLine());
            if (id == 0)
            {
                goto labelMenu;
            }
            else if (CheckHavePost(id, dataB.listAdmins[0].posts))
            {
                Console.Clear();
                dataB.listAdmins[0].posts[id - 1].ViewCount++;
                dataB.listAdmins[0].posts[id - 1].PrintPost();
                Console.WriteLine("\n1.Remove");
                Console.WriteLine("0.Back");
                Console.WriteLine("\nEnter : ");
                userin = Console.ReadLine();
                if (userin == "1")
                {
                    dataB.listAdmins[0].posts.Remove(dataB.listAdmins[0].posts[id - 1]);
                    Console.Clear();
                    Console.WriteLine("\nRemoved");
                    Thread.Sleep(1000);
                    goto labelposts;
                }
                else if (userin == "0")
                    goto labelMenu;
                else
                {
                    Console.Clear();
                    Console.WriteLine("Incorrect input");
                    Thread.Sleep(1000);
                    goto labelposts;
                }
            }
            else
            {
                Console.Clear();
                Console.WriteLine("Incorrect input");
                Thread.Sleep(1000);
                goto labelposts;
            }
        }
        else if (userin == "2")
        {
        labelnotifications:
            Console.Clear();
            for (int i = 0; i < dataB.listAdmins[0].notifications.Count; i++)
            {
                dataB.listAdmins[0].notifications[i].PrintNotification();
            }
            Console.WriteLine("\n1.Clear");
            Console.WriteLine("0.Back");
            Console.WriteLine("\nEnter : ");
            userin = Console.ReadLine();
            if (userin == "1")
            {
                dataB.listAdmins[0].notifications.Clear();
                Console.Clear();
                Console.WriteLine("Removed");
                Thread.Sleep(1000);
                goto labelnotifications;
            }
            else if (userin == "0")
            {
                goto labelMenu;
            }
            else
            {
                Console.Clear();
                Console.WriteLine("Incorrect input");
                Thread.Sleep(1000);
                goto labelnotifications;
            }
        }
        else if (userin == "0")
        {
            goto lebel0;
        }
        else
        {
            Console.Clear();
            Console.WriteLine("Incorrect input");
            Thread.Sleep(1000);
            goto labelAdmins;
        }
    }
    else
    {
        Console.Clear();
        Console.WriteLine("Incorrect input");
        Thread.Sleep(1000);
        goto labelAdmins;
    }
}
else if (userin == "2")
{
labelUsers:
    Console.Clear();
    Console.WriteLine("Enter username or email");
    string? usernamee = Console.ReadLine();
    Console.WriteLine("\nEnter password");
    string? entered = Console.ReadLine();
    if (CheckUser(usernamee ?? "null", entered ?? "null", dataB.listUsers))
    {
    labelposts:
        Console.Clear();
        for (int i = 0; i < dataB.listAdmins.Count; i++)
        {
            for (int j = 0; j < dataB.listAdmins[i].posts.Count; j++)
            {
                dataB.listAdmins[i].posts[j].PrintPost();
            }
        }
        Console.WriteLine("\n0.Back");
        Console.WriteLine("Enter id :");
        int id = Convert.ToInt32(Console.ReadLine());
        if (id == 0)
        {
            goto lebel0;
        }
        else if (CheckHavePost(id, dataB.listAdmins[0].posts))
        {
            Console.Clear();
            dataB.listAdmins[0].posts[id - 1].ViewCount++;
            dataB.listAdmins[0].posts[id - 1].PrintPost();
            Console.WriteLine("\n1.Like");
            Console.WriteLine("0.Back");
            Console.WriteLine("\nEnter : ");
            userin = Console.ReadLine();
            if (userin == "1")
            {
                dataB.listAdmins[0].posts[id - 1].LikeCount += 1;
                Console.Clear();
                Console.WriteLine("Liked...");
                Thread.Sleep(1000);
                dataB.listAdmins[0].notifications.Add(new Notification($"{usernamee} liked {id} post", DateTime.Now, User(usernamee, dataB.listUsers)));
                goto labelposts;
            }
            else
                goto labelposts;
        }
        else
        {
            Console.Clear();
            Console.WriteLine("Incorrect input");
            Thread.Sleep(1000);
            goto labelposts;
        }

    }
    else
    {
        Console.Clear();
        Console.WriteLine("Incorrect input");
        Thread.Sleep(1000);
        goto labelUsers;
    }
}
else
{
    Console.Clear();
    Console.WriteLine("Incorrect input");
    Thread.Sleep(1000);
    goto lebel0;
}
