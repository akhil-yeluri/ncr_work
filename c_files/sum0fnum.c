#include<stdio.h>
void main()
{
int n;
scanf("%d",&n);
int sum=0,rem;
while(n>0){
rem=n%10;
sum=sum+rem;
n/=10;
}
printf("%d",sum);
}