#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{
	BOOL processid;
	processid = CreateProcess(TEXT("calc.exe"),NULL,NULL,FALSE,NORMAL_PRIORITY_CLASS,NULL,NULL);
}