
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node(int data, Node* next = nullptr)
	{
		this->data = data;
		this->next = next;
	}
};
struct Queue
{
	Node* head;
	Node* tail;
	Queue()
	{
		head = tail = nullptr;
	}
	void Enqueue(int data)
	{
		Node* temp = new Node(data);
		if (head == nullptr)
		{
			head = temp;
		}
		else
		{
			tail->next = temp;
		}
		tail = temp;
	}

	void Dequeue()
	{
		if (head != nullptr)
		{
			Node* toDelete = head;
			head = head->next;
			delete toDelete;
		}
	}
	void free()
	{
		while (head != nullptr)
		{
			Dequeue();
		}
	}
};
int main()
{
	int n;
	int k;
	cin >> n;
	cin >> k;
	
	int data;
	Queue smallQ;
	int min=10000;
	for (int i = 0; i < k-1; i++)
	{
			cin >> data;
			smallQ.Enqueue(data);
			if (min > data)
			{
				min = data;
			}
	}
	
	long sum = 0;
	Node* temp = smallQ.head;
	long removedNumber=100;
	for (int i = 0; i < n+1  - k; i++)
	{
		cin >> data;
		smallQ.Enqueue(data);
		temp = smallQ.head;
		if (removedNumber == min)
		{
			min = temp->data;
			for (int j = 0; j < k; j++)
			{
				if (temp->data < min)
					min = temp->data;
				temp = temp->next;
			}
		}
		else
		{
			if (min > smallQ.tail->data)
				min = smallQ.tail->data;
		}
		sum += min;
		removedNumber = smallQ.head->data;
		smallQ.Dequeue();
		
	}
	cout << sum;
	smallQ.free();
	return 0;
}
