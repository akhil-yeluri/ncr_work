using namespace std;
#include<string>
#include<stack>
#include<iostream>

int main()
{
	string s;
	cout << "enter a infix expression\n";
	getline(cin, s);
	string output;
	
	stack<char> stck;
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '+' && s[i] != '-' && s[i] != '/' && s[i] != '*' && s[i]!='(' && s[i]!=')') {
			output += s[i];
			i++;
			continue;
		}
		else
		{
			switch (s[i])
			{
			case '+': if (stck.empty() || stck.top() == '(')
				         stck.push(s[i]);
					  else
					  {
						  while (!stck.empty())
						  {
							  output += stck.top();
							  stck.pop();
						  }

						  stck.push('+');
					  }
					  break;
			case '-': if (stck.empty() || stck.top() == '(')
				stck.push(s[i]);
					  else
					  {
						  while (!stck.empty())
						  {
							  output += stck.top();
							  stck.pop();
						  }

						  stck.push('-');
					  }
					  break;

			case '*': if (stck.empty() || stck.top() == '(')
				stck.push(s[i]);
					  else
					  {
						  if (stck.top()= '/') 
						  {
							  output += stck.top();
							  stck.pop();
						 }

						  stck.push('*');
					  }
					  break;
			case '/': if (stck.empty() || stck.top()=='(')
				stck.push(s[i]);
					  else
					  {
						  if (stck.top()= '*')
						  {
							  output += stck.top();
							  stck.pop();
						  }

						  stck.push('/');
					  }
					  break;

			case '(':stck.push('(');
				     break;
			case ')': while (stck.top() != '(')
			             {
				output += stck.top();
				stck.pop();
			    }
					  stck.pop();
					  break;
			 
			}
		}


		i++;
	}
	while (!stck.empty()){
		output += stck.top();
		stck.pop();
	}
	cout << output;
	int n;
	cin >> n;
	return 0;
}