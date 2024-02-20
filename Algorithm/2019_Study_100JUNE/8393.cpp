#include <iostream>

using namespace std;

int main(void)
{
	int n,res=0;

	cin>>n;

	for(int i=1;i<=n;i++)
	{
		res+=i;
	}

	cout<<res<<endl;

	return 0;
}