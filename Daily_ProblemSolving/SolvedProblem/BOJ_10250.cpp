#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T,H,W,N,i,j,k;
	
	cin>>T;
	
	for(i=0; i<T; ++i)
	{
		cin>>H>>W>>N;
		
		for(j=1; j<=W; ++j)
		{
			for(k=1; k<=H; ++k)
				if(--N==0)
					break;
			if(N==0)
				break;
		}
		
		cout<<k*100+j<<'\n';
	}
	
	return 0;
}
