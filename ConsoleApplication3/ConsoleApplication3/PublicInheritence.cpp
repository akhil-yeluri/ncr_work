using namespace std;
#include<iostream>

class Base
{
	int privateVariable = 5;

protected:	
	int protectedVariable = 10;

public:
	int publicVariable = 15;
};


//class DerivedPublic inherits protectedVariable and publicVariable which become public in DerivedPublic
class DerivedPublic :public Base
{
public:
	void display()
	{
		cout << protectedVariable << publicVariable;
	}
};

int main()
{
	DerivedPublic derivedpublic;
	derivedpublic.display();
	int n;
	cin >> n;
	return 0;
}