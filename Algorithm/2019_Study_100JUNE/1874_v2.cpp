#include <iostream>
#include <stack>
#include <cstring>
#include <queue>

using namespace std;

int main(void)
{
	stack<int> seq;
	queue<int> ans;
	int x,n,i=0,c=0;
	string res;

	cin>>n;

	for(int j=0; j<n; j++)
	{
		cin>>x;
		ans.push(x);
	}

	while(!ans.empty())
	{
		if(seq.empty())
		{
			seq.push(++i);
			res += '+';
		}

		else if(seq.top()>ans.front())
		{
			cout<<"NO";
			return 0;
		}

		else if(seq.top()==ans.front())
		{
			seq.pop();
			ans.pop();
			res += '-';
		}

		else
		{
			seq.push(++i);
			res += '+';
		}
	}
	for(int i=0; i<n*2; i++)
		cout<<res[i]<<"\n";

	return 0;
}

// seq.empty() == TRUE 인 경우도 생각해야 되니 else 에 