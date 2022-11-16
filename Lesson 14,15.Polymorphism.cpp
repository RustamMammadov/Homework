#include <iostream>
#include <stack>

using namespace std;

class Engine {
public:
	string engineNo;
	string company;
	double volume;
	Engine() {}
	Engine(string engineNo, string company, double volume) {
		this->engineNo = engineNo;
		this->company = company;
		this->volume = volume;
	}
	void Show() {
		cout << "Engine Company: " << company << "\nEngine No: " << engineNo << "\nEngine Volume: " << volume << endl;
	}
};

class Vehicle {
public:
	static int staticId;
	int id;
	string vendor;
	string model;
	Engine engine;

	Vehicle(string vendor, string model, Engine engine) {
		id = staticId++;
		this->vendor = vendor;
		this->model = model;
		this->engine = engine;
	}
	virtual void Show() {
		cout << "Id: " << id << "\nVendor: " << vendor << "\nModel: " << model << "\n";
		engine.Show();
	}
};
int Vehicle::staticId = 1;

class Car : public Vehicle {
public:
	bool hasSpoiler;

	Car(string vendor, string model, Engine engine, bool hasSpoiler) : Vehicle(vendor, model, engine) {
		this->hasSpoiler = hasSpoiler;
	}

	void Show() {
		cout << "-------CAR-------\n";
		Vehicle::Show();
		cout << "Spoiler: " << (hasSpoiler ? "var" : "yox") << endl;
	}
};

class Ship : public Vehicle {
public:
	bool hasSail;

	Ship(string vendor, string model, Engine engine, bool hasSpoiler) : Vehicle(vendor, model, engine) {
		this->hasSail = hasSpoiler;
	}

	void Show() {
		cout << "-------Ship-------\n";
		Vehicle::Show();
		cout << "Sail: " << (hasSail ? "var" : "yox") << endl;
	}
};

class Airplane : public Vehicle {
public:
	int engineCount;
	int passangersCapacity;

	Airplane(string vendor, string model, Engine engine, int engineCount, int passangersCapacity) : Vehicle(vendor, model, engine) {
		this->engineCount = engineCount;
		this->passangersCapacity = passangersCapacity;
	}

	void Show() {
		cout << "-------Airplane-------\n";
		Vehicle::Show();
		cout << "EngineCount: " << engineCount << endl << "PassangersCapacity: " << passangersCapacity << endl;
	}


};

class VehicleDepo {
public:
	stack<Vehicle*> vehicles;
	stack<Car*> cars;
	stack<Ship*> ships;
	stack<Airplane*> airplanes;

	void AddCar(Car* car) {
		cars.push(car);
	}
	void AddShip(Ship* ship) {
		ships.push(ship);
	}
	void AddAirplane(Airplane* airplane) {
		airplanes.push(airplane);
	}

	void ShowAllVehicles() {
		while (!cars.empty()) {
			cars.top()->Show();
			cars.pop();
		}
		while (!ships.empty()) {
			ships.top()->Show();
			ships.pop();
		}
		while (!airplanes.empty()) {
			airplanes.top()->Show();
			airplanes.pop();
		}

	}
};

void main() {
	VehicleDepo* vehicleDepo = new VehicleDepo();
	vehicleDepo->AddCar(new Car("mini", "cooper", Engine("bmw123", "bmw", 1.9), true));
	vehicleDepo->AddCar(new Car("lada", "vaz2107", Engine("123", "lada", 1.6), false));
	vehicleDepo->AddShip(new Ship("Yamaha", "SX220", Engine("TWIN TR-1 HIGH OUTPUT", "YAMAHA MARINE ENGINES", 1.6), false));
	vehicleDepo->AddShip(new Ship("Suzuki", "zs5000", Engine("QUATRO F-35 FULLSPEED", "BOENG MARINE ENGINES", 2.2), true));
	vehicleDepo->AddAirplane(new Airplane("Boeng","F35", Engine("6.3.3", "RolsRoys", 2.7), 4 , 256));
	vehicleDepo->AddAirplane(new Airplane("Bayraktar","TB6", Engine("0.0.0.", "TOGG", 5.5), 4 , 2));


	vehicleDepo->ShowAllVehicles();
}