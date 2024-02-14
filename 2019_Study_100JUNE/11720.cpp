#include <iostream>

using namespace std;

int main(void)
{
	int n, res=0;

	cin>>n;

	int *arr = new int[n];

	for(int i=0; i<n; i++)
	{
		scanf("%1d",&arr[i]);
		res+=arr[i];
	}

	cout<<res<<endl;

	return 0;
}