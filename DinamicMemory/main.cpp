#include <iostream>
using namespace std;
#define tab "\t"
using std::cin;
using std::cout;
using std::endl;


int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);
void FillRand(int arr[], const int n, int minRand, int maxRand);
void FillRand(int** arr, int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* pop_back(int arr[], int& n);
int* push_front(int arr[], int& n, int value);
int* pop_front(int arr[], int& n);
int* insert(int arr[], int& n, int value, int pos);
int* erase(int arr[], int& n, int pos);

int* push_back(int arr[], int& n, int value);

int** push_row_back(int** arr, int& rows, int cols);
int** push_row_front(int** arr, int& rows, int cols);
int** insert_row(int** arr, int& rows, const int cols, int position);

int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols,  int position);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
void insert_col(int** arr, const int rows, int& cols, int position);

void pop_col_back(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);
void erase_col(int** arr, const int rows, int& cols,  int position);



//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DINAMIC_MEMORY_1
	int n = 5;
	cout << "Ведите размер массива:"; cin >> n;

	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	cout << endl;
	int value;

	cout << "Введите добавляемое значение"; cin >> value;
	int pos;
	cout << "Введите добавляемое значение"; cin >> pos;

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
#endif //DINAMIC_MEMORY_1

#ifdef DINAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк:"; cin >> rows;
	cout << "Введите количество элементов строки:"; cin >> cols;
	int** arr = Allocate(rows, cols);



	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;

	arr =  push_row_back( arr,rows, cols);
	FillRand(arr[rows-1],cols, 100, 1000);
	Print(arr, rows, cols);
	arr = push_row_front( arr,  rows, cols);
	FillRand(arr[0], cols, 100, 1000);
	Print(arr, rows, cols);
	int index;
	cout << "Введите позицию добавляемой строки: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	if (index < rows)FillRand(arr[index], cols, 100, 1000);
	Print(arr, rows, cols);

	arr = pop_row_back( arr, rows,  cols);
	Print(arr, rows, cols);

	arr= pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите позицию удаляемой строки:"; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	push_col_back(arr,  rows, cols);
	Print(arr, rows, cols);

	push_col_front(arr, rows, cols);;
	Print(arr, rows, cols);

	
	cout << "Введите позицию добавляемого столбцв:"; cin >> index;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);


	cout << "Введите позицию удаляемого столбцв:"; cin >> index;
	erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	Clear(arr, rows);


#endif //DINAMIC_MEMORY_2
}
int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[] arr;
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;

	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
			/*cout<< *(*(arr + i) + j)<<tab;*/
			
		}
		cout << endl;
		
	}
}
int* push_back(int arr[], int& n, int value)
{
	//1)создаем буферный массив
	int* buffer = new int[n + 1];
	//2)копируем значения элементов исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)удаляем исходный массив из памяти
	delete[]arr;
	//4)подменяем адрес указателя arr адресом нового массива
	arr = buffer;
	//5)только после всего этого добавить значение в конец массива:
	arr[n] = value;
	//после добавления элемента в конец массива количество его элементов увеличивается на один
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
	int* buffer = new int[--n];
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
int** push_row_back(int** arr, int& rows, int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
int** push_row_front(int** arr, int& rows, int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	buffer[0] = new int [cols] {};
	rows++;
	return buffer;
}
int** insert_row(int** arr, int& rows, const int cols, int position)
{
	if (position >= rows)return arr;
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < position; i++) buffer[i] = arr[i];
	for (int i = position; i < rows; i++) buffer[i] = arr[i];
	delete[]arr;
	buffer[position] = new int[cols];
	rows++;
	return buffer;
}
int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int*[--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[]arr[rows];
	delete[]arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i + 1];
	delete[]arr[0];
	delete[]arr;
	return buffer;
}
int** erase_row(int** arr, int& rows, const int cols,  int position)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i < position ? i : i++ ];
	}
	delete[]arr[rows];
	delete[]arr;
	return buffer;
}

void push_col_back(int** arr, const int rows, int &cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void insert_col(int** arr, const int rows,  int &cols, int position)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < position; j++) buffer[j] = arr[i][j];
		for (int j = position; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void pop_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols-1; j++) buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void pop_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++) buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}

void erase_col(int** arr,const int rows, int& cols, int position)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols-1];
		for (int j = 0; j < position; j++)buffer[j] = arr[i][j];
		for (int j = position; j < cols; j++)buffer[j] = arr[i][j+1];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}



