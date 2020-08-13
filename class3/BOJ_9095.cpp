#include <iostream>

using namespace std;

int main(void)
{
	int ans[11], T, n;
	ans[0] = ans[1] = 1;
	ans[2] = 2;
	ans[3] = 4;
	
	for(int i=4; i<11; ++i)
		ans[i] = ans[i-1]*2-ans[i-4];
	
	cin>>T;
	
	for(int i=0; i<T; ++i)
	{
		cin>>n;
		cout<<ans[n]<<'\n';
	}
}
