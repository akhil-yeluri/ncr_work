using namespace std;
#include<iostream>
#include<string>
#include<stack>

int main()
{
	stack<int> stck;
	string s;
	cout << "enter the postfix expression\n";
	getline(cin,s);
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			int a = stck.top();
			stck.pop();
			int b = stck.top();
			stck.pop();
			switch (s[i]) {
			case '+': stck.push(a + b);
				break;
			case '-': stck.push(b - a);
				break;
			case '*': stck.push(a * b);
				break;
			case '/': stck.push(b / a);
				break;
			}
		}

		else
			stck.push((int)s[i]-'0');
		i++;
	}
	cout << stck.top();
	cin >> i;
	return 0;

}