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
			int i = b%2;
			
			if(i==1)
			{
				a = a * exp_res % c;
				cout<<"ANS : "<<a<<'\n';
			}

			cout<<"-> EXP_RES : "<<exp_res<<'\n';
			exp_res = exp_res * exp_res % c;
		}
	}
	
	cout<<a%c<<'\n';
}

// 비트연산자 활용, 모듈러
