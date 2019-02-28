#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;

int _tmain(int argc,WCHAR *argv[],WCHAR env[])
{
	LPWSTR * arguments;
	int size;
	arguments = CommandLineToArgvW(GetCommandLineW(), &size);
	for (int i = 0; i < size; i++)
		wcout << arguments[i] << endl;
	for (int i = 0; i < argc; i++)
		wcout << argv[i] << endl;
	int n;
	cin >> n;
	return 0;
}