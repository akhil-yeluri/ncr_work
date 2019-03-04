using namespace std;
#include<Windows.h>
#include<iostream>
#define limit 100

long GlobalIncrementVariable;
int traversal;
DWORD WINAPI Function1(LPVOID lpparameter)
{

	return InterlockedIncrement(&GlobalIncrementVariable);
}

DWORD WINAPI Function2(LPVOID lpparameter)
{
	return InterlockedIncrement(&GlobalIncrementVariable);
}

int main()
{
	HANDLE ThreadHandler[limit];
	while ((traversal++)<=limit) {
		GlobalIncrementVariable = 0;
		ThreadHandler[0] = CreateThread(NULL, 0, &Function1, 0, 0, NULL);
		ThreadHandler[1]=CreateThread(NULL, 0, &Function2, 0, 0, NULL);
		WaitForMultipleObjects(2,ThreadHandler,1,INFINITE);
		cout << "Value of variable:" << GlobalIncrementVariable<<endl;
		if (GlobalIncrementVariable != 2)
		{
			cout << "Threads are Inconsistent\n";
			return 0;
		}
	}

	cout << "Shared Integer Among Threads is Consistent\n";
	getchar();
	return 0;
}