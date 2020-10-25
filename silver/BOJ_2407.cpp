#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, d1, d2, rise, div;
	int ans[100] = {1,};
	int tmp1[100];
	int tmp2[100];
	
	cin>>n>>m;
	
	if(m > n/2)
		m = n-m;
	
	for(int i=n-m+1; i<=n; ++i)
	{
		fill(tmp1, tmp1+100, 0);
		fill(tmp2, tmp2+100, 0);
		
		d1 = i%10;
		d2 = i/10;
		
		for(int j=0; j<100; ++j)
		{
			tmp1[j] = ans[j]*d1;
			tmp2[j] = ans[j]*d2;
			
			tmp2[j] += tmp1[j+1];
		}
		
		tmp2[0] = tmp1[0];
		rise = 0;
		
		for(int j=0; j<100; ++j)
		{
			tmp2[j] += rise;
			
			if(tmp2[j]/10)
			{
				rise = tmp2[j]/10;
				tmp2[j]%=10;
			}
			
			else
				rise = 0;
		}
		
		for(int j=0; j<100; ++j)
			ans[j] = tmp2[j];
		
		for(int k=0; k<100; ++k)
			cout<<ans[k];
		cout<<'\n';
	}
	
	for(int k=0; k<100; ++k)
		cout<<ans[k];
	cout<<'\n';
	
	bool flag = false;
	
	for(int i=99; i>=0; --i)
	{
		if(!flag && ans[i] == 0)
			continue;
		
		else
		{
			flag = true;
			cout<<ans[i];
		}
	}
	
	if(m==0)
		cout<<"1\n";
	cout<<'\n';
}
