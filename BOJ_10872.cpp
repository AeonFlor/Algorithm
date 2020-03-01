#include <iostream>

using namespace std;

int facto(int n)
{
	if(n==0)
		return 1;
	return n*facto(n-1);
}

int main(void)
{
	int N;
	scanf("%d",&N);
	printf("%d",facto(N));
}
