#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, input;
	vector<int> seq;
	vector<int> sorted;
	
	
	cin>>N;
	
	for(int i=0; i<N; ++i)
	{
		cin>>input;
		seq.push_back(input);
	}
	
	sorted = seq;
	sort(sorted.begin(),sorted.end());
	sorted.erase(unique(sorted.begin(),sorted.end()),sorted.end());
	
	for(int i=0; i<N; ++i)
	{
		cout<<find(sorted.begin(),sorted.end(),seq[i])-sorted.begin()<<' ';
	}
	cout<<'\n';
}
