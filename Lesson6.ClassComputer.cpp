#include <iostream>
#include <assert.h>

using namespace std;

//
//class: Computer
//fields:
//id(static)
//object_Id
//model(char*)
//vendor(char*)
//videocard(char*)
//monitor(char*)
//cpu_hz
//core
//ram
//disk_size
//isSSD(bool)
//cin, cout overload
//constructors
//destructor

class Computer {

#pragma region Field

	static int staticId;
	int id;
	char* vendor;
	char* model;
	char* videoCard;
	char* monitor;
	double cpuHz;
	int core;
	int ram;
	int discSize;
	bool isSSD;

#pragma endregion

public:

#pragma region Setter

	void SetVendor(const char* value) 
	{
		delete[] vendor;
		int size = strlen(value) + 1;
		vendor = new char[size];
		strcpy_s(vendor, size, value);
	}

	void SetModel(const char* value) 
	{
		delete[] model;
		int size = strlen(value) + 1;
		model = new char[size];
		strcpy_s(model, size, value);
	}

	void SetVideoCard(const char* value) 
	{
		delete[] videoCard;
		int size = strlen(value) + 1;
		videoCard = new char[size];
		strcpy_s(videoCard, size, value);
	}

	void SetMonitor(const char* value) 
	{
		delete[] monitor;
		int size = strlen(value) + 1;
		monitor = new char[size];
		strcpy_s(monitor, size, value);
	}

	void SetCpuHz(double value) 
	{
		cpuHz = value;
	}

	void SetCore(int value) 
	{
		core = value;
	}

	void SetRam(int value) 
	{
		ram = value;
	}

	void SetDiscSize(int value) 
	{
		discSize = value;
	}

	void SetIsSSD(bool value) 
	{
		isSSD = value;
	}

#pragma endregion

#pragma region Getter

	int GetId() const { return id; }
	const char* GetVendor() const { return vendor; }
	const char* GetModel() const { return model; }
	const char* GetVideoCard() const { return videoCard; }
	const char* GetMonitor() const { return monitor; }
	double GetCpuHz() const { return cpuHz; }
	int GetCore() const { return core; }
	int GetRam() const { return ram; }
	int GetDiscSize() const { return discSize; }
	bool GetIsSSD() const { return isSSD; }

#pragma endregion

#pragma region Constructor

	Computer() 
	{
		id = staticId++;
		vendor = nullptr;
		model = nullptr;
		videoCard = nullptr;
		monitor = nullptr;
		SetCpuHz(0);
		SetCore(0);
		SetRam(0);
		SetDiscSize(0);
		SetIsSSD(0);
	}

	Computer(const char* vendor, const char* model, const char* videoCard, const char* monitor, double cpuHz, int core, int ram, int discSize, bool isSsd) 
	{
		id = staticId++;
		SetVendor(vendor);
		SetModel(model);
		SetVideoCard(videoCard);
		SetMonitor(monitor);
		SetCpuHz(cpuHz);
		SetCore(core);
		SetRam(ram);
		SetDiscSize(discSize);
		SetIsSSD(isSSD);
	}

	Computer(const Computer& comp) 
	{
		id = comp.id;
		SetVendor(comp.vendor);
		SetModel(comp.model);
		SetVideoCard(comp.videoCard);
		SetMonitor(comp.monitor);
		SetCpuHz(comp.cpuHz);
		SetCore(comp.core);
		SetRam(comp.ram);
		SetDiscSize(comp.discSize);
		SetIsSSD(comp.isSSD);
	}

#pragma endregion

#pragma region Overload

	Computer& operator=(const Computer& comp) 
	{
		id = comp.id;
		SetVendor(comp.vendor);
		SetModel(comp.model);
		SetVideoCard(comp.videoCard);
		SetMonitor(comp.monitor);
		SetCpuHz(comp.cpuHz);
		SetCore(comp.core);
		SetRam(comp.ram);
		SetDiscSize(comp.discSize);
		SetIsSSD(comp.isSSD);
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Computer& obj) 
	{
		out << "\nComputer Info : \n\n"
			<< "ObjectId:" << obj.id
			<< "\nVendor: " << obj.vendor
			<< "\nModel: " << obj.model
			<< "\nMonitor: " << obj.monitor
			<< "\nCpu-Hz: " << obj.cpuHz
			<< "\nCore: " << obj.core
			<< "\nRam: " << obj.ram
			<< "\nDiskSize: " << obj.discSize
			<< "\nSSD: " << obj.isSSD;
		return out;
	}

