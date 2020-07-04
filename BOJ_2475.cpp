#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int serial,ans=0;
	
	for(int i=0; i<5; ++i)
	{
		cin>>serial;
		ans+=pow(serial,2);
	}
	
	cout<<ans%10<<'\n';
	
	return 0;
}
