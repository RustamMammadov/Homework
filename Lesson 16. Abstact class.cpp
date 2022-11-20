#include <iostream>

using namespace std;


class Phone
{
private:
	string model;
	double display_size;
	double camera;
	bool dual_sim;
	string OS;
public:
	string date_of_production;
	Phone(string brand, double display_size, double camera, bool dual_sim , string OS, string date_of_production)
	{
		this->model = brand;
		this->display_size = display_size;
		this->camera = camera;
		this->dual_sim = dual_sim;
		this->OS = OS;
		this->date_of_production = date_of_production;
	}

	void Print()
	{
		cout << "Moldel : " << model << endl;
		cout << "Display size : " << display_size << endl;
		cout << "Camera : " << camera << endl;
		cout << "Dual Sim : " << boolalpha << dual_sim << endl;
		cout << "OS : " << OS << endl << endl;
	}

	virtual string Date_of_production(string date_of_production) = 0 { return date_of_production; }
};

class Samsung : public Phone
{
public:
	Samsung (string brand, double display_size, double camera, bool dual_sim, string OS, string date_of_production) : Phone(brand , display_size , camera , dual_sim , OS , date_of_production) {}

	string Date_of_production(string date_of_production) override { return Phone::Date_of_production(date_of_production); }
};


class Apple : public Phone
{
public:
	Apple (string brand, double display_size, double camera, bool dual_sim, string OS, string date_of_production) : Phone(brand , display_size , camera , dual_sim , OS , date_of_production) {}

	string Date_of_production(string date_of_production) override { return Phone::Date_of_production(date_of_production); }
};

class Xiaomi : public Phone
{
public:
	Xiaomi (string brand, double display_size, double camera, bool dual_sim, string OS, string date_of_production) : Phone(brand , display_size , camera , dual_sim , OS , date_of_production) {}

	string Date_of_production(string date_of_production) override { return Phone::Date_of_production(date_of_production); }
};



int main()
{
	Samsung samsung ("Samsung A70", 5.8, 32, true, "Android 10", "10.08.2021");
	Apple iphone("IPhone 7", 4.7, 12, true, "IOS", "09.09.2016");
	Xiaomi xiaomi("Xiaomi MiA3", 6.1, 48, true, "Android 12", "06.06.2019");

	samsung.Print();
	cout << "Date_of_production : " << samsung.Date_of_production(samsung.date_of_production) << "\n\n";

	iphone.Print();
	cout << "Date_of_production : " << iphone.Date_of_production(iphone.date_of_production) << "\n\n";

	xiaomi.Print();
	cout << "Date_of_production : " << xiaomi.Date_of_production(xiaomi.date_of_production) << endl;

}
