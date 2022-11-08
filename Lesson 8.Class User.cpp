#include <iostream>

using namespace std;

//class User :
//    string username;
//string password;
//
//class Database :
//    User * users;
//
//bool SignIn(User& user)
//bool SignUp(User& user)

class User
{
private:
	string username;
	string password;

public:
	User()
	{
		username = "Admin";
		password = "Admin";
	}

	User(const string username, const string password)
	{
		this->password = password;
		this->username = username;
	}

	User(const User& obj)
	{
		this->password = obj.password;
		this->username = obj.username;
	}

	void SetUsername(string username) { this->username = username; }
	void SetPassword(string password) { this->password = password; }

	string GetUsername() { return username; }
	string GetPassword() { return password; }

	friend ostream& operator<<(ostream& out, const User& obj)
	{
		cout << "Username : " << obj.username << endl;
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
		return *this;
	}


};


class Database
{
	User* users = nullptr;
	int size = 0;

public:

	Database() = default;

	User* GetUsers() { return users; }

	void AddUser(User& obj)
	{
		if (SignUp(obj) == false)
		{
			cout << "\n\nThis user already exists\n\n";
			return;
		}
		User* temp = new User[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = users[i];
		}
		temp[size] = obj;
		delete[] users;
		users = temp;
		temp = nullptr;
		size++;
	}


	friend ostream& operator<<(ostream& out, const Database& obj)
	{
		for (int i = 0; i < obj.size; i++)
		{
			cout << "Username : " << obj.users[i].GetUsername() << endl;
			cout << "Password : " << obj.users[i].GetPassword() << "\n\n";

		}
		return out;
	}

	bool SignUp(User& user)
	{
		for (int i = 0; i < size; i++)
		{
			if (users[i].GetUsername() == user.GetUsername())
			{
				return false;
			}
		}
		return true;
	}

	bool SignIn(User& user)
	{
		for (int i = 0; i < size; i++)
		{
			if (users[i].GetUsername() == user.GetUsername() && users[i].GetPassword() == user.GetPassword())
			{
				return true;
			}
		}
		return false;
	}

	void Check(User& obj)
	{
		if (SignUp(obj) == false)
		{

			return;
		}
		else
		{
			cout << "\nWelcome\n";
		}
	}

	~Database()
	{
		delete[] users;
	}

};


int main()
{

	User user1("Rustam", "12345");
	User user2("Islam", "12345");
	User user3("Huseyn", "12345");
	Database usersBase;
	usersBase.AddUser(user1);
	usersBase.AddUser(user2);
	usersBase.AddUser(user3);

	User user4;
	while (true)
	{
		cout << "Sign up :\n";
		cin >> user4;
		if (usersBase.SignUp(user4))
		{
			usersBase.AddUser(user4);
			break;
		}
		cout << "\n\nThis user already exists\n\n";
		system("pause");
		system("cls");
	}
	cout << endl;
	system("pause");
	system("cls");

	cout << "Sign in\n";

	while (true)
	{
		User user5;
		cin >> user5;
		system("cls");
		if (usersBase.SignIn(user5))
		{
			cout << "Welcome...\n\n";
			break;
		}
		else
		{
			system("cls");
			cout << "\nUsername or password is incorrect!\n";
			continue;
		}
	}


	system("pause");
	system("cls");
	cout << "Base : \n\n" << usersBase;

}

