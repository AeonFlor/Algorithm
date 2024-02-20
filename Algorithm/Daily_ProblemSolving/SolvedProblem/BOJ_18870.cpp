#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, input, prior=0;
	vector<pair<int,int>> seq;
	
	cin>>N;
	
	int ans[N];
	
	for(int i=0; i<N; ++i)
	{
		cin>>input;
		seq.push_back(make_pair(input,i));
	}
	
	sort(seq.begin(), seq.end());
	
	for(int i=0; i<N-1; ++i)
	{
		if(seq[i].first!=seq[i+1].first)
			ans[seq[i].second] = prior++;
		else
			ans[seq[i].second] = prior;
	}
	
	ans[seq[N-1].second] = prior;
	
	for(int i=0; i<N; ++i)
	{
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}
