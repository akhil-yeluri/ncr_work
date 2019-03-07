using namespace std;
#include<iostream>
#include<string>
#include<string.h>
int print(char a,char b)
{
	if (a > b)
	{
		cout << "Invalid expression";
		return 0;
	}
	while (a <= b) {
		cout << a;
		a++;
	}
	return 1;
}

int main()
{
	string input;
	cout << "enter an expression\n";
	getline(cin, input);
	int length = input.length();

	if (input[0] == '-' || input[length - 1] == '-')
	{
		cout <<"Invalid Expression\nPress any key to exit";
		getchar();
		return 0;
	}

	for(int i=2;i<length;i++)
		if(input[i]=='-' && (input[i-2]=='-' || input[i-1]=='-'))
		{
			cout << "Invalid Expression\nPress any key to exit";
			getchar();
			return 0;
		}
	

	for (int i = 0; i<length-1; i++)
		if (input[i] == '-' && input[i + 1] != '\0')
		{
			if(!print(input[i - 1], input[i+ 1]))
				return 0;
			
			i++;
		}
		else
		{
			if (input[i] != '-' && input[i+1]!='-')
				cout << input[i];
		}

	int n;
	cin >> n;
	return 0;
}