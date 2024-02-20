#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	int t,r,cnt;
	char s='A';
	string res;
	cin>>t;

	for(int i=0; i<t; i++)
	{
		cnt=0;
		cin>>r;
		while(s!='\n')
		{
			s=cin.get();
			cout<<"s : "<<s<<endl;
			for(int j=0; j<r; j++)
				res[cnt++]=s;
			cout<<"res : "<<res<<endl;
		}
		cout<<res<<endl;
	}

	return 0;
}