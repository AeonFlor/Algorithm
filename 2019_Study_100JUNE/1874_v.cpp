#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
	stack<int> seq;
	int x,n,r=0,c=0;

	cin>>n;
	vector<int> v;
	char *note = new char[n];

	for(int i=0; i<n; i++)
	{
		cin>>x;
		v.push_back(x);
	}

	for(int i=1; i<=n; i++)
	{
		seq.push(i);
		note[r]='+';
		r++;

		for(;seq.top()==v[c];c++)
		{
			seq.pop();
			note[r]='-';
			r++;
		}
	}

	if(c==n)
		for(int i=0; i<n; i++)
			cout<<note[i]<<endl;
	else
		cout<<"NO"<<endl;

	delete[] note;
	return 0;
}