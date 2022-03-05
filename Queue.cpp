#include "Queue.h"

Queue::Queue(unsigned int max_count)
{
	this->max_count = max_count;
	data = new string[max_count];
	priorities = new int[max_count];
	real_count = 0;
}

Queue::~Queue()
{
	if (data != nullptr)
	{
		delete[] data;
	}
	if (priorities!=nullptr)
	{
		delete[] priorities;
	}
}

void Queue::Clear()
{
	real_count = 0;
}

bool Queue::IsEmpty() const
{
	return real_count == 0;
}

bool Queue::IsFull() const
{
	return real_count == max_count;
}

int Queue::GetCount() const
{
	return real_count;
}

void Queue::Enqueue(string value, int priority)
{
	
	if (real_count == 0)
	{
		data[real_count] = value;
		priorities[real_count] = priority;
		++real_count;
	}
	else if (!IsFull())
	{
		string *temp_data = new string[max_count];
		int* temp_priorities = new int[max_count];
		int position = 0;

		for (int i = 0; i < real_count; i++)
		{
			if (priority>=priorities[i])
			{
				position = i;
				break;
			}
			else
			{
				continue;
			}
		}

		for (int i = 0; i < real_count+1; i++)
		{
			temp_data[i] = data[i];
			temp_priorities[i] = priorities[i];
			if (i == position)
			{
				temp_data[i] = value;
				temp_priorities[i] = priority;
				for (int i = position; i < real_count; i++)
				{
					temp_data[i+1] = data[i];
					temp_priorities[i+1] = priorities[i];
				}
				break;
			}
		}
		delete[] this->data;
		delete[]this->priorities;
		this->data = temp_data;
		this->priorities = temp_priorities;
		++real_count;
	}
	else
	{
		throw "OPPS!";
	}
}

void Queue::Print() const
{
	cout << "-----------------------------------" << endl;
	for (int i = 0; i < real_count; i++)
	{
		cout << i + 1 << ")" << data[i] << endl;
	}
	cout << "-----------------------------------" << endl;
}

void Queue::Dequeue()
{
	if (!IsEmpty())
	{
		int max_priority = priorities[0];
		int max_priority_position = 0;
		for (int i = 0; i < real_count; i++)
		{
			if (max_priority < priorities[i])
			{
				max_priority = priorities[i];
				max_priority_position = i;
			}
		}

		string result = data[max_priority_position];

		for (int i = max_priority_position; i < real_count - 1; i++)
		{
			data[i] = data[i + 1];
			priorities[i] = priorities[i + 1];
		}
		real_count--;
	}
	else
	{
		throw "OPPS!";
	}
}
