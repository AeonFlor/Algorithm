// 시간 초과 뜬다.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int N,M;
	
	cin>>N>>M;
	
	vector<string> name(N);
	vector<string> res;
	
	string check;
	
	for(int i=0; i<N; ++i)
		cin>>name[i];
	
	for(int i=0; i<M; ++i)
	{
		cin>>check;
		
		if(find(name.begin(), name.end(), check)!=name.end())
			res.push_back(check);
	}
	
	cout<<res.size()<<"\n";
	
	for(int i=0; i<res.size(); ++i)
		cout<<res[i]<<"\n";
}
