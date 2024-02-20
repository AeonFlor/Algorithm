#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

int main(void)
{
	stack<int> s;
	string in;
	int mv=1,res=0,oc=0,cc=0, c1=0, c2=0, j=0;

	getline(cin,in);
	cout<<in<<endl;
	in.erase(remove(in.begin(), in.end(), ' '), in.end());
	
	while(c1>=0 && c2>=0 && j<in.length())
	{
		if(in[j]=='(')
			c1++;
		else if(in[j]==')')
			c1--;
		if(in[j]=='[')
			c2++;
		else if(in[j]==']')
			c2--;
		j++;
	}
	
	if(c1!=0 || c2!=0)
	{
		cout<<"0\n";
		return 0;
	}

	for(int i = 0; i<in.length(); i++)
	{
		if(in[i] == '(' && in[i+1] != ')')
		{
			mv*=2;
		}
		else if(in[i] == '(' && in[i+1] == ')')
		{
			res+=mv*2;
			i++;
		}
		else if(in[i] == ')')
		{
			mv/=2;
		}
		else if(in[i] == '[' && in[i+1] != ']')
		{
			mv*=3;
		}
		else if(in[i] == '[' && in[i+1] == ']')
		{
			res+=mv*3;
			i++;
		}
		else if(in[i] == ']')
		{
			mv/=3;
		}
	}

	cout<<res<<endl;

	return 0;
}