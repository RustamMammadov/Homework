#include <iostream>
#include<assert.h>

using namespace std;

//Task 
// Class DynamicArray (template<class t>)
// Example: DynamicArray<double> da;
// Copy Constructor, Copy Assignment operator, Default Constructor
// [] operator overloading
// AddElementToEnd
// AddElementToHead
// AddElementByIndex
// DeleteElementByIndex
// Print()

template<class T>
class DynamicArray
{
private:
	T* dynamicArray;
	int size;

public:
	DynamicArray()
	{
		dynamicArray = nullptr;
		size = 0;
	}

	DynamicArray(DynamicArray& other)
	{
		delete[] dynamicArray;
		if (other.size == 0)
		{
			size = 0;
			dynamicArray = nullptr;
			return;
		}
		dynamicArray = new T[other.size];
		size = other.size;

		for (int i = 0; i < size; i++)
		{
			dynamicArray[i] = other[i];
		}
	}

	DynamicArray& operator=(const DynamicArray& other)
	{
		delete[] dynamicArray;
		if (other.size == 0)
		{
			size = 0;
			dynamicArray = nullptr;
			return *this;
		}
		dynamicArray = new T[other.size];
		size = other.size;

		for (int i = 0; i < size; i++)
		{
			dynamicArray[i] = other[i];
		}
		return *this;
	}

	T& operator[](int index)
	{
		assert(size > 0 && cout << "Empty Array\n\n");
		return dynamicArray[index];
	}

	void AddElementToEnd(T el)
	{
		T* temp = new T[size + 1];
		for (int i = 0; i < size; i++)
		{
			temp[i] = dynamicArray[i];
		}
		temp[size] = el;
		delete[] dynamicArray;
		dynamicArray = temp;
		temp = nullptr;
		size++;
	}

	void AddElementToHead(T el)
	{
		T* temp = new T[size + 1];
		temp[0] = el;
		for (int i = 0; i < size; i++)
		{
			temp[i + 1] = dynamicArray[i];
		}
		delete[] dynamicArray;
		dynamicArray = temp;
		temp = nullptr;
		size++;

	}

	void AddElementByIndex(T el, int index)
	{
		T* temp = new T[size + 1];
		for (int i = 0; i < index; i++)
		{
			temp[i] = dynamicArray[i];
		}
		temp[index] = el;

		for (int i = index; i < size; i++)
		{
			temp[i + 1] = dynamicArray[i];
		}
		delete[] dynamicArray;
		dynamicArray = temp;
		temp = nullptr;
		size++;
	}

	void DeleteElementByIndex(int index)
	{
		T* temp = new T[size - 1];
		for (int i = 0; i < index; i++)
		{
			temp[i] = dynamicArray[i];
		}
		for (int i = index; i < size; i++)
		{
			temp[i] = dynamicArray[i + 1];
		}
		delete[] dynamicArray;
		dynamicArray = temp;
		temp = nullptr;
		size--;
	}

	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << dynamicArray[i] << " ";
		}
		cout << endl;
	}


	~DynamicArray()
	{
		delete[] dynamicArray;
	}
};






int main()
{
	DynamicArray<double> arr;
	arr.AddElementToHead(1.4);
	arr.AddElementToHead(2.4);
	arr.AddElementToHead(3.4);
	arr.Print();
	arr.AddElementToHead(4.4);
	arr.Print();
	arr.AddElementToEnd(14.3);
	arr.Print();
	arr.AddElementByIndex(42.2, 2);
	arr.Print();
	arr.DeleteElementByIndex(2);
	arr.Print();
	arr.AddElementToHead(9.36);
	arr.Print();



}
