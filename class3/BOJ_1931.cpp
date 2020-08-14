#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, start, end, ans=1, cur;
	vector<pair<int,int>> schedule;
	
	cin>>N;
	
	for(int i=0; i<N; ++i)
	{
		cin>>start>>end;
		schedule.push_back(make_pair(end,start));
	}
	
	sort(schedule.begin(), schedule.end());
	cur = schedule[0].first;
	
	for(int i=1; i<N; ++i)
		if(cur<=schedule[i].second)
		{
			cur = schedule[i].first;
			++ans;
		}
	
	cout<<ans<<'\n';
}
