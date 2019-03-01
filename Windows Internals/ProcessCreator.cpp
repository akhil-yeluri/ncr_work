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
	//WCHAR var[10] = "calc.exe";
	cout << "Enter your choice\n1.Calculator\n2.Notepad";
	cin >> n;
	switch (n)
	{
	case 1:	processid = CreateProcess(NULL, argv[1], NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &startupinfo, &processinfo);
		    cout << "ProcessId:" << processinfo.dwProcessId << endl;
		    cout << "Handle:" << processinfo.hProcess << endl;
		    break;

	case 2:	processid = CreateProcess(NULL, argv[2], NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &startupinfo, &processinfo);
		    cout <<"ProcessId:"<<processinfo.dwProcessId << endl;
			cout << "Handle:" << processinfo.hProcess << endl;
		    break;
	default:return 0;
	}
	//cout << processid<<endl<<GetLastError();
	cin >> n;
	return 0;
}