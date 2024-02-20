#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans=0;
vector<vector<pair<int,int>>> tree(10000);

int diameter(int n)
{
	if(tree[n].empty())
		return 0;
	
	vector<int> inner_max;
	
	for(int i=0; i<tree[n].size(); ++i)
		inner_max.push_back(tree[n][i].second + diameter(tree[n][i].first));
	
	sort(inner_max.begin(), inner_max.end());
	
	if(tree[n].size()>1)
		ans = max(ans, inner_max[inner_max.size()-2]+inner_max[inner_max.size()-1]);
	
	return inner_max[inner_max.size()-1];
}

int main(void)
{
	int parent, child, weight;
	
	cin>>n;
	
	while(--n)
	{
		cin>>parent>>child>>weight;
		tree[parent].push_back(make_pair(child,weight));
	}
	
	ans = max(diameter(1), ans);
	
	cout<<ans<<'\n';
}
