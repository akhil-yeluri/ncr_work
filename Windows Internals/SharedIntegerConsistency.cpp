using namespace std;
#include<Windows.h>
#include<iostream>
#define limit 1
int GlobalIncrementVariable;
DWORD WINAPI Function1(LPVOID lpparameter)
{
	GlobalIncrementVariable++;
	//cout << "Value from Thread 1:"<<GlobalIncrementVariable <<"\n";
	return 0;
}

DWORD WINAPI Function2(LPVOID lpparameter)
{
	return GlobalIncrementVariable++;
	//cout << "Value from Thread 2:" << GlobalIncrementVariable <<endl;
	return 0;
}

int main()
{
	HANDLE ThreadHandler[limit];
	while (1) {
		GlobalIncrementVariable = 0;
		ThreadHandler[0] = CreateThread(NULL, 0, &Function1, 0, 0, NULL);
		ThreadHandler[1]=CreateThread(NULL, 0, &Function2, 0, 0, NULL);
		WaitForMultipleObjects(2,ThreadHandler,1,INFINITE);
		cout << "Value of variable:" << GlobalIncrementVariable<<endl;
		if (GlobalIncrementVariable != 2)
		{
			cout << "Threads are Inconsistent\n";
			break;
		}
	}
	getchar();
	return 0;
}