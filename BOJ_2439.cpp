#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=n; j>i; --j)
			cout<<" ";
		
		for(int k=0; k<i; ++k)
			cout<<"*";
		
		cout<<'\n';
	}
	
	return 0;
}
