#include<iostream>
#include<Windows.h>
#include<tchar.h>
using namespace std;
int _tmain(int argc,WCHAR * argv[],WCHAR * env[])
{
	int n;
	BOOL processid;
	STARTUPINFO  startupinfo;
	PROCESS_INFORMATION processinfo;
	ZeroMemory(&startupinfo,sizeof(startupinfo));
	ZeroMemory(&processinfo, sizeof(processinfo));
	startupinfo.cb = sizeof(startupinfo);
	processid = CreateProcess(NULL, argv[1], NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &startupinfo, &processinfo);
	cout << "ProcessId:" << processinfo.dwProcessId << endl;
    cout << "Handle:" << processinfo.hProcess << endl;
	cout << "Current Process ID:" << GetCurrentProcessId() << endl;
	cout << "Current Thread ID:" << GetCurrentThreadId() << endl;
	cout << "ProcessID:" << GetProcessId() << endl;
	cout << "Thread ID:" << GetThreadId()<<endl;
	cout << "Process ID of Thread" << GetProcessIdOfThread()<<endl;
	cin >> n;
	return 0;
}