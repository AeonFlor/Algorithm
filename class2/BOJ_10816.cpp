#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,M,input;
	bool check=true;
	vector<pair<int,int>> having;
	cin>>N;
	
	for(int i=0; i<N; ++i)
	{
		cin>>input;
		
		for(int j=0; j<having.size(); ++j)
		{
			if(input==having[j].first)
			{
				++having[j].second;
				check = false;
			}
		}
		
		if(check)
			having.push_back(pair<int,int>(input,1));
		
		check = true;
	}
	
	cin>>M;
	
	for(int i=0; i<M; ++i)
	{
		cin>>input;
		
		for(int j=0; j<having.size(); ++j)
		{
			if(input==having[j].first)
			{
				cout<<having[j].second<<" ";
				check = false;
			}
		}
		
		if(check)
			cout<<"0 ";
		
		check=true;
	}
	cout<<'\n';
	
	
	return 0;
}
