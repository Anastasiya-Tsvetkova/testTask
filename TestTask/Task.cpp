#include <iostream>
#include <fstream>
using namespace std;

int ** createMatrix(int n, int m);
void printMatrix(int **p, int n, int m);
int **deleteMatrix(int **p, int n);
void countPlaces(int **p, int n, int m);

void main()
{
	ifstream in("sourceData.txt"); // ���������� ������ �� �����
	if (in.is_open())
	{
		int n, m, k; // n - ����, m - �������, k - ���������� ���������� �����
		in >> n >> m >> k;


		int ** p = createMatrix(n, m);

		// ����, ����������� ������� ����������� ������  
		for (int i = 0; i < k; i++)
		{
			int r, c1, c2; // r - ���, ��� ���������� ���������� ����, �1 - ������ ����������� ����, �2 - ����� ����������� ����
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

//�������� ������ �������
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

// ������� ��� ����������� �����,���� ����� ��������� ������ 
// ���������� ������� ��������� � ������������ ��������� �� �������� �����
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

// ����� ����������� ������� � �������
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

// ����� ��� ������� ������ (������ garbage collector � Java)  
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