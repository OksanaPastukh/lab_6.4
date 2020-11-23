//Lab_6.4
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Random(int* p, int n, int Low, int High)
{
	for (int i = 0; i < n; i++)
		p[i] = rand() % (High - Low + 1) + Low;
}

void Print(int* p, int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(3) << p[i] << " ";
	cout << "\n";
}
int Count(int* p, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (p[i] == 0)
			count++;
	return count;
}
int find_min_index(int* p,  int n)
{
	int min = p[0];
	int min_index = 0;
	for (int i = 1; i < n; i++)
		if (p[i] < min)
		{
			min = p[i];
			min_index = i;
		}
	return min_index;
}
int Sum(int* p,  int n, int min_index)

{
	int S = 0;
	for (int i = min_index + 1 ; i < n; i++)
			S += p[i];
	return S;
}
void Sort(int* p, int n) // метод обм≥ну (бульбашки)
{
	for (int i = 1; i <n; i++) // л≥чильник ≥терац≥й
	{
		int k = 0; // показник, чи були обм≥ни
		for (int j = 0; j < n - i; j++) // номер поточного елемента
			if (abs(p[j]) > abs(p[j + 1])) // €кщо порушено пор€док
			{ // - обм≥н елемент≥в м≥сц€ми
				int tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
				k = 1;
			}
		if (k == 0) // €кщо обм≥н≥в - не було,
			return; // то припин€Їмо процес
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int n;
	cout << "n = "; cin >> n;

	int* p = new  int[n];
	int Low;
	int High;
	cout << "Low = "; cin >> Low;
	cout << "High = "; cin >> High;
	Random(p, n, Low, High);
	Print(p, n);
	find_min_index(p, n);
	cout << "Count = " << Count(p, n) << endl;
	cout << "S = " << Sum(p, n, find_min_index(p, n)) << endl;
	Sort(p, n);
	Print(p, n);
	delete[] p;
	return 0;
}