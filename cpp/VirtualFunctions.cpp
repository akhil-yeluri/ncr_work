using namespace std;
#include<iostream>
class shape
{
public:
	virtual void display()
	{
		cout << "This is shape class";
	}
};

class Rectangle :public shape
{
public:
	void display()
	{
		cout << "This is Rectangle class";
	}
 };


class Triangle :public shape
{
public:
	void display()
	{
		cout << "This is Triangle class";
	}
};


class Square :public shape
{
public:
	void display()
	{
		cout << "This is Square class";
	}
};


int main()
{
	shape * object;
	Rectangle rectangle;
	Triangle triangle;
	Square square;
	object = &square;
	object->display();
	getchar();
	return 1;

}