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
	{
		ans = N-K+1;
		flag = true;
	}
	
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
			{
				flag = true;
				break;
			}
			
			if(prc[i]-1>-1 && !visited[prc[i]-1])
				rsv.push_back(prc[i]-1);
			
			if(prc[i]%2==0 && !visited[prc[i]/2])
				rsv.push_back(prc[i]/2);
			
			if(prc[i]+1<100001 && !visited[prc[i]+1])
				rsv.push_back(prc[i]+1);
		}
		
		q.push(rsv);
		++ans;
	}
	
	cout<<ans-1<<'\n';
	
	return 0;
}
