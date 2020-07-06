#include <iostream>
#include <queue>

using namespace std;

// Queue 비우는 함수
void clear_queue(queue<int>* queue)
{
	while(!queue->empty())
		queue->pop();
}

void clear_queue(priority_queue<int>* queue)
{
	while(!queue->empty())
		queue->pop();
}

int main(void)
{
	int T,N,M,input,cnt;
	queue<int> sequence;
	priority_queue<int> priority;
	
	cin>>T;
	
	for(int i=0; i<T; ++i)
	{
		cnt = 0;
		
		cin>>N>>M;
		
		clear_queue(&sequence);
		clear_queue(&priority);

		for(int j=0; j<N; ++j)
		{
			cin>>input;
			sequence.push(input);
			priority.push(input);
		}
		
		while(true)
		{
			if(sequence.front()==0 || priority.top()==0)
				break;
			
			if(priority.top()==sequence.front())
			{
				++cnt;
				
				if(M--==0)// 처음 M 이 0인지 확인해야 되기에 후위 감소자로 해야됨.
					break;
				
				sequence.pop();
				priority.pop();
			}

			else
			{
				sequence.push(sequence.front());
				sequence.pop();
				
				if(M--==0)
					M = sequence.size()-1;
			}
		}

		cout<<cnt<<'\n';
	}
	
	return 0;
}
