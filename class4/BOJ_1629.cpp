#include <iostream>

using namespace std;

int main(void)
{
	unsigned long long a,b,c,exp_res;
	cin>>a>>b>>c;
	
	exp_res = a%c;
	
	if(exp_res!=0)
	{
		a=1;
		for(; b!=0; b=b>>1)
		{
			if(b%2)
				a = a * exp_res % c;
			
			exp_res = exp_res * exp_res % c;
		}
	}
	
	cout<<a%c<<'\n';
}
