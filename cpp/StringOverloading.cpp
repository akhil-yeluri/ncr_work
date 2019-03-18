using namespace std;
#include<iostream>
class String
{
	char *s;
	int length;
public:
	String()
	{
		s = NULL;
		length = 0;
	}

	String(char *str,int size)
	{
		length = size;
		s = new char[length*sizeof(char)];
		for (int i = 0; i < size; i++)
			s[i] = str[i];
	}

	String operator + (String &object)
	{
		String res;
		int i;
		res.length = length + object.length;
		res.s = new char[res.length];
		for (i = 0; i < strlen(s); i++)
			res.s[i] = s[i];
		for (int j=0; j <=strlen(object.s); j++)
			res.s[i++] = object.s[j];
		return res;

	}

	void operator = (String &object)
	{
		s = new char[object.length+1];
		strcpy_s(s,100,object.s);

	}

	char operator [] (int index)
	{
		return s[index];
	}

	void display()
	{
		cout << s;
	}
};

int main()
{
	String s("hello",6);
	String s2("world",6);
	String s3= s + s2;
	//cout << s2[3];
	s = s2;
	s.display();
	getchar();
	return 0;
}