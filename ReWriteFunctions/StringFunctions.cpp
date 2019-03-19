#include<iostream>
#include<stdio.h>
#include<string>
#define size 5000
//#include<pch.h>
#include<string.h>
using namespace std;
int input;

int strcmp(string s1,string s2)
{

	int length = 0;
	while (length < s1.length() && length < s2.length())
	{
		if (s1[length] < s2[length])
			return -1;
		else
			if (s1[length] > s2[length])
				return 1;
			else
				length++;
	}
	if (s1.length() != s2.length())
		return 1;
	return 0;
}

string strcpy(string s1,string s2)
{
		s2 = s1;
		return s2;
}

char* strcat(char *s1,char* s2)
{
	int i = 0;
	for (i = 0; s1[i] != '\0'; i++)
		continue;
	for (int j = 0; s2[j] != '\0'; j++)
		s1[i++] = s2[j];
	s1[i] = '\0';
	realloc(s1, strlen(s1) + strlen(s2));
	return s1;
}

string strrev(string s)
{
	int length = s.length()-1;
	int i = 0;
	while (i <= s.length()/2-1)
	{
		char c = s[i];
		s[i] = s[length];
		s[length] = c;
		i++;
		length--;
	}
	return s;
}

int main()
{

	while (1) {
		cout << "Enter your choice\n1.check string equality\n2.Reverse a String\n3.String Copy\n4.String Concatenate\n";
		cin >> input;
		if (input == 1)
		{
			string s1, s2;
			cout << "Enter 1st string\n";
			cin.ignore();
			getline(cin, s1);
			cout << "Enter 2nd string\n";
			getline(cin, s2);
			if (!strcmp(s1, s2))
				cout << "Given Strings are equal\n";
			else
				cout << "Unequal strings\n";
			cout << "\n";
			continue;
		}

		if (input == 2)
		{
			string s;
			cout << "enter string that needs to be reversed\n";
			cin.ignore();
			getline(cin, s);
			cout << "String after reverse is :" << strrev(s) << endl;
			cout << "\n";
			continue;
		}
		if (input == 3)
		{
			string s1, s2;
			cout << "Enter 1st string\n";
			cin.ignore();
			getline(cin, s1);
			cout << "Enter 2nd string\n";
			getline(cin, s2);
			cout << "Copying String 1 to String 2\nString 2 after Copying:" << strcpy(s1, s2) << "\n";
			cout << "\n";
			continue;
		}

		if (input == 4)
		{
			char *s1 = new char[size];
			char *s2 = new char[size];
			cout << "Enter 1st string\n";
			cin >> s1;
			cout << "Enter 2nd string\n";
			cin >> s2;
			cout << "String after concatenation is:";
			strcat(s1, s2);
			int i = 0;
			while (s1[i] != '\0')
				cout << s1[i++];
			cout << "\n";
			delete s1, s2;
			continue;
		}

		else
		{
			cout << "Invalid Option\nPress any key to Exit\n";
			getchar();
			return 0;
		}
	}
   return 0;
}