	friend istream& operator>>(istream& in, Computer& obj) 
	{
		char* bf = new char[32];
		cout << "Model: ";
		in.getline(bf, 32);
		obj.SetModel(bf);

		cout << "Vendor: ";
		in.getline(bf, 32);
		obj.SetVendor(bf);

		cout << "Videocard: ";
		in.getline(bf, 32);
		obj.SetVideoCard(bf);

		cout << "Monitor: ";
		in.getline(bf, 32);
		obj.SetMonitor(bf);

		cout << "Cpu Hz: ";
		double y;
		cin >> y;
		obj.SetCpuHz(y);

		cout << "Core: ";
		int c;
		cin >> c;
		obj.SetCore(c);

		cout << "Ram: ";
		int r;
		cin >> r;
		obj.SetRam(r);

		cout << "Disc Size: ";
		int d;
		cin >> d;
		obj.SetDiscSize(d);

		cout << "Have you SSD ? (1 = Yes, 0 = No) : ";
		int i;
		cin >> i;
		obj.SetIsSSD(i);

		delete[] bf;
		return in;
	}

#pragma endregion

#pragma region Destructor

	~Computer() {
		delete[] vendor;
		delete[] model;
		delete[] videoCard;
		delete[] monitor;
	}

#pragma endregion

};

int Computer::staticId = 100;

/*
class: ComputerStore
store_name(char*)
store_address(char*)
Computer** computers; (array)
addComputer();
deleteComputer(int id);
cin, cout overload
constructors
destructor
*/

class CompStore 
{
#pragma region Field

	char* name;
	char* address;
	Computer** computers;
	int count;

#pragma endregion

public:

#pragma region Constructor

	CompStore(const char* name, const char* address) 
	{
		SetName(name);
		SetAddress(address);
		computers = nullptr;
		count = 0;
	}

#pragma endregion

#pragma region Setter

	void SetName(const char* value) 
	{
		delete[] name;
		int size = strlen(value) + 1;
		name = new char[size];
		strcpy_s(name, size, value);
	}

	void SetAddress(const char* value) 
	{
		delete[] address;
		int size = strlen(value) + 1;
		address = new char[size];
		strcpy_s(address, size, value);
	}

#pragma endregion

#pragma region Getter

	const char* GetName() { return name; }
	const char* GetAddress() { return address; }

#pragma endregion

#pragma region Method

	void AddComputer(const Computer* value) 
	{
		Computer** temp = new Computer * [count + 1];
		for (int i = 0; i < count; i++)
			temp[i] = computers[i];
		temp[count] = new Computer(*value);
		delete[] computers;
		computers = temp;
		count++;
		temp = nullptr;
	}

	void DeleteComputer(int id) 
	{
		int index = -1;
		for (int i = 0; i < count; i++) 
		{
			if (computers[i]->GetId() == id) 
			{
				index = i;
				break;
			}
		}
		if (index != -1) 
		{
			Computer** temp = new Computer * [count - 1];
			for (int i = 0; i < index; i++) 
			{
				temp[i] = computers[i];
			}

			for (int i = index; i < count; i++) 
			{
				temp[i] = computers[i + 1];
			}
			delete[] computers;
			computers = temp;
			count--;
			temp = nullptr;
		}
	}

#pragma endregion

#pragma region Overload

	friend ostream& operator<<(ostream& out, const CompStore& obj) {
		out << obj.name << " ( ";
		out << obj.address << " )\n";
		for (int i = 0; i < obj.count; i++) 
		{
			cout << *obj.computers[i] << endl;
		}
		return out;
	}

#pragma endregion

#pragma region Destructor

	~CompStore() {
		for (int i = 0; i < count; i++)
			delete computers[i];
		delete[] computers;
	}

#pragma endregion
};

void main() {
	Computer* com = new Computer("Hp", "pavilion", "iRIS xe", "OLED", 4.3, 8, 32, 1024, true);
	CompStore store("Compstore", "Shamaxi");
	store.AddComputer(com);
	store.AddComputer(new Computer("Xiaomi", "gameX", "gforce gtx256", "OLED", 5.7, 16, 32, 2048, true));
	cout << store << "\n\n";
	store.DeleteComputer(101);
	cout << store << "\n\n";
}