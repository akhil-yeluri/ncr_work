using namespace std;
#include<iostream>
#include<string>
void print(char a,char b)
{
	
	while (a <= b) {
		cout << a;
		a++;
	}
}

int main()
{
	string input;
	cout << "enter an expression\n";
	getline(cin, input);
	int length = 0;
	while (input[length] != '\0')
		length++;
	cout << length;
	for (int i = 0; i<length; i++)
		if (input[i] == '-' && input[i + 1] != '\0')
		{
			print(input[i - 1], input[i+ 1]);
			i++;
		}
		else
		{
			if (input[i] != '-' )
				cout << input[i];
		}

	int n;
	cin >> n;
	return 0;
}