using namespace std;
#include<Windows.h>
#include<iostream>
#define limit 100

long GlobalIncrementVariable;
int traversal;



DWORD WINAPI Function1(LPVOID lpparameter)
{

	Sleep(109);
	cout << "Hello World\n";
	return 0;
}



int main()
{
	HANDLE ThreadHandler;
	
		GlobalIncrementVariable = 0;
		DWORD waitForSingleObjectReturnValue;
		ThreadHandler = CreateThread(NULL, 0, &Function1, 0, 0, NULL);
		waitForSingleObjectReturnValue = WaitForSingleObject( ThreadHandler,5);
		switch(waitForSingleObjectReturnValue)
		{
		case WAIT_ABANDONED:cout << "WAIT ABANDONED";
			                break;
		case WAIT_OBJECT_0:cout << "The state of specified object is signaled";
			               break;
		case WAIT_TIMEOUT:cout << "The wait timed out and specified object is not signaled";
			              break;
		case WAIT_FAILED:cout << "The wait function failed";
			             break;

		default:break;
		}

	getchar();
	return 0;
}