#include <iostream>
#include <algorithm>

using namespace std;

int cache[1000];

int dp(int n)
{
	int& res = cache[n];
	
	if(n<3)
		return n;
	
	if(res!=-1)
		return res;
	
	return res = (dp(n-1) + dp(n-2))%10007;
}


int main(void)
{
	fill(cache, cache+1001,-1);
	
	int n;
	
	cin>>n;
	
	cout<<dp(n)<<'\n';
}
