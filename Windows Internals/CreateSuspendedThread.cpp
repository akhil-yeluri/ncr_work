using namespace std;
#include<Windows.h>
#include<iostream>
#define limit 1000
DWORD WINAPI ThreadProc(LPVOID lpparameter)
{
	for (int i = 0; i <=limit; i++)
	{
		Sleep(5);
		cout << i << endl;
	}
	return 0;
}

int main()
{
	HANDLE ThreadHandler;
	ThreadHandler = CreateThread(NULL,0,&ThreadProc,0,CREATE_SUSPENDED,NULL);
	cout << "Waitning time is 5 seconds for secondary thread\n";
	Sleep(5000);
	ResumeThread(ThreadHandler);
	int n;
	cin >> n;
	return 0;
}