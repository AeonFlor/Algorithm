#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(void)
{
	stack<int> s;
	int N,x;
	char com[10];
	cin>>N;

	for(int i=0; i<N; i++)
	{
		cin>>com;

		if(!strcmp(com,"push"))
		{
			cin>>x;
			s.push(x);
		}

		else if(!strcmp(com,"pop"))
		{
			if(s.empty())
				cout<<"-1"<<endl;
			else
			{
				cout<<s.top()<<endl;
				s.pop();
			}
		}

		else if(!strcmp(com,"size"))
			cout<<s.size()<<endl;

		else if(!strcmp(com,"empty"))
			cout<<s.empty()<<endl;

		else if(!strcmp(com,"top"))
		{
			if(s.empty())
				cout<<"-1"<<endl;
			else
				cout<<s.top()<<endl;
		}
	}

	return 0;
}