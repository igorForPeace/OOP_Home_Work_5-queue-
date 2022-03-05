#pragma once
#include "All_Libraries.h"

class Queue
{
private:
	string* data;
	int* priorities;
	int max_count;
	int real_count;
public:
	Queue(unsigned int max_count); 
	~Queue();
	void Clear(); // очистка списка
	bool IsEmpty() const; // проверка на пустую очередь
	bool IsFull() const; 
	int GetCount() const;
	void Enqueue(string data, int priority); 
	void Print() const;
	void Dequeue();
};

