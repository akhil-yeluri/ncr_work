using namespace std;
#include<Windows.h>
#include<iostream>
#define limit 1

long GlobalIncrementVariable;
int traversal;
DWORD WINAPI Function1(LPVOID lpparameter)
{
	Sleep(4000);
	cout << "HELLO 1";
	return InterlockedIncrement(&GlobalIncrementVariable);
}

DWORD WINAPI Function2(LPVOID lpparameter)
{
	Sleep(3000);
	cout << "HELLO 2";
	return InterlockedIncrement(&GlobalIncrementVariable);
}

int main()
{
	HANDLE ThreadHandler[limit];
	DWORD waitForMultipleObjectsReturnValue;
	
		GlobalIncrementVariable = 0;
		ThreadHandler[0] = CreateThread(NULL, 0, &Function1, 0, 0, NULL);
		ThreadHandler[1] = CreateThread(NULL, 0, &Function2, 0, 0, NULL);
		waitForMultipleObjectsReturnValue=WaitForMultipleObjects(2, ThreadHandler,FALSE,2000);
		switch (waitForMultipleObjectsReturnValue)
		{
		case WAIT_OBJECT_0:cout << "All Specified Objects are signalled";
			break;

		case WAIT_ABANDONED_0:cout << "Atleast one specified object is abandoned";
			break;
		case WAIT_TIMEOUT:cout << "Wait timed out and the specified objects are not signalled";
			break;
		case WAIT_FAILED:cout << "Wait function failed";
			break;
		default:break;
		}
	
	getchar();
	return 0;
}