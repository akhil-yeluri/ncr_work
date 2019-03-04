using namespace std;
#include<Windows.h>
#include<iostream>
#define limit 1000
DWORD exitcode;
DWORD WINAPI ThreadProc(LPVOID lpparameter)
{
	for (int i = 0; i <=limit; i++)
	{
		Sleep(100);
		cout << i << endl;
	}
	ExitThread(exitcode);
	return 0;
}

int main()
{
	HANDLE ThreadHandler;
	
	ThreadHandler = CreateThread(NULL,0,&ThreadProc,0,0,NULL);
	GetExitCodeThread(ThreadHandler,&exitcode);
	WaitForSingleObject(ThreadHandler,5);
	cout << "Exit Code of Thread is " <<exitcode << endl;
	int n;
	getchar();
	return 0;
}