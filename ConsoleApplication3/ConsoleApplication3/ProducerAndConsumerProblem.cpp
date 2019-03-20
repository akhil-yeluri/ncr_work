#include<windows.h>
#include<iostream>
#include<queue>
#define length 5
using namespace std;

CONDITION_VARIABLE QUEUE_EMPTY, QUEUE_FULL;
SRWLOCK readlock, writelock;
int write_value;
queue<int> Queue;

DWORD WINAPI Read(LPVOID lparameter)
{
	AcquireSRWLockExclusive(&readlock);
	if (Queue.size() == 0)
	   {
		SleepConditionVariableSRW(&QUEUE_EMPTY, &readlock, INFINITE,0);
		WakeConditionVariable(&QUEUE_FULL);
	   }
	else
	{
		int pop_value = Queue.front();
		Queue.pop();
		cout << (char *)lparameter<<" consumes "<<pop_value<<endl;
		WakeConditionVariable(&QUEUE_FULL);
	}
		ReleaseSRWLockExclusive(&readlock);
	return 0;
}

DWORD WINAPI Write(LPVOID lparameter)
{
	AcquireSRWLockExclusive(&writelock);
	if (Queue.size() == length)
	{
		SleepConditionVariableSRW(&QUEUE_FULL,&writelock,INFINITE,0);
		WakeAllConditionVariable(&QUEUE_EMPTY);
	}

	else
	{
		Queue.push(++write_value);
		
		cout << (char *)lparameter<<" produces"<<write_value<<endl;
		WakeAllConditionVariable(&QUEUE_EMPTY);
	}
	ReleaseSRWLockExclusive(&writelock);
	return 0;
}

int main()
{
	
	InitializeConditionVariable(&QUEUE_EMPTY);
	InitializeConditionVariable(&QUEUE_FULL);
	InitializeSRWLock(&readlock);
	InitializeSRWLock(&writelock);
	HANDLE Thread[length];
	while (1) 
	{

		Thread[0]= CreateThread(NULL,0,Read,(LPVOID)"reader",0,NULL);//reader thread
		Thread[1]= CreateThread(NULL, 0,Read,(LPVOID)"reader", 0, NULL);//reader thread
		Thread[2]= CreateThread(NULL, 0,Write,(LPVOID)"writer", 0, NULL);//writer thread
		Thread[3] = CreateThread(NULL, 0, Write,(LPVOID)"writer", 0, NULL);//writer thread
		Thread[4] = CreateThread(NULL, 0, Write, (LPVOID)"writer", 0, NULL);//writer thread
		WaitForMultipleObjects(5, Thread, TRUE, INFINITE);
	}
	for (int i = 0; i < length; i++)
	   CloseHandle(Thread[i]);
	getchar();
	return 0;
}