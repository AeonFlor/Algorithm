#include <iostream>

using namespace std;

int fibo(int n)
{
	if(n==0) return 0;
	if(n==1 || n==2) return 1;
	
	return fibo(n-2)+fibo(n-1);
}

int main(void)
{
	int input;
	
	scanf("%d",&input);
	
	printf("%d", fibo(input));
	
	return 0;
}
