#include <cstdio>
#include <algorithm>

using namespace std;

int wine[10001];
int dp[10001][2];

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
		dp[i][1] = dp[i-1][0] + wine[i];
		dp[i][1] = max(dp[i-1][1],dp[i][1]); // 2칸 연속으로 점프할 경우 2칸 점프했을 때
		// 100 400 2 1 4 200 이 있다면 4일 때, 점프를 해서 온 1에서의 최댓값과 2에서 점프를 해서 온 4에서의 최댓값을 비교해서 4에서 최댓값이 더 작다면 2칸을 뛰는 게 맞다.
	}
	
	// 두번째 인덱스는 연속된 잔의 수 1이면 2번 연속 마셨다는 것이므로 건너뛰어야한다.
	
	printf("%d",max(max(dp[n-1][0],dp[n-1][1]),max(dp[n][0],dp[n][1])));
	
	return 0;
}

/*
dp[0] = 100
dp[1] = 500
dp[2] = 500

dp[0] + 1 + 2 103, dp[1] + 1 501
dp[2], dp[3] 501

dp[1] + 4 + 1 505, dp[2] + 4 504
dp[3], dp[4] 505

dp[2] + 200 + 4 704, dp[3] + 200 701
dp[4], dp[5] 704
*/
