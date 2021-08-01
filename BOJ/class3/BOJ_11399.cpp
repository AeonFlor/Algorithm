#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, ans;
	cin>>N;
	vector<int> P(N);
	
	for(int i=0; i<N; ++i)
		cin>>P[i];
	
	sort(P.begin(), P.end());
	
	ans = P[0];
	
	for(int i=1; i<N; ++i)
	{
		P[i]+=P[i-1];
		ans += P[i];
	}
	
	cout<<ans<<'\n';
}
