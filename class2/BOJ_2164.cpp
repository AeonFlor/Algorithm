#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	queue<int> list;
	
	cin>>N;
	
	for(int i=1; i<=N; ++i)
	{
		list.push(i);
	}
	
	while(list.size()>1)
	{
		list.pop();
		if(list.size()==1)
			break;
		list.push(list.front());
		list.pop();
	}
	
	cout<<list.front()<<'\n';
	
	return 0;
}
