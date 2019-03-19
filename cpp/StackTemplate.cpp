using namespace std;
#include<iostream>
template<class T>
class Stack
{

	int top ,size;
	T * stack;

public:
	  Stack()
	  {
		  top = -1;
		  size = 0;
	  }

	  void setSize(int inputSize)
	  {
		  size = inputSize;
		  stack = new T[size];
	  }

	void push(T element)
	{
		if (top == size - 1)
		{
			cout << "stack is full cannot insert\n";
		}

		else
		{
			stack[++top] = element;
			cout << "Element pushed into the stack\n";
		}
	}

	void pop()
	{
		if (top == -1)
			cout << "Stack is empty cant Pop\n";
		else
		{
			cout << "Element popped out from stack is:"<<stack[top]<<endl;
			top--;
		}
	}


	
};



class complex
{
	int real, imaginary;
public:
	complex()
	{
		real = imaginary = 0;
	}

	complex(int realIp,int imaginaryIp)
	{
		real = realIp;
		imaginary = imaginaryIp;
	}

	friend ostream & operator << (ostream &out, complex &object);
};

ostream & operator << (ostream &out, complex &object)
{
	cout << "real value is "<<object.real <<"Imaginary value is "<<object.imaginary<<endl;
	return out;
}

int main()
{
	int choice;
	cout << "Choose the stack type\n1.INTEGER\n2.FLOAT\n3.DOUBLE\n4.CHARACTER\n5.Complex Class\n";
	cin >> choice;
 
	if (choice == 1)
	{
		int stackSize;
		cout << "Enter size of stack\n";
		cin >> stackSize;
		Stack<int> integerStack;
		integerStack.setSize(stackSize);
		while (1)
		{

			cout << "Enter your choice\n1.push into stack\n2.pop from stack\n";
			cin >> choice;
			switch (choice)
			{
			case 1: int elementToPush;
				cout << "Enter element to push\n";
				cin >> elementToPush;
				integerStack.push(elementToPush);
				break;


			case 2:integerStack.pop();
				break;

			default:cout << "Invalid Option\n";
				break;
			}
		}
	}

	if (choice == 2)
	{
		int stackSize;
		cout << "Enter size of stack\n";
		cin >> stackSize;
		Stack<float> floatStack;
		floatStack.setSize(stackSize);
		while (1)
		{

			cout << "Enter your choice\n1.push into stack\n2.pop from stack\n";
			cin >> choice;
			switch (choice)
			{
			case 1: float elementToPush;
				cout << "Enter element to push\n";
				cin >> elementToPush;
				floatStack.push(elementToPush);
				break;


			case 2:floatStack.pop();
				break;

			default:cout << "Invalid Option";
				break;
			}
		}
	}

	if (choice == 3)
	{
		int stackSize;
		cout << "Enter size of stack\n";
		cin >> stackSize;
		Stack<float> DoubleStack;
		DoubleStack.setSize(stackSize);
		while (1)
		{

			cout << "Enter your choice\n1.push into stack\n2.pop from stack\n";
			cin >> choice;
			switch (choice)
			{
			case 1: double elementToPush;
				cout << "Enter element to push\n";
				cin >> elementToPush;
				DoubleStack.push(elementToPush);
				break;


			case 2:DoubleStack.pop();
				break;

			default:cout << "Invalid Option";
				break;
			}
		}
	}

	if (choice == 4)
	{
		int stackSize;
		cout << "Enter size of stack\n";
		cin >> stackSize;
		Stack<char> characterStack;
		characterStack.setSize(stackSize);
		while (1)
		{

			cout << "Enter your choice\n1.push into stack\n2.pop from stack\n";
			cin >> choice;
			switch (choice)
			{
			case 1: char elementToPush;
				cout << "Enter element to push\n";
				cin >> elementToPush;
				characterStack.push(elementToPush);
				break;


			case 2:characterStack.pop();
				break;

			default:cout << "Invalid Option";
				break;
			}
		}
	}

	if (choice == 5)
	{
		int stackSize;
		cout << "Enter size of stack\n";
		cin >> stackSize;
		Stack<complex> ComplexStack;
		ComplexStack.setSize(stackSize);
		while (1)
		{
			cout << "Enter your choice\n1.push into stack\n2.pop from stack\n";
			cin >> choice;
			if (choice == 1) 
			{
				int real, imaginary;
				cout << "enter real and imaginary\n";
				cin >> real >> imaginary;
				complex c(real, imaginary);
				ComplexStack.push(c);
			}

			if(choice==2)
				ComplexStack.pop();
		

			
			
			
		}
	}
	else
		cout << "Invalid Option selected";
		    
	
	




	
	return 0;
}