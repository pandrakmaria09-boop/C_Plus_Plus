#include <iostream>
using namespace std;
/*
void InitArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}
void ShowArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int LinearSearch(int arr[], int size, int key) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
			return i;
	}
	return -1;
}
void selectSort(int arr[], int size)
{
	int temp, index;
	for (int i = 0; i < size; i++)
	{
		index = i;
		temp = arr[i];
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < temp) {
				temp = arr[j];
				index = j;
			}
		}
		if (index != i)
		{
			arr[index] = arr[i];
			arr[i] = temp;
		}
	}
}
void Sort(int arr[], int size, int parameter)
{
	if (parameter == 0)//sort ascing
		if (parameter == 1)//sort descing
}
void BubbleSort(int arr[], int size)
{
	int temp;
	for (int i = 0; i < size; i++)//15
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j]) {
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void ShakerSort(int arr[], int size)
{
	int j, index = size - 1;
	int left = 1, right = size - 1;
	int temp;
	do
	{
		for (j = right; j >= left; j--)
		{
			if (arr[j - 1] > arr[j]) {
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
			index = j;
		}
		left = index + 1;
		for (j = left; j <= right; j++)
		{
			if (arr[j - 1] > arr[j]) {
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
			index = j;
		}
		right = index - 1;

	} while (left < right);

}
void InsertSort(int arr[], int size)
{
	//11 4 2 7 3 11 8 9 6 
	int temp;
	int j;
	for (int i = 0; i < size; i++)
	{
		//i = 1;		
		temp = arr[i];//4
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
		{
			//j = 0
			//arr[j + 1] = 4
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}

}*/





//1 завдання


void ShowArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void InitArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100;    //rand
}

void Sort(int arr[], int size, int order = 1)
{
	int temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (order == 0)  // за зрост
			{
				if (arr[j - 1] > arr[j])
				{
					temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
			}
			else if (order == 1)  // за спад
			{
				if (arr[j - 1] < arr[j])
				{
					temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}

}









//2 завдання

void Task2()
{
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "\n========== 2 ==========" << endl;

	const int size = 15;
	int arr[size];

	for (int i = 0; i < size; i++)
		arr[i] = rand() % 41 - 20; 

	cout << "masiv ";
	ShowArray(arr, size);

	
	int leftNegative = -1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			leftNegative = i;
			break;  
		}
	}

	int rightNegative = -1;
	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[i] < 0)
		{
			rightNegative = i;
			break;
		}
	}

	cout << leftNegative <<  arr[leftNegative] << endl;
	cout << rightNegative  << arr[rightNegative] << endl;


	if (leftNegative != -1 && rightNegative != -1 && leftNegative < rightNegative)
	{
		cout << "\n element between them ";
		for (int i = leftNegative + 1; i < rightNegative; i++)
			cout << arr[i] << " ";
		cout << endl;


		int temp;
		for (int i = leftNegative + 1; i < rightNegative; i++)
		{
			for (int j = rightNegative - 1; j > leftNegative + i - leftNegative - 1; j--)
			{
				if (arr[j - 1] > arr[j])
				{
					temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
			}
		}

		cout << "after sort element between them ";
		ShowArray(arr, size);
	}
	else
	{
		cout << "error" << endl;
	}
}
int main()
{
	srand(time(0));
	const int size = 15;
	int arr[size];
	InitArray(arr, size);
	ShowArray(arr, size);
	//selectSort(arr, size);
	//BubbleSort(arr, size);
	//ShakerSort(arr, size);
	//InsertSort(arr, size);
	ShowArray(arr, size);
	/*int searchKey, indexFind;
	cout << "Enter search key --> ";
	cin >> searchKey;
	indexFind = LinearSearch(arr, size, searchKey);
	if (indexFind != -1)
	{
		cout << "Element [" << searchKey << "] find in index ["
			<< indexFind << "]" << endl;
	}
	else
	{
		cout << "Element " << searchKey << " not found " << endl;
	}*/

	srand(time(0));









	//1


	cout << "========== 1 ==========" << endl;

	const int size1 = 10;
	int arr1[size1];

	InitArray(arr1, size1);
	cout << "masiv: ";
	ShowArray(arr1, size1);

	Sort(arr1, size1, 0);
	cout << "after sort zrostania ";
	ShowArray(arr1, size1);

	InitArray(arr1, size1);
	cout << "\n new masiv: ";
	ShowArray(arr1, size1);

	Sort(arr1, size1, 1);
	cout << "after sort spadania";
	ShowArray(arr1, size1);

	InitArray(arr1, size1);
	cout << "\n new masiv: ";
	ShowArray(arr1, size1);

	Sort(arr1, size1); 
	cout << "za spadania ";
	ShowArray(arr1, size1);




	//2
	Task2();

	return 0;
	return 0;
}



