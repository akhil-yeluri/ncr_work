#include<iostream>
#include<Windows.h>
#include<tchar.h>
using namespace std;
int _tmain(int argc, WCHAR * argv[], WCHAR * env[])
{
	int n;
	BOOL processid;
	STARTUPINFO  startupinfo;
	PROCESS_INFORMATION processinfo;
	ZeroMemory(&startupinfo, sizeof(startupinfo));
	ZeroMemory(&processinfo, sizeof(processinfo));
	startupinfo.cb = sizeof(startupinfo);
	processid = CreateProcess(NULL, argv[1], NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &startupinfo, &processinfo);
	cout << "ProcessId:" << processinfo.dwProcessId << endl;
	cout << "Handle:" << processinfo.hProcess << endl;
	cout << "Current Process ID:" << GetCurrentProcessId() << endl;
	cout << "Current Thread ID:" << GetCurrentThreadId() << endl;
	cout << "ProcessID:" << GetProcessId(processinfo.hProcess) << endl;
	cout << "Thread ID:" << GetThreadId(processinfo.hThread) << endl;
	cout << "Process ID of Thread" << GetProcessIdOfThread(processinfo.hThread) << endl;
	cin >> n;
	return 0;
}