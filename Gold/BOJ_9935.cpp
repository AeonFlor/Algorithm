#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int idx = 0;
	string src, exp;
	char ans[1000001];
	
	cin>>src>>exp;
	
	for(int i=0; i<src.size(); ++i)
	{
		ans[idx++] = src[i];
		
		if(ans[idx-1] == exp[exp.size()-1])
		{
			if(idx<exp.size())
				continue;
			
			bool check = true;
			
			for(int j=0; j<exp.size(); ++j)
			{
				if(ans[idx-j-1] != exp[exp.size()-j-1])
				{
					check = false;
					break;
				}
			}
			
			if(check)
				idx -= exp.size();
		}
	}
	
	if(!idx)
		cout<<"FRULA\n";
	
	else
	{
		for(int i=0; i<idx; ++i)
			cout<<ans[i];
		cout<<'\n';
	}
}
