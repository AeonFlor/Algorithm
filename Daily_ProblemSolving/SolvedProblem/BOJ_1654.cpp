#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll K, N, ans, total=0;
int arr[10001];

ll bs_length(ll s, ll e)
{
	if(s > e)
		return 0;
	
	ll mid = (s+e)/2;
	ll cnt = 0;
	
	for(int i=0; i<K; ++i)
		cnt += arr[i]/mid;
	
	if(cnt < N)
		return bs_length(s, mid-1);
	
	else
	{
		ans = mid;
		return bs_length(mid+1, e);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>K>>N;
	
	for(int i=0; i<K; ++i)
	{
		cin>>arr[i];
		total+=arr[i];
	}
	
	bs_length(1ll, total/N);
	
	cout<<ans<<'\n';
	
	return 0;
}
