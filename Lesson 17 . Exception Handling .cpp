#include <iostream>

using namespace std;

class DatabaseException : public exception {
	string message;
public:
	DatabaseException(string message) : message(message) {}
	const char* what() const override {
		return message.c_str();
	}
};

class InvalidArgumentException : public exception {
	string message;
public:
	InvalidArgumentException(string message) : message(message) {}
	const char* what() const override {
		return message.c_str();
	}
};

class NotFoundException : public exception {
	string message;
public:
	NotFoundException(string message) : message(message) {}
	const char* what() const override {
		return message.c_str();
	}
};

class CreatSameException : public exception {
	string message;
public:
	CreatSameException(string message) : message(message) {}
	const char* what() const override {
		return message.c_str();
	}
};


static int id = 100;

class User
{
private:
	string username;
	string password;
	string name;
	string surname;
	int ID;

public:
	
	User()
	{
		username = "Admin";
		password = "Admin";
		name = "NoName";
		surname = "NoSurname";
		ID = 100;
	}

	User(const string username, const string password, const string name, const string surname)
	{
		SetUsername(username);
		SetPassword(password);
		SetName(name);
		SetSurname(surname);
		ID = ++id;
	}

	User(const User& obj)
	{
		this->password = obj.password;
		this->username = obj.username;
		this->name = obj.name;
		this->surname = obj.surname;
	}

	void SetUsername(string username)
	{
		if (SizeUsername(username) && ChekFirstCaseUsername(username))
		{
			this->username = username;
		}
		else
			throw InvalidArgumentException("Invalid username");
	}

	void SetPassword(string password)
	{
		if (SizePassword(password))
		{
			this->password = password;
		}
		else
			throw InvalidArgumentException("Invalid password");

	}

	void SetName(string name)
	{
		if (SizeName(name))
		{
			this->name = name;
		}
		else
			throw InvalidArgumentException("Invalid name");
	}

	void SetSurname(string surname)
	{
		if (SizeSurname(surname))
		{
			this->surname = surname;
		}
		else
			throw InvalidArgumentException("Invalid surname");

	}

	bool SizeUsername(string username)
	{
		if ((username.size()) < 6)
			return false;
		return true;
	}

	bool ChekFirstCaseUsername(string username)
	{
		if (int(username[0]) >= 97 && int(username[0]) <= 122)
			return false;
		return true;
	}

	bool SizePassword(string password)
	{
		if ((password.size()) < 6)
			return false;
		return true;
	}

	bool SizeName(string name)
	{
		if ((name.size()) < 4)
			return false;
		return true;
	}

	bool SizeSurname(string surname)
	{
		if ((surname.size()) < 4)
			return false;
		return true;
	}

	string GetUsername() { return username; }

	string GetPassword() { return password; }

	string GetName() { return name; }

	string GetSurname() { return surname; }

	friend ostream& operator<<(ostream& out, const User& obj) // void show() const; evezine
	{
		cout << "Username : " << obj.username << endl;
		cout << "Name : " << obj.name << endl;
		cout << "Surname : " << obj.surname << endl;
		cout << "Password : " << obj.password << "\n\n";
		return out;
	}

	friend istream& operator>>(istream& in, User& obj) {

		cout << "\nUsername : ";
		in >> obj.username;
		cout << "Password : ";
		in >> obj.password;
		return in;
	}

	User& operator=(const User& obj)
	{
		username = obj.username;
		password = obj.password;
		name = obj.name;
		surname = obj.surname;
		return *this;
	}
};

class Database
{
	User* users = nullptr;
	int user_count = 0;

public:

	Database() = default;

	User* GetUsers()const { return users; }

	void addUser(User& user)
	{
		if (SignUpUser(user) == false)
		{
			throw CreatSameException("This user already exists");
		}
		User* temp = new User[user_count + 1];
		for (int i = 0; i < user_count; i++)
		{
			temp[i] = users[i];
		}
		temp[user_count] = user;
		delete[] users;
		users = temp;
		temp = nullptr;
		user_count++;
	}

	friend ostream& operator<<(ostream& out, const Database& obj)
	{
		for (int i = 0; i < obj.user_count; i++)
		{
			cout << "Name     : " << obj.users[i].GetName() << endl;
			cout << "Surname  : " << obj.users[i].GetSurname() << endl;
			cout << "Username : " << obj.users[i].GetUsername() << endl;
			cout << "Password : " << obj.users[i].GetPassword() << "\n\n";

		}
		return out;
	}

	bool SignUpUser(User& user)const
	{
		for (int i = 0; i < user_count; i++)
		{
			if (users[i].GetUsername() == user.GetUsername())
			{
				return false;
			}
		}
		return true;
	}

	void signUp(string username, string password, string name, string surname)
	{
		User user(username, password, name, surname);
		addUser(user);
	}

	User& getUserByUsername(string username) const
	{
		for (int i = 0; i < user_count; i++)
		{
			if (users[i].GetUsername() == username)
			{
				return users[i];
			}
		}
		throw NotFoundException("User not found!!!");
	}

	void SignIn(string username, string password) const
	{
		for (int i = 0; i < user_count; i++)
		{
			if (users[i].GetUsername() == username && users[i].GetPassword() == password)
			{
				if (users[i].GetPassword() == password)
				{
					throw DatabaseException("WELCOME!!!");
				}
			}
			else if (users[i].GetPassword() == password && users[i].GetPassword() != password)
			{
				throw NotFoundException("Password incorrect!!!");
			}
		}
		throw NotFoundException("User not found!!!");
	}

	~Database()
	{
		delete[] users;
	}
};

class Registration 
{
public:
	Database _database;
	Registration(const Database& database)
	{
		_database = database;
	}

	Registration& operator=(const Registration& obj)
	{
		_database = obj._database;
		return *this;
	}

	Database getDatabase() { return _database; };

	void showRegistration()
	{
		cout << _database;
	}
};

class System {
public:
	static void Control() {
		try {
			Database db;
			Registration twitter(db);
			User user1("Rustam", "123456", "Rustam", "Mammadov");
			User user2("Islam02", "123456", "Islam", "Salamzade");// user2-nin username.ini Islam ve islam etsek sherte uygun olaraq exception atacaq.
			
			cout << user1 << endl;

			system("pause");
			system("cls");

			twitter._database.addUser(user1);
			twitter._database.addUser(user2);
			twitter._database.signUp("Huseyn", "123456", "Huseyn", "Mammadov");

			cout << "Base : \n\n";
			twitter.showRegistration();
		}
		catch (const exception& ex)
		{
			cout << "Error : " << ex.what() << endl;
		}
	}
};

int main()
{
	System::Control();

	system("pause");
}