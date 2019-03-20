#include<Windows.h>
#include<iostream>
#define max_count 4
#define size 20
using namespace std;

int main()
{
	HANDLE Semaphore;
	Semaphore = CreateSemaphore(NULL,0,max_count,TEXT("SEMAPHORE"));
	if (Semaphore = NULL)
		cout << "Semaphore creation error " << GetLastError();
	HANDLE THREAD[size];
	return 0;
}