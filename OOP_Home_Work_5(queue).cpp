#include "Queue.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	Queue A(25);
	A.Enqueue("�������� �������", 1);
	A.Enqueue("�������� ��������", 2);
	A.Print();
	A.Enqueue("�������� ��������� ������", 3);
	A.Print();
	A.Enqueue("�������� ������", 5);
	A.Print();
	A.Enqueue("������������ ��������", 4);
	A.Print();
	A.Dequeue();
	A.Print();
	
	
	return 0;
}

