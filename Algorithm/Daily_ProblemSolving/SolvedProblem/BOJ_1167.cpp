#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans=0;
vector<vector<pair<int,int>>> tree(100000);

int diameter(int n, int parent)
{
	if(tree[n].size() == 1 && tree[n][0].first == parent)
		return 0;
	
	vector<int> inner_max;
	
	for(int i=0; i<tree[n].size(); ++i)
		if(tree[n][i].first != parent)
			inner_max.push_back(tree[n][i].second + diameter(tree[n][i].first, n));
	
	sort(inner_max.begin(), inner_max.end());
	
	if(tree[n].size()>1)
		ans = max(ans, inner_max[inner_max.size()-2]+inner_max[inner_max.size()-1]);
	
	return inner_max[inner_max.size()-1];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int s, e, weight;
	
	cin>>n;
	
	while(n--)
	{
		cin>>s;
		while(cin>>e && e!=-1)
		{
			cin>>weight;
			tree[s].push_back(make_pair(e,weight));
		}
	}
	
	ans = max(diameter(1,0), ans);
	
	cout<<ans<<'\n';
}
