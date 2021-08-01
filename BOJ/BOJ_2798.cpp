#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N,M,res=0,sum;
	
	scanf("%d %d",&N,&M);
	
	vector<int> cards(N);
	
	for(int i=0; i<N; ++i)
		scanf("%d",&cards[i]);
	
	for(int i=0; i<N-2; ++i)
		for(int j=i+1; j<N-1; ++j)
			for(int k=j+1; k<N; ++k)
			{
				sum = cards[i]+cards[j]+cards[k];
				if(sum>M)
					continue;
				if(sum==M)
				{
					printf("%d",M);
					return 0;
				}
				res = (M-res>M-sum)?sum:res;
			}
	printf("%d",res);
}

// 최악의 경우 100C3 (100*99*98) / (3*2*1) = 161700
