#include <iostream>
#include <queue>

using namespace std;

// Queue 비우는 함수
void clear_queue(queue<int>* queue)
{
	while(!queue->empty())
		queue->pop();
	
	cout<<"Queue Cleared!\n";
}

void clear_queue(priority_queue<int>* queue)
{
	while(!queue->empty())
		queue->pop();
	
	cout<<"Queue Cleared!\n";
}

// Queue 출력하는 함수
void print_queue(queue<int> queue)
{
	int size = queue.size();
	for(int i=0; i<size; ++i)
		{
			cout<<"["<<queue.front()<<"] ";
			queue.pop();
		}
		cout<<"\n";
}

void print_queue(priority_queue<int> queue)
{
	int size = queue.size();
	for(int i=0; i<size; ++i)
		{
			cout<<"["<<queue.top()<<"] ";
			queue.pop();
		}
		cout<<"\n";
}

int main(void)
{
	int T,N,M,input,cnt=0;
	queue<int> sequence;
	priority_queue<int> priority;
	
	queue<int> test_q;
	priority_queue<int> test_pq;
	
	cout<<"Input T : ";
	cin>>T;
	
	for(int i=0; i<T; ++i)
	{
		cout<<"Input N,M : ";
		cin>>N>>M;
		
		clear_queue(&sequence);
		clear_queue(&priority);

		for(int j=0; j<N; ++j)
		{
			cin>>input;
			sequence.push(input);
			priority.push(input);
		}
		
		// print_queue, clear_queue 잘 되는지 확인
		
		cout<<"Print sequence\n";
		print_queue(sequence);
		cout<<"Print priority\n";
		print_queue(priority);
		
		test_q = sequence;
		test_pq = priority;
		
		cout<<"Print test_q\n";
		print_queue(test_q);
		cout<<"Print test_pq\n";
		print_queue(test_pq);
		
		clear_queue(&test_q);
		clear_queue(&test_pq);
		
		cout<<"After Cleaning...\n";
		
		cout<<"Print test_q\n";
		print_queue(test_q);
		cout<<"Print test_pq\n";
		print_queue(test_pq);
		
		while(true)
		{
			if(priority.top()==sequence.front())
			{
				++cnt;
				cout<<"Print "<<sequence.front()<<"\n";
				
				if(M--==0)// 처음 M 이 0인지 확인해야 되기에 후위 감소자로 해야됨.
					break;
				
				sequence.pop();
				priority.pop();
			}

			else
			{
				sequence.push(sequence.front());
				cout<<"Relocation "<<sequence.front()<<"\n";
				sequence.pop();
				
				if(M--==0)
					M = sequence.size()-1;
			}
		}

		cout<<cnt<<'\n';
	}
	
	return 0;
}
