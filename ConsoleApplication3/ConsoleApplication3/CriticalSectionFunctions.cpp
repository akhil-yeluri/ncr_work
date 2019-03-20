using namespace std;
#include<Windows.h>
#include<iostream>
#define limit 100

long GlobalIncrementVariable;
int traversal;

CRITICAL_SECTION cs,cs2;

DWORD WINAPI Function1(LPVOID lpparameter)
{
	EnterCriticalSection(&cs);
	GlobalIncrementVariable++;
	LeaveCriticalSection(&cs);
	return 0;
}

DWORD WINAPI Function2(LPVOID LAP)
{
	EnterCriticalSection(&cs2);
	cout << "HEllo world"<<endl;
	LeaveCriticalSection(&cs2);
	return 0;
}

int main()
{
	HANDLE ThreadHandler[limit];
	InitializeCriticalSection(&cs2);
	InitializeCriticalSectionAndSpinCount(&cs,100);
	while ((traversal++)<=limit) {
		GlobalIncrementVariable = 0;
		ThreadHandler[0] = CreateThread(NULL, 0, &Function1, 0, 0, NULL);
		ThreadHandler[1]=CreateThread(NULL, 0, &Function2, 0, 0, NULL);
		WaitForMultipleObjects(2,ThreadHandler,1,INFINITE);
		cout << "Value of variable:" << GlobalIncrementVariable<<endl;
		if (GlobalIncrementVariable ==0)
		{
			cout << "Threads are Inconsistent\n";
			getchar();
		}
	}

	cout << "Shared Integer Among Threads is Consistent\n";
	getchar();
	return 0;
}