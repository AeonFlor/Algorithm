#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int N,K;
	
	cin>>N>>K;
	
	vector<bool> visited(100000,false);
	vector<int> prc;
	vector<int> rsv;
	int ans = 0;
	bool flag = false;
	
	if(K<N)
		return N-K;
	
	queue<vector<int>> q;
	q.push(vector<int>(1,K));
	
	while(!flag)
	{
		prc = q.front();
		rsv.clear();
		q.pop();
		
		for(int i=0; i<prc.size(); ++i)
		{
			visited[prc[i]]=true;
			
			if(prc[i]==N)
				flag = true;
			
			if(!visited[prc[i]-1] && prc[i]-1>-1)
				rsv.push_back(prc[i]-1);
			
			if(!visited[prc[i]/2] && prc[i]%2==0)
				rsv.push_back(prc[i]/2);
			
			if(!visited[prc[i]+1] && prc[i]+1<100001)
				rsv.push_back(prc[i]+1);
		}
		
		q.push(rsv);
		++ans;
	}
	
	cout<<ans-1<<'\n';
	
	return 0;
}
