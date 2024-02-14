#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, unit;
int cache[101][10001];
vector<int> coin;

bool DESC(int a, int b)
{
	return a > b;
}

int count(int iter, int remain)
{
	int ans = 10001;
	
	int& res = cache[iter][remain];
	
	if(remain == 0)
		return 0;
	
	if(res != -1)
		return res;
	
	for(int i=iter; i< coin.size(); ++i)
		if(coin[i] <= remain)
			ans = min(ans, 1 + count(i, remain - coin[i]));
	
	return res = ans;
}

int main(void)
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int ans;
	
	fill(&cache[0][0], &cache[100][10000], -1);
	
	cin>>n>>k;
	
	while(n--)
	{
		cin>>unit;
		if(unit <= k)
			coin.push_back(unit);
	}
	
	sort(coin.begin(), coin.end(), DESC);
	coin.erase(unique(coin.begin(), coin.end()), coin.end());
	  
	ans = count(0,k);
	
	if(ans > 10000)
		cout<<"-1\n";
	
	else
		cout<<ans<<'\n';
}
