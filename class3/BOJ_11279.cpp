#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> heap;

void print()
{
	cout<<"================\n";
	for(int i=0; i<heap.size(); ++i)
		cout<<heap[i]<<' ';
	cout<<"\n================\n";
}

void insert_heap(int n)
{
	int cur = heap.size();
	
	heap.push_back(n);
	
	while(cur>0 && heap[cur]>heap[(cur-1)/2])
	{
		swap(heap[cur],heap[(cur-1)/2]);
		cur=(cur-1)/2;
		//print();
	}
}

void delete_heap()
{
	int cur = 0;
	
	swap(heap[0], heap[heap.size()-1]);
	heap.pop_back();
	
	if(heap.size()>2)
	{
		while(cur*2+2<heap.size() && heap[cur] < max(heap[cur*2+1],heap[cur*2+2]))
		{
			//print();
			if(heap[cur*2+1] >= heap[cur*2+2])
			{
				swap(heap[cur], heap[cur*2+1]);
				cur=cur*2+1;
			}
			else
			{
				swap(heap[cur], heap[cur*2+2]);
				cur=cur*2+2;
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
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
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

/*
13
2
1
4
7
8
3
25
47
0
0
0
0
0
*/