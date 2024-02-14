#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> queue;
	int N,x,cur=0;
	char com[10];

	cin>>N;

	for(int i = 0; i < N; i++)
	{
		cin>>com;

		if(!strcmp(com,"push"))
		{
			cin>>x;
			cur++;
			queue.push_back(x);
		}

		else if(!strcmp(com,"pop"))
		{
			if(queue.empty())
				cout<<"-1\n";
			else
			{
				cout<<queue.front()<<"\n";
				queue.erase(queue.begin());
				cur--;
			}
		}

		else if(!strcmp(com,"size"))
			cout<<cur<<"\n";

		else if(!strcmp(com,"empty"))
		{
			if(cur==0)
				cout<<"1\n";
			else
				cout<<"0\n";
		}

		else if(!strcmp(com,"front"))
		{
			if(queue.empty())
				cout<<"-1\n";
			else
				cout<<queue.front()<<"\n";
		}

		else if(!strcmp(com,"back"))
		{
			if(queue.empty())
				cout<<"-1\n";
			else
				cout<<queue.back()<<"\n";
		}
	}

	return 0;
}