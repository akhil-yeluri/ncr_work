using namespace std;
#include<Windows.h>
#include<iostream>
#define size 10
DWORD WINAPI ThreadProc(LPVOID lpparameter)
{
	for (int i = 0; i <=size; i++)
	{
		Sleep(1000);
		cout << i << endl;
	}
	return 0;
}

int main()
{
	HANDLE ThreadHandler;
	ThreadHandler = CreateThread(NULL,0,&ThreadProc,0,NULL,NULL);
	int n;
	cin >> n;
	return 0;
}