#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

class Contact {
public:
	string name = "";
	string surname = "";
	string phonenumber = "";
	Contact() = default;
	Contact(const string n, const string s, const string num) {
		name = n;
		surname = s;
		phonenumber = num;


	}

	void AppToFile() {
		ofstream file("contacts.txt", ios::app);
		if (file.is_open()) 
		{
			file << name << "#" << surname << "#" << phonenumber << "/";
		}
		file.close();
	}
};



void ReadFromFile()
{

	ifstream ifs("contacts.txt", ios::in);
	if (ifs.is_open()) 
	{
		string val;
		while (!ifs.eof())
		{
			ifs >> val;
			cout << val << endl;
		}

	}
}



	class Database
	{
		vector<Contact> database;
	public:


		void AddContact(Contact contact)
		{
			database.push_back(contact);
			contact.AppToFile();
		}

		void DeleteByName(string name)
		{
			if (!database.empty()) {
				remove("contacts.txt");
				for (int i = 0; i < database.size(); i++)
				{
					if (database[i].name != name)
					{
						ofstream file("contacts.txt", ios::app);
						if (file.is_open()) 
						{
							file << database[i].name << "#" << database[i].surname << "#" << database[i].phonenumber << "/";
						}
						file.close();
					}
				}


				for (int i = 0; i < database.size(); i++)
				{
					if (database[i].name == name)
					{
						database.erase(database.begin() + i);
						return;
					}
				}
				cout << "Name is not base\n\n";
				return;
			}
			else
				cout << "Database is empty\n\n";
		}

		void SearchByName(string name)
		{
			if (!database.empty()) {
				for (int i = 0; i < database.size(); i++)
				{
					if (database[i].name == name)
					{
						cout << "Name : " << database[i].name << "\nSurname : " << database[i].surname << "\nPhonenamber :" << database[i].phonenumber << "\n\n";
						return;
					}
				}
				cout << "Name is not base\n\n";
				return;
			}
			else
				cout << "Database is empty\n\n";
		}
	};




	int main()
	{
		//remove("contacts.txt");
		Database dd;
		dd.DeleteByName("Islam");
		Contact contact1("Rustam", "Mammadov", "0703069333");
		Contact contact2("Islam", "Salamzade", "0555555555");
		Contact contact3("Huseyn", "Mammadov", "0777777777");
		dd.AddContact(contact1);
		dd.AddContact(contact2);
		dd.AddContact(contact3);
		dd.SearchByName("Islam");
		dd.DeleteByName("Islam");
		dd.SearchByName("Islam");
		ReadFromFile();
	}
