#include <iostream>

using namespace std;

int dec(int x)
{
	int dif;

	dif = x/10%10-x%10;

	while(x)
	{
		if( dif != x/10%10-x%10 && x/10!=0 )
			return 0;
		x/=10;
	}

	return 1;
}

int main(void)
{
	int n,cnt=0;
	
	cin>>n;

	for(int i = 1; i<=n; i++)
	{
		cnt += dec(i);
	}

	cout<<cnt<<endl;

	return 0;
}