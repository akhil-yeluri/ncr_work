#include<iostream>
#include<Windows.h>
#include<tchar.h>
using namespace std;
int _tmain(int argc, WCHAR * argv[], WCHAR * env[])
{
	HANDLE FileHandler;
	FileHandler = CreateFile(argv[1], GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	return 0;
	
}