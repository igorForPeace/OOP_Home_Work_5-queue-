#include "Queue.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	Queue A(25);
	A.Enqueue("Работник Сидоров", 1);
	A.Enqueue("Бугалтер Сидорова", 2);
	A.Print();
	A.Enqueue("Помощник Директора Петров", 3);
	A.Print();
	A.Enqueue("Директор Коблев", 5);
	A.Print();
	A.Enqueue("ЗамДиректора Васильев", 4);
	A.Print();
	A.Dequeue();
	A.Print();
	
	
	return 0;
}

