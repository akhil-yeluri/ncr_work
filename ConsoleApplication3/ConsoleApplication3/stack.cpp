#include<iostream>
using namespace std;
struct _stack
{
	int size;
	int *s;
	int top;
};

class Stack
{
	_stack stack;

public:
	Stack()
	{
		stack.size = 0;
		stack.s = NULL;
		stack.top = -1;
	}

	void setSize(int n)
	{
		stack.s = new int[n];
		stack.top = -1;
		stack.size = n;
	}

	bool isEmpty()
	{
		return (stack.top == -1);
	}

	bool isFull()
	{
		return (stack.top == stack.size - 1);
	}

	void push(int n)
	{
		if (!isFull())
			stack.s[++stack.top] = n;
		else
			cout << "Stack is full\n";
	}

	int pop()
	{
		int error_code = 404;
		if (!isEmpty())
			return stack.s[stack.top--];
		return error_code;
	}

	int peek()
	{
		int error_code = 404;
		if (!isEmpty())
			error_code= stack.s[stack.top--];
		return error_code;
	}

	void display()
	{
		for (int i = 0; i <= stack.top; i++)
			cout << stack.s[i]<<" ";
	}
};

int main()
{
	Stack object;
	int temp;
	cout << "Enter size of Stack\n";
	int n;
	cin >> n;
	object.setSize(n);
	while (true) {
	cout << "Enter your choice\n 1.Insert \n 2.Delete 3.Display\n 4.peek\n";
	cin >> n;
		switch (n) {
		case 1:cout << "Enter element to push\n";
			cin >> temp;
			object.push(temp);
			break;

		case 2:
			temp = object.pop();
			if (temp == 404)
				cout << "stack is empty\n";
			else
				cout << temp;
			break;

		case 3:object.display();
			break;
		case 4:temp = object.peek();
			if (temp == 404)
				cout << "stack is empty\n";
			else
				cout << temp <<" ";
			break;

		default:return 0;

		}

	}

	return 0;
}