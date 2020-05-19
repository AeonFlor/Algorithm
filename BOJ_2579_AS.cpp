#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	int dp[301][2];
	int score[301];
	
	scanf("%d",&n);
	
	for(int i=1; i<=n; ++i)
		scanf("%d",&score[i]);
	
	dp[0][0] = dp[0][1] = 0;
	dp[1][0] = score[1];
	
	for(int i=2; i<=n; ++i)
	{
		dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + score[i];
		dp[i][1] = max(dp[i-2][1], dp[i-1][0]) + score[i];
	}
	
	printf("%d",max(dp[n][0],dp[n][1]));
	
	return 0;
}

// 잘 된 풀이를 스스로 이해해보고 다시 안 보고 짜보자! -> AS 는 After Solution 이라는 뜻 
