using namespace std;
#include<iostream>
#include<string>
#include<string.h>

//function for printing the expansion sequence
int print(char a,char b)
{
	//conditon: breaks where expansion interval is invalid
	if (a > b)
	{
		cout << "\nThe Sequence encountered a Invalid expression and stopped execution\nPress any key to exit";
		getchar();
		return 0;
	}
	//prints sequence if expansion interval is valid
	while (a <= b) {
		cout << a;
		a++;
	}
	return 1;
}

int main()
{
	string input;
	int i;
	cout << "enter an expression\n";
	getline(cin, input);
	int length = input.length();
	//condition for checking for valid expression at start and end of string
	if (input[0] == '-' || input[length - 1] == '-')
	{
		cout <<"Invalid Expression\nPress any key to exit";
		getchar();
		return 0;
	}

	//condition for checking for proper spacing of '-' operator
	for(i=2;i<length;i++)
		if(input[i]=='-' && (input[i-2]=='-' || input[i-1]=='-'))
		{
			cout << "Invalid Expression\nPress any key to exit";
			getchar();
			return 0;
		}
	

	for ( i = 0; i<length-1; i++)
		//function call if the expression is valid
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
	cout << input[i];

	int n;
	cin >> n;
	return 0;
}