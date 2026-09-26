#include <iostream>
#include <conio.h>
using namespace std;


//2

int* CreateArray(int size)
{
	int* arr = new int[size];
	return arr;
}

void InitArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

void ShowArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int* AddNewNumber(int* arr, int* size, int number)
{
	int* temp = new int[*size + 1];
	for (int i = 0; i < *size; i++)
	{
		temp[i] = arr[i];
	}
	temp[*size] = number;
	delete[] arr;
	arr = temp;
	(*size)++;
	return arr;
}

int* DeleteLast(int* arr, int* size)
{
	if (*size == 0) return arr;

	int* temp = new int[*size - 1];
	for (int i = 0; i < *size - 1; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	(*size)--;
	return arr;
}

int* DeleteByIndex(int* arr, int* size, int index)
{
	if (index < 0 || index >= *size) return arr;

	int* temp = new int[*size - 1];
	int j = 0;
	for (int i = 0; i < *size; i++)
	{
		if (i == index) continue;
		temp[j] = arr[i];
		j++;
	}
	delete[] arr;
	arr = temp;
	(*size)--;
	return arr;
}

int* InsertAt(int* arr, int* size, int index, int number)
{
	if (index < 0 || index > *size) return arr;

	int* temp = new int[*size + 1];
	for (int i = 0; i < index; i++)
	{
		temp[i] = arr[i];
	}
	temp[index] = number;
	for (int i = index; i < *size; i++)
	{
		temp[i + 1] = arr[i];
	}
	delete[] arr;
	arr = temp;
	(*size)++;
	return arr;
}













int main()
{

	

	int* pInt = new int(5);
	double* pDouble = new double(2.5);
	float* pFloat = new float(3.0f);

	double dobutok = (*pInt) * (*pDouble) * (*pFloat);

	cout << "Int value :" << *pInt << endl;
	cout << "Double v.. : " << *pDouble << endl;
	cout << "Float v... ; " << *pFloat << endl;
	cout << "Dobutok : " << dobutok << endl;

	delete pInt;
	delete pDouble;
	delete pFloat;

	





	int size = 3;
	int* arr = CreateArray(size);
	InitArray(arr, size);
	ShowArray(arr, size);

	char choice;
	int number, index;

	while (true)
	{
		cout << endl;
		cout << "1 - Add element" << endl;
		cout << "2 - Delete last element" << endl;
		cout << "3 - Delete element  index" << endl;
		cout << "4 - Insert element" << endl;
		cout << "5 - Show array" << endl;
		cout << "0 - Exit" << endl;
		cout << "Your choice --> ";
		choice = _getch();
		cout << choice << endl;

		if (choice == '0') break;

		if (choice == '1')
		{
			cout << "Enter number : "; cin >> number;
			arr = AddNewNumber(arr, &size, number);
			ShowArray(arr, size);
		}
		else if (choice == '2')
		{
			arr = DeleteLast(arr, &size);
			ShowArray(arr, size);
		}
		else if (choice == '3')
		{
			cout << "Enter index : "; cin >> index;
			arr = DeleteByIndex(arr, &size, index);
			ShowArray(arr, size);
		}
		else if (choice == '4')
		{
			cout << "Enter index : "; cin >> index;
			cout << "Enter number : "; cin >> number;
			arr = InsertAt(arr, &size, index, number);
			ShowArray(arr, size);
		}
		else if (choice == '5')
		{
			ShowArray(arr, size);
		}
	}

	delete[] arr;





}