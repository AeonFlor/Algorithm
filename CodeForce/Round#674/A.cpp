#include <iostream>
 
using namespace std;
 
int main(void)
{
	int t, n, x;
	
	cin>>t;
	
	while(t--)
	{
		cin>>n>>x;
		
		if(n<3)
			cout<<"1\n";
		
		else
		{
			n = (n-3)/x+2;
			
			cout<<n<<'\n';
		}
	}
}
