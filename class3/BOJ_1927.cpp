#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, x;
	priority_queue<int, vector<int>, greater<int>> heap;
	
	cin>>N;
	
	while(N--)
	{
		cin>>x;
		
		if(x==0)
		{
			if(heap.empty())
				cout<<"0\n";
			
			else
			{
				cout<<heap.top()<<'\n';
				heap.pop();
			}
		}
		
		else
			heap.push(x);
	}
}
