#include <cstdio>

using namespace std;

int main(void)
{
	int N;
	
	scanf("%d",&N);
	
	int arr[N+1]={0,1,2,};
	
	for(int i=3; i<N+1; ++i)
		arr[i]=(arr[i-1]+arr[i-2])%15746;
	
	printf("%d",arr[N]);
    
	return 0;
}
