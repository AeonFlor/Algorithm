#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void)
{
	int M, x;
	string com;
	
	set<int> S;
	
	cin>>M;
	
	while(M--)
	{
		cin>>com;
		
		if(!com.compare("add"))
		{
				cin>>x;
				S.insert(x);
		}
				
		else if(!com.compare("remove"))
		{
				cin>>x;
				S.erase(S.find(x));
		}
				
		else if(!com.compare("check"))
		{
				cin>>x;
				cout<<S.count(x)<<'\n';
		}
				
		else if(!com.compare("toggle"))
		{
				cin>>x;
				if(S.find(x)!=S.end())
					S.erase(S.find(x));
				else
					S.insert(x);
		}
				
		else if(!com.compare("all"))
		{
				for(int i=1; i<21; ++i)
					S.insert(i);
		}
				
		else if(!com.compare("empty"))
				S.clear();
	}
}
