#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int N, x;
	priority_queue<int> heap;
	
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
