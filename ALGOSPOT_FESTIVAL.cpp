#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int c,n,l,i,j;
	double res=101;
	
	scanf("%d",&c);
	
	while(c--)
	{
		scanf("%d %d",&n,&l);
		
		vector<int> ps(n);
		ps[-1]=0;
		
		for(i=0; i<n; ++i)
		{
			scanf("%d",&ps[i]);
			ps[i]+=ps[i-1];
		}
		
		for(i=l; i<n+1; ++i)
		{
			for(j=i-1; j<n; ++j)
				res=min(res,(double)(ps[j]-ps[j-i])/i);
		}
		
		printf("%.12f\n",res);
	}
}
