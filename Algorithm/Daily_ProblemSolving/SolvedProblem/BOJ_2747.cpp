#include <iostream>

using namespace std;

int cache[46]={0,};
// Not initialized to negative.

int fibo(int n)
{
	if(n<2) return cache[n];
	if(cache[n] != 0) return cache[n];
	return cache[n]=fibo(n-2)+fibo(n-1);
}

int main(void)
{
	int input;
	
	cache[1]=1;
	cache[2]=1;
	
	scanf("%d",&input);
	
	printf("%d", fibo(input));
	
	return 0;
}
