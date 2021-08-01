#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,x,y;
	vector<pair<int,int>> coor;
	
	cin>>N;
	
	for(int i=0; i<N; ++i)
	{
		cin>>x>>y;
		coor.push_back(pair<int,int>(x,y));
	}
	
	sort(coor.begin(),coor.end());
	
	for(int i=0; i<N; ++i)
		cout<<coor[i].first<<" "<<coor[i].second<<'\n';
	
	return 0;
}
