#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
void Create(int** mas, const int rowCount, int  colCount, int A, int B) {

	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j <  colCount; j++) {
			mas[i][j] = A + rand() % (B - A + 1);
		}
	}
}
void Print(int** mas, const int rowCount, int  colCount) {

	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j <  colCount; j++) {
			cout << setw(4) << mas[i][j];
		}
		cout << endl;
	}
}

void Change(int** mas, int row1, int row2, int colCount) {

	int tmp;
	for (int j = 0; j < colCount; j++) {
		tmp = mas[row1][j];
		mas[row1][j] = mas[row2][j];
		mas[row2][j] = tmp;
	}
}

void Sort(int** mas, int rowCount, int  colCount) {
	for (int i0 = 0; i0 < rowCount-1; i0++) {
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++) {
			if (mas[i1][0] > mas[i1 + 1][0] ||
				(mas[i1][0] == mas[i1 + 1][0] && mas[i1][1] > mas[i1 + 1][1]) ||
				(mas[i1][1] == mas[i1 + 1][1] && mas[i1][2] > mas[i1 + 1][2]))
			{
				Change(mas, i1, i1 + 1,  colCount);
			}
		}
	}
}

int Numbers(int** mas, int rowCount, int colCount) {
	int num = 0;
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			if(mas[i][j]<0 && !(mas[i][j] % 4 ==0)){
			
				num++;

			}
		}
	}
	return num;
}
int Suma(int** mas, int rowCount, int colCount) {
	int sum = 0;
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			if (mas[i][j] < 0 && !(mas[i][j] % 4 == 0)) {

				sum += mas[i][j];

			}
		}
	}
	return sum;
}

void Zamina_0(int** mas, int rowCount, int colCount) {
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			if (mas[i][j] < 0 && !(mas[i][j] % 4 == 0)) {

				mas[i][j] = 0;
			}
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int rowCount = 8;
	int colCount = 5;

	int** T = new int* [rowCount];
	for (int i = 0; i < rowCount; i++) {

		T[i] = new int[colCount];
	}

	Create(T, rowCount, colCount, -17, 14);
	cout << "T = { " << endl;
	Print(T, rowCount, colCount);
	cout << "    }" << endl;

	Sort(T, rowCount, colCount);
	cout << " Sort T = { " << endl;
	Print(T, rowCount, colCount);
	cout << "    }" << endl;

	int num = Numbers(T, rowCount, colCount);
	cout << "Numbers = " << num << endl;
	
	int sum = Suma(T, rowCount, colCount);
	cout << "Suma = " << sum << endl;
	
	Zamina_0(T, rowCount, colCount);
	cout << " Zamina_0 T = { " << endl;
	Print(T, rowCount, colCount);
	cout << "    }" << endl;


	for (int i = 0; i < rowCount; i++)
		delete[]T[i];
	delete[]T;

	return 0;
}
