#include <iostream>
using namespace std;
#define tab "\t"
using std::cin;
using std::cout;
using std::endl;


template<typename T> T** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);
void FillRand(int arr[], const int n, int minRand=0, int maxRand=100);
void FillRand(double arr[], const int n, int minRand=0, int maxRand=100);
void FillRand(int** arr, int rows, const int cols, int minRand = 0, int maxRand = 100);

template <typename T> void Print(T arr[], const int n);
template <typename T> void Print(T** arr, const int rows, const int cols);

template <typename T> T* push_back (T arr[], int& n, const T value);
template <typename T> T* push_front(T arr[], int& n, T value);
template <typename T> T* insert    (T arr[], int& n, T value, int pos);

template <typename T> T* pop_back (T arr[], int& n);
template <typename T> T* pop_front(T arr[], int& n);
template <typename T> T* erase    (T arr[], int& n, int pos);

template <typename T> T** push_row_back (T** arr, int& rows, int cols);
template <typename T> T** push_row_front(T** arr, int& rows, int cols);
template <typename T> T** insert_row    (T** arr, int& rows, const int cols, int position);

template <typename T> T** pop_row_back (T** arr, int& rows, const int cols);
template <typename T> T** pop_row_front(T** arr, int& rows, const int cols);
template <typename T> T** erase_row    (T** arr, int& rows, const int cols,  int position);

template <typename T> void push_col_back (T** arr, const int rows, int& cols);
template <typename T> void push_col_front(T** arr, const int rows, int& cols);
template <typename T> void insert_col    (T** arr, const int rows, int& cols, int position);

template <typename T> void pop_col_back  (T** arr, const int rows, int& cols);
template <typename T> void pop_col_front (T** arr, const int rows, int& cols);
template <typename T> void erase_col     (T** arr, const int rows, int& cols,  int position);



//#define DINAMIC_MEMORY_1
#define DINAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DINAMIC_MEMORY_1
	int n = 5;
	cout << "Ведите размер массива:"; cin >> n;
	typedef double DataType;
	DataType* arr = new DataType[n];

	FillRand(arr, n);
	Print(arr, n);
	
	DataType value;

	cout << "Введите добавляемое значение"; cin >> value;
	int pos;
	

	cout << "push_back:" << tab;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << endl;

	cout << "Введите добавляемое значение"; cin >> value;
	cout << "push_front:" << tab;
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << endl;

	cout << "Введите позицию добавляемого значения"; cin >> pos;
	cout << "Введите добавляемое значение"; cin >> value;
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

	cout << "Введите позицию добавляемого значения"; cin >> pos;
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
	int** arr = Allocate<int>(rows, cols);



	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;

	cout << "push_row_back:" << endl;
	arr =  push_row_back( arr,rows, cols);
	FillRand(arr[rows-1],cols, 100, 1000);
	Print(arr, rows, cols);

	cout << "push_row_front:"<<endl;
	arr = push_row_front( arr,  rows, cols);
	FillRand(arr[0], cols, 100, 1000);
	Print(arr, rows, cols);

	int index_insert_row;
	cout << "Введите позицию добавляемой строки: "; cin >> index_insert_row;
	cout << "insert_row:" << endl;
	arr = insert_row(arr, rows, cols, index_insert_row);
	if (index_insert_row < rows)FillRand(arr[index_insert_row], cols, 100, 1000);
	Print(arr, rows, cols);

	cout << "pop_row_back:" << endl;
	arr = pop_row_back( arr, rows,  cols);
	Print(arr, rows, cols);

	cout << "pop_row_front:" << endl;
	arr= pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	int index_erase_row;
	cout << "Введите позицию удаляемой строки:"; cin >> index_erase_row;
	cout << "erase_row:" << endl;
	arr = erase_row(arr, rows, cols, index_erase_row);
	Print(arr, rows, cols);

	cout << "push_col_back:" << endl;
	push_col_back(arr,  rows, cols);
	Print(arr, rows, cols);

	cout << "push_row_front:" << endl;
	push_col_front(arr, rows, cols);;
	Print(arr, rows, cols);

	int index_insert_col;
	cout << "Введите позицию добавляемого столбцв:"; cin >> index_insert_col;
	cout << "insert_col:" << endl;
	insert_col(arr, rows, cols, index_insert_col);
	Print(arr, rows, cols);

	cout << "pop_col_back:" << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "pop_col_front:" << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	int inde_erase_col;
	cout << "Введите позицию удаляемого столбцв:"; cin >> inde_erase_col;
	 cout << "erase_col:" << endl;
	erase_col(arr, rows, cols, inde_erase_col);
	Print(arr, rows, cols);

	Clear(arr, rows);


#endif //DINAMIC_MEMORY_2
}
template <typename T> T** Allocate(const int rows, const int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
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
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
		*(arr + i) /= 100;
	}
}

void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = double(rand() % (maxRand - minRand) + minRand / 100);
		}
	}
}
template <typename T> void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
}template <typename T> void Print(T** arr, const int rows, const int cols)
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
template <typename T> T* push_back(T arr[], int& n, T  value)
{
	//1)создаем буферный массив
	T* buffer = new T[n + 1];
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
template <typename T> T* push_front(T arr[], int& n, T value)
{
	T* buffer = new T[++n];
	buffer[0] = value;
	for (int i = 1; i < n; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[]arr;
	arr = buffer;
	return arr;
}
template <typename T> T* insert(T arr[], int& n, T value, int pos)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i < pos ? i : i + 1] = arr[i];
	}
	delete[]arr;
	buffer[pos] = value;
	n++;
	return buffer;
}
template <typename T> T* pop_back( T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	return arr;
}
template <typename T> T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[]arr;
	arr = buffer;
	return arr;
}
template <typename T> T* erase(    T arr[], int& n, int pos)
{
	T* buffer = new T[--n];
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
template <typename T> T** push_row_back( T** arr, int& rows, int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	buffer[rows] = new T[cols] {};
	rows++;
	return buffer;
}
template <typename T> T** push_row_front(T** arr, int& rows, int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	buffer[0] = new T [cols] {};
	rows++;
	return buffer;
}
template <typename T> T** insert_row(    T** arr, int& rows, const int cols, int position)
{
	if (position >= rows)return arr;
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < position; i++) buffer[i] = arr[i];
	for (int i = position; i < rows; i++) buffer[i] = arr[i];
	delete[]arr;
	buffer[position] = new T[cols];
	rows++;
	return buffer;
}
template <typename T> T** pop_row_back( T** arr, int& rows, const int cols)
{
	T** buffer = new T*[--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[]arr[rows];
	delete[]arr;
	return buffer;
}
template <typename T> T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i + 1];
	delete[]arr[0];
	delete[]arr;
	return buffer;
}
template <typename T> T** erase_row(    T** arr, int& rows, const int cols,  int position)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i < position ? i : i++ ];
	}
	delete[]arr[rows];
	delete[]arr;
	return buffer;
}


template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template <typename T> void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T [cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template <typename T> void insert_col    (T** arr, const int rows,  int &cols, int position)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < position; j++) buffer[j] = arr[i][j];
		for (int j = position; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template <typename T> void pop_col_back  (T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < cols-1; j++) buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template <typename T> void pop_col_front (T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < cols - 1; j++) buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template <typename T> void erase_col     (T** arr,const int rows, int& cols, int position)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols-1];
		for (int j = 0; j < position; j++)buffer[j] = arr[i][j];
		for (int j = position; j < cols; j++)buffer[j] = arr[i][j+1];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}



