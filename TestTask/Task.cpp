#include <iostream>
#include <fstream>
using namespace std;

int ** createMatrix(int n, int m);
void printMatrix(int **p, int n, int m);
int **deleteMatrix(int **p, int n);
void countPlaces(int **p, int n, int m);

void main()
{
	ifstream in("sourceData.txt"); // считывание данных из файла
	if (in.is_open())
	{
		int n, m, k; // n - ряды, m - колонки, k - количество трамвайных путей
		in >> n >> m >> k;


		int ** p = createMatrix(n, m);

		// цикл, заполняющий матрицу трамвайными путями  
		for (int i = 0; i < k; i++)
		{
			int r, c1, c2; // r - ряд, где расположен трамвайный путь, с1 - начало трамвайного пути, с2 - конец трамвайного пути
			in >> r >> c1 >> c2;
			for (int j = c1; j <= c2; j++)
			{
				p[r - 1][j - 1] = 1;
			}
		}
		in.close();
		printMatrix(p, n, m);
		countPlaces(p, n, m);		

		p = deleteMatrix(p, n);
	}
}

//создание пустой матрицы
int ** createMatrix(int n, int m) 
{
	int ** p = new int*[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] = 0;
		}
	}
	return p;
}

// счетчик для определения места,куда можно поставить фонарь 
// перебирает матрицу элементов и подсчитывает свободные от трамваев места
void countPlaces(int **p, int n, int m) 
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (p[i][j] != 1)
				count++;
		}
	}
	cout << count << endl;
}

// вывод заполненной матрицы в консоль
void printMatrix(int **p, int n, int m)  
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}

// метод для очитски памяти (аналог garbage collector в Java)  
int **deleteMatrix(int **p, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] p[i];
	}
	delete[]p;
	p = NULL;
	return p;

}