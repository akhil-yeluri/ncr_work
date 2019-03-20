#include<iostream>
using namespace std;

class Complex
{
	int x, y;
public:
	Complex()
	{
		x = 50;
		y = 100;
	}

	Complex(int x)
	{
		this->x = x;
		this->y = x;
	}

	int get()
	{
		return x;
	}


	Complex operator+(Complex &c2) {
		Complex temp;
		temp.x = this->x + c2.x;
		temp.y = this->y + c2.y;
		return temp;
	}
};


int main()
{
	Complex c(10),c1(c);
	int n;
	Complex c3;
	c3 = c + c1;
	cout << c3.get();
	cin >> n;
	return 0;
}