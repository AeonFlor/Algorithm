#include <iostream>

using namespace std;

int main(void)
{
 	int ans[1001]={1,2,};
	int n;
	
	cin>>n;
	
	for(int i=2; i<n; ++i)
		ans[i] = (ans[i-1] + ans[i-2])%10007;
	
	cout<<ans[n-1]<<'\n';
}
