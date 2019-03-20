using namespace std;
#include<iostream>
#include<string>

#include<stack>

int main()
{
	string s;
	int unbalanced = -1;
	getline(cin, s);
	stack <char> st;
	int i = 0;

	char ch;

	while (s[i] != '\0')
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			st.push(s[i]);
		if (s[i] == '}' || s[i] == ']' || s[i] == ')')
		{
			if (st.empty())
			{
				unbalanced = 0;
				break;
			}
			else
			{
				if (s[i] == '}' && st.top() == '{' || s[i] == ')' && st.top() == '(' || s[i] == ']' && st.top() == '[')
					st.pop();

				else
				{
					unbalanced = 0;
					break;
				}
			}
		}
		i++;
	}
	if (unbalanced == 0) {
		cout << "Unbalanced";
		return 1;
	}
	if (st.empty() && unbalanced == -1)
	{
		cout << "balanced";
		return 0;
	}

	cout << "Unbalanced";
	return 0;
}