#include <iostream>
using namespace std;
#define tab "\t"


void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int& n, int value);
int* pop_back(int arr[], int& n);
int* push_front(int arr[], int& n, int value);
int* pop_front(int arr[], int& n);
int* insert(int arr[], int& n, int value, int pos);
int* erase(int arr[], int& n, int pos);
void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
	cout << "������ ������ �������:"; cin >> n;

	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	cout << endl;
	int value;

	cout << "������� ����������� ��������"; cin >> value;
	int pos;
	cout << "������� ����������� ��������"; cin >> pos;

	cout << "push_back:" << tab;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << endl;

	cout << "push_front:" << tab;
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << endl;

	cout << "insert:" << tab << tab;
	arr = insert(arr, n, value, pos);
	Print(arr, n);
	cout << endl;

	cout << "pop_back:" << tab;
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << endl;

	cout << "pop_front:" << tab;
	arr = pop_front(arr, n);
	Print(arr, n);
	cout << endl;

	cout << "erase:" << tab << tab;
	arr = erase(arr, n, pos);
	Print(arr, n);
	delete[]arr;

}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;

	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
}
int* push_back(int arr[], int& n, int value)
{
	//1)������� �������� ������
	int* buffer = new int[n + 1];
	//2)�������� �������� ��������� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)������� �������� ������ �� ������
	delete[]arr;
	//4)��������� ����� ��������� arr ������� ������ �������
	arr = buffer;
	//5)������ ����� ����� ����� �������� �������� � ����� �������:
	arr[n] = value;
	//����� ���������� �������� � ����� ������� ���������� ��� ��������� ������������� �� ����
	n++;

	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[++n];
	buffer[0] = value;
	for (int i = 1; i < n; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[]arr;
	arr = buffer;
	return arr;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[]arr;
	arr = buffer;
	return arr;
}
int* insert(int arr[], int& n, int value, int pos)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
		if (i == pos)
		{
			buffer[i] = value;

		}
		else if (i > pos)
		{
			buffer[i] = arr[i - 1];
		}



	}
	buffer[n] = arr[n - 1];
	n++;
	delete[]arr;
	arr = buffer;
	return arr;
}
int* erase(int arr[], int& n, int pos)
{
	int* buffer = new int[n--];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
		if (i >= pos)
		{
			buffer[i] = arr[i + 1];



		}

	}
	delete[]arr;
	arr = buffer;
	return arr;
}