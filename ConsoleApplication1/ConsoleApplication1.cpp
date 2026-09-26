
#include <iostream>
using namespace std;


//2
//
//const int n = 10;  
//
//void InitArray(int* arr, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Enter element " << i << endl;
//		cin >> *(arr + i);
//	}
//}
//
//void ShowForward(int* arr, int n)
//{
//	for (int i = 0; i < n; i++)
//		cout << *(arr + i) << " ";
//	cout << endl;
//}
//
//void ShowBackward(int* arr, int n)
//{
//	for (int i = n - 1; i >= 0; i--)
//		cout << *(arr + i) << " ";
//	cout << endl;
//}
//
//int Summa(int* arr, int n)
//{
//	int summa = 0;
//	for (int i = 0; i < n; i++)
//		summa += *(arr + i);
//	return summa;
//}
//
////3
//const int N = 10;
//
//void ShowArray(int* arr, int N)
//{
//	for (int i = 0; i < N; i++)
//		cout << *(arr + i) << " ";
//	cout << endl;
//}

//4
const int A = 10;

void ShowArray(int* arr, int A)
{
	for (int i = 0; i < A; i++)
		cout << *(arr + i) << " ";
	cout << endl;
}

int main()
{
  
	//1

	//int a, b, c;
	//cout << "Enter a, b, c --> ";
	//cin >> a >> b >> c;

	//int* pa = &a;
	//int* pb = &b;
	//int* pc = &c;

	//int dobutok = (*pa) * (*pb) * (*pc);
	//double serednye = (*pa + *pb + *pc) / 3.0;

	//int minVal = *pa;
	//if (*pb < minVal) minVal = *pb;
	//if (*pc < minVal) minVal = *pc;

	//cout << "Dobutok = " << dobutok << endl;
	//cout << "Serednye = " << serednye << endl;
	//cout << "Min = " << minVal << endl;





	//2

	//int arr[n];

	//InitArray(arr, n);
	//ShowForward(arr, n);
	//ShowBackward(arr, n);

	//cout << "summa = " << Summa(arr, n) << endl;


	////3
	//int arr[N] = { 5, 12, 3, 45, 7, 1, 22, 9, 40, 6 };

	//int* pMax = arr;
	//int* pMin = arr;

	//for (int i = 1; i < N; i++)
	//{
	//	if (*(arr + i) > *pMax) pMax = arr + i;
	//	if (*(arr + i) < *pMin) pMin = arr + i;
	//}

	//ShowArray(arr, N);
	//cout << endl;
	//int temp = *pMax;
	//*pMax = *pMin;
	//*pMin = temp;
	//cout << endl;
	//ShowArray(arr, N);


	////4
	int arr[A] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "Before: ";
	ShowArray(arr, A);

	int* p = arr;

	for (int i = 0; i < A - 1; i += 2)
	{
		int temp = *(p + i);
		*(p + i) = *(p + i + 1);
		*(p + i + 1) = temp;
	}

	cout << "After: ";
	ShowArray(arr, A);

}

