using namespace std;
#include<iostream>
template<class T>


void LinearSearch(T *arr,T element,int size)
{
	for(int i=0;i<size;i++)
		if (arr[i] == element)
		{
			cout << arr[i] << "is found at position " << i << " in the array";
			return;
		}
	cout << "Element not found in the array";
		return;
}

template<>
void LinearSearch(char *arr, char element, int size)
{
	for (int i = 0; i < size; i++)
		if (arr[i] == element)
		{
			cout << arr[i] << "is found at position " << i << " in the array";
			return;
		}
	cout << "Element not found in the array";
	return;
}




int main()
{
	int size,choice;
	cout << "Enter size of array\n";
	cin >> size;
	cout << "select array type\n1.INTEGER\n2.FLOAT\n3.DOUBLE\n4.CHARACTER\n";
	cin >> choice;
	if (choice == 1) 
	{
		int *array = new int[size];
		cout << "Enter elements to  array\n";
		for (int i = 0; i < size; i++)
			cin >> array[i];
		cout << "Enter element to search\n";
		int element;
		cin >> element;
		LinearSearch(array, element, size);
		return 1;
	}
	
	if (choice == 2)
	{
		float *arrayf = new float[size];
		cout << "Enter elements to  array\n";
		for (int i = 0; i < size; i++)
			cin >> arrayf[i];
		cout << "Enter element to search\n";
		float elementF;
		cin >> elementF;
		LinearSearch(arrayf, elementF, size);
		return 1;
	}

	if (choice == 3)
	{
		double *arrayD = new double[size];
		cout << "Enter elements to  array\n";
		for (int i = 0; i < size; i++)
			cin >> arrayD[i];
		cout << "Enter element to search\n";
		double elementD;
		cin >> elementD;
		LinearSearch(arrayD, elementD, size);
		return 1;
	}

	if (choice == 4)
	{
		char *arrayC = new char[size];
		cout << "Enter elements to  array\n";
		for (int i = 0; i < size; i++)
			cin >> arrayC[i];
		cout << "Enter character to search\n";
		char elementC;
		cin >> elementC;
		LinearSearch(arrayC, elementC, size);
		return 1;
	}
	else
	{
		cout << "Invalid option";
		return -1;
	}

	

	return 0;

}