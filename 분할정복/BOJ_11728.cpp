#include <iostream>
#include <queue>

using namespace std;

void input(int iter, queue<int>&seq)
{
	int n;
	
	for(int i=0; i<iter; ++i)
	{
		cin>>n;
		seq.push(n);
	}
}

int main(void)
{
	int a,b, min;
	
	cin>>a>>b;
	
	min = (a>b)? b:a;
	
	queue<int> a_seq;
	queue<int> b_seq;
	
	input(a,a_seq);
	input(b,b_seq);
	
	for(int i=0; i<min*2; ++i)
	{	
		if(!(a_seq.empty()) && a_seq.front()<b_seq.front() || b_seq.empty())
		{
			cout<<a_seq.front()<<" ";
			a_seq.pop();
		}
		else
		{
			cout<<b_seq.front()<<" ";
			b_seq.pop();
		}
	}
	
	if(a_seq.empty())
	{
		while(!(b_seq.empty()))
		{
			cout<<b_seq.front()<<" ";
			b_seq.pop();
		}
	}
	
	else if(b_seq.empty())
	{
		while(!(a_seq.empty()))
		{
			cout<<a_seq.front()<<" ";
			a_seq.pop();
		}
	}
	
	return 0;
}
