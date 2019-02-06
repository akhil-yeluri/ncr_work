#include<stdio.h>
int main() 
{
	int n,i=1,sum=0;
	scanf_s("%d",&n);
	int temp = n;
	while (n > 0) 
	{
		sum = sum*i + n % 10;
		n /= 10;
		i *= 10;
	
	}
	if (temp == sum)
		printf("%d is a palindrome",temp);
	else
		printf("%d is not a palindrome", temp);
	
	getch();
	return 0;
}