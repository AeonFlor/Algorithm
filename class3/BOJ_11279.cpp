#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> heap;

void insert_heap(int n)
{
	int cur = heap.size();
	
	heap.push_back(n);
	
	while(heap[cur]>heap[cur/2])
	{
		swap(heap[cur],heap[cur/2]);
		cur/=2;
	}
}

void delete_heap()
{
	int cur = 0;
	
	swap(heap[0], heap[heap.size()-1]);
	heap.pop_back();
	
	if(heap.size()>2)
	{
		while(heap[cur] < max(heap[cur*2+1],heap[cur*2+2]))
		{
			if(heap[cur*2+1] >= heap[cur*2+2])
			{
				swap(heap[cur], heap[cur*2+1]);
				cur*=2+1;
			}
			else
			{
				swap(heap[cur], heap[cur*2+2]);
				cur*=2+2;
			}
		}
	}
	
	else if(heap.size()==2)
	{
		if(heap[0] < heap[1])
			swap(heap[0], heap[1]);
	}
}

int main(void)
{
	int N, x;
	
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
				cout<<heap[0]<<'\n';
				delete_heap();
			}
		}
		
		else
			insert_heap(x);
	}
}
