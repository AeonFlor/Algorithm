#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second < b.second;
}

int main(void)
{
	int N, input, prior=0;
	vector<pair<int,int>> seq;
	
	cin>>N;
	
	for(int i=1; i<=N; ++i)
	{
		cin>>input;
		seq.push_back(make_pair(input,i));
	}
	
	sort(seq.begin(), seq.end());
	
	for(int i=0; i<N-1; ++i)
	{
		if(seq[i].first!=seq[i+1].first)
			seq[i].first = prior++;
		else
			seq[i].first = prior;
	}
	
	seq[N-1].first = prior;
	sort(seq.begin(), seq.end(), cmp);
	
	for(int i=0; i<N; ++i)
	{
		cout<<seq[i].first<<' ';
	}
	cout<<'\n';
}
