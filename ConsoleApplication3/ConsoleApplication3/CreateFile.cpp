#include<iostream>
#include<Windows.h>
#include<tchar.h>
#include<string>
#include<string.h>
#define size 100
using namespace std;

int main()
{
	HANDLE UriFileHandler;
	UriFileHandler = CreateFileA("uri.txt",GENERIC_READ|GENERIC_WRITE,0,NULL,3,FILE_ATTRIBUTE_NORMAL,NULL);
	CHAR *buffer = new CHAR[size];
	ZeroMemory(buffer,size);
	BOOL ReadFileUri;
	LPDWORD bufferSize=0;

	//read file
	ReadFileUri = ReadFile(UriFileHandler,buffer,size+1,bufferSize,NULL);
	_tprintf(_T("%S\n"),buffer);
	ZeroMemory(buffer, size);

	//USER INPUT FOR WRITE
	cout << "Enter the content to be written to the file\n";
	string input;
	getline(cin, input);
	int input_index = 0;

	while (input_index < input.length() && input_index < size) {
		buffer[input_index] = input[input_index];
		input_index++;
	}

	//WRITE FILE
	BOOL WriteFileUri = WriteFile(UriFileHandler,buffer,input.length()+1,NULL,NULL);
	cout << "FILE AFTER EDITS \n";

	//READ FILE
	CHAR *buffer2 = new CHAR[size];
	ZeroMemory(buffer2, size);
	bufferSize = 0;
	BOOL ReadFileUri2 = ReadFile(UriFileHandler, buffer2, size,bufferSize, NULL);
	_tprintf(_T("%S\n"), buffer2);
	int n;
	cin >> n;
	return 0;

}