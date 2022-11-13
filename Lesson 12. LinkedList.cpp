#include <iostream>

using namespace std;

class Node 
{
public:
	string data;
	Node* next;
	Node(const string& data) : data(data), next(nullptr) {}
};

class SinglyLinkedList 
{
	Node* head = nullptr;
public:
	void AddBegin(const string& value) 
	{
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
		newNode = nullptr;
	}

	void AddEnd(const string& value) 
	{
		Node* newNode = new Node(value);
		if (head == nullptr) 
		{
			head = newNode;
			return;
		}
		Node* temp = head;

		while (temp->next != nullptr)
			temp = temp->next;

		temp->next = newNode;
		temp = nullptr;
		newNode = nullptr;
	}

	void AddBefore(const string& name, const string value) 
	{
		Node* newNode = new Node(value);
		if (head != nullptr) 
		{
			Node* temp = head;
			if (name == head->data)
			{
				AddBegin(value);
				return;
			}
			while (temp->next->data != name) 
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
	void AddAfter(const string& x, const string value) 
	{
		Node* newNode = new Node(value);
		if (head != nullptr) 
		{
			Node* temp = head;
			while (temp->data != x) 
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}

	void DeleteEnd() {
		if (head != nullptr) 
		{
			Node* temp = head;
			while (temp->next->next != nullptr) 
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next = nullptr;
		}
	}

	void DeleteBegin() 
	{
		Node* temp = head->next;
		delete head;
		head = temp;
	}


	void Print() 
	{

		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}


	void DeleteByValue(const string& value)
	{
		Node* temp = head;
		while (temp->next->data != value)
		{
			temp = temp->next;
		}
		Node* n = temp->next->next;
		delete temp->next;
		temp->next = n;
	}
};

void main() 
{
	SinglyLinkedList singleL;
	singleL.AddBegin("Islam");
	singleL.AddBefore("Islam","Huseyn");
	cout << endl;
	singleL.Print();
	cout << endl;
	singleL.AddAfter("Huseyn","Rustam");
	cout << endl;
	singleL.Print();
	cout << endl;
	singleL.AddBegin("Azer");
	singleL.AddBegin("Shamil");
	singleL.DeleteByValue("Huseyn");
	cout << endl;
	singleL.Print();
	cout << endl;
}