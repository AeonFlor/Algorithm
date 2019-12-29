#include <iostream>

using namespace std;

int main(void)
{
	int a,b,c;
	int arr[10]={0,};
	
	scanf("%d %d %d",&a,&b,&c);
	
	a= a*b*c;
	
	while(a)
	{
		arr[a%10]++;
		a/=10;
	}
	
	for(int i=0; i<10; ++i)
		printf("%d\n",arr[i]);
	
}
