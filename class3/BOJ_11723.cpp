#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int M, x;
	bool S[21] = {false,};
	string com;
	
	cin>>M;
	
	while(M--)
	{
		cin>>com;
		
		if(com == "add")
		{
			cin>>x;
			S[x] = true;
		}
				
		else if(com == "remove")
		{
			cin>>x;
			S[x] = false;
		}
				
		else if(com == "check")
		{
			cin>>x;
			cout<<(S[x])?1:0;
			cout<<'\n';
		}
				
		else if(com == "toggle")
		{
			cin>>x;
			S[x] = !S[x];
		}
				
		else if(com == "all")
		{
			for(int i=1; i<21; ++i)
				S[i] = true;
		}
				
		else if(com == "empty")
		{
			for(int i=1; i<21; ++i)
				S[i] = false;
		}
	}
}
