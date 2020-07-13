#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,K,cnt=0;
	queue<int> loop;
	
	cin>>N>>K;
	
	for(int i=1; i<=N; ++i)
		loop.push(i);
	
	cout<<"<";
	while(loop.size()>1)
	{
		if(K==++cnt)
		{
			cout<<loop.front()<<", ";
			loop.pop();
			cnt=0;
		}
		
		else
		{
			loop.push(loop.front());
			loop.pop();
		}
	}
	
	cout<<loop.front()<<">\n";
	
	return 0;
}
