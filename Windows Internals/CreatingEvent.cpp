using namespace std;
#include<Windows.h>
#include<iostream>
int main()
{
	HANDLE EventHandler;
	EventHandler = CreateEventA(NULL,FALSE,TRUE,"Custom event");
	if (NULL == EventHandler)
		cout << "EVENT NOT CREATED";
	else
		cout << "EVENT CREATED SUCCESSFULLY";
	CloseHandle(EventHandler);
	int n;
	cin >> n;
	return 0;
}