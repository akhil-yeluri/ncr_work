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
	SECURITY_ATTRIBUTES SecurityAttributes;
	SecurityAttributes.bInheritHandle = TRUE;
	SecurityAttributes.lpSecurityDescriptor = NULL;
	SecurityAttributes.nLength = 0;
	HANDLE EventCreator = CreateEvent(&SecurityAttributes,FALSE,TRUE,TEXT("EVENT 1"));
	if (NULL != EventCreator)
		cout << "EVENT CREATED";
	ZeroMemory(&startupinfo, sizeof(startupinfo));
	ZeroMemory(&processinfo, sizeof(processinfo));
	processid = CreateProcess(NULL, argv[1],&SecurityAttributes,NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &startupinfo, &processinfo);
	cin >> n;
	return 0;
}