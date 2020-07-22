#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<pair<string,int>> lib;
vector<pair<string,int>> sorted_lib;

int binary_search(string name, int begin, int end)
{
	int mid = (begin+end)/2;
	
	if(name.compare(sorted_lib[mid].first) == 0)
		return mid;
	
	else if(name.compare(sorted_lib[mid].first) > 0)
		return binary_search(name, mid, end);
	
	else
		return binary_search(name, begin, mid);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	string input, name;
	
	cin>>N>>M;
	
	for(int i=0; i<N; ++i)
	{
		cin>>name;
		lib.push_back(make_pair(name,i+1));
	}
	
	sorted_lib=lib;
	sort(sorted_lib.begin(), sorted_lib.end());
	
	for(int i=0; i<M; ++i)
	{
		cin>>input;
		
		if(input[0]>64 && input[0]<91)
			cout<<sorted_lib[binary_search(input, 0, sorted_lib.size())].second<<'\n';
		
		else
			cout<<lib[atoi(input.c_str())-1].first<<'\n';
	}
}
