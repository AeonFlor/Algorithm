#include <cstdio>
#include <algorithm>

using namespace std;

int wine[10001];
int dp[10001][3];

int main(void)
{
	int n;
	
	scanf("%d", &n);
	
	for(int i=1; i<=n; ++i)
		scanf("%d",&wine[i]);
	  
	dp[0][0] = dp[0][1] = 0;
	dp[1][0] = wine[1];
	
	for(int i=2; i<=n; ++i)
	{
		dp[i][0] = max(dp[i-2][0],dp[i-2][1]) + wine[i];
		dp[i][1] = max(dp[i-1][2] + wine[i],dp[i-1][0] + wine[i]);
		dp[i][2] = max(dp[i-1][0]-wine[i-1]+wine[i],dp[i][0]);
	}
	printf("%d",max(max(dp[n-1][0],dp[n-1][1]),max(dp[n][0],dp[n][1])));
	
	return 0;
}
