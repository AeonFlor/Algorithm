#include <iostream>
#include <cstring>

using namespace std;

string iter(int r)
{
	string res="";
	string s;
	
	cin>>s;

	for(int i=0; i<s.length(); i++)
		res.append(r,s[i]);

	return res;
}

int main(void)
{
	int t,r;

	cin>>t;

	for(int i=0; i<t; i++)
	{
		cin>>r;
		cout<<iter(r)<<endl;
	}

	return 0;
}