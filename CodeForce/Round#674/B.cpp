#include <iostream>
 
using namespace std;
 
int main(void)
{
	int t, n, m;
	
	cin>>t;
	
	while(t--)
	{
		int v11,v12,v21,v22;
		bool flag = false;
		
		cin>>n>>m;
		
		for(int i=0; i<n; ++i)
		{
			cin>>v11>>v12>>v21>>v22;
			
			if(v12 == v21)
				flag = true;
		}
		
		if(m%2)
			flag = false;
		
		if(flag)
			cout<<"YES\n";
		
		else
			cout<<"NO\n";
	}
}
