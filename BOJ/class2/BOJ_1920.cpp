#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,M,input;
	cin>>N;
	vector<int> list(N);
	
	for(int i=0; i<N; ++i)
	{
		cin>>list[i];
	}
	
	cin>>M;
	
	for(int i=0; i<M; ++i)
	{
		cin>>input;
		
		if(find(list.begin(),list.end(),input)!=list.end())
			cout<<"1\n";
		else
			cout<<"0\n";
	}
	
	return 0;
}
