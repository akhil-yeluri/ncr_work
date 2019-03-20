#include<iostream>
#include<Windows.h>

using namespace std;
int main()
{
	LPWSTR * arguments;
	int size;
	arguments = CommandLineToArgvW(GetCommandLineW(),&size);
	for (int i = 0; i < size; i++)
		wcout << arguments[i] << endl;
	int n;
	cin >> n;
	return 0;
}