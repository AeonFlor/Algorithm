#include <cstdio>
#include <algorithm>

using namespace std;

int nos;
int stair_score[301];
int dp[301][3];

int max_ss(int pos, int seq)
{
	if(pos==nos)
		return stair_score[nos];
	
	if(pos>nos)
		return -3000001;
	
	int & res = dp[pos][seq];
	
	if(res != 0)
		return res;
	
	if(seq==2)
		res = stair_score[pos] + max_ss(pos+2,1);
	
	else
		res = stair_score[pos] + max(max_ss(pos+1,seq+1), max_ss(pos+2,1));
	
	return res;
}

int main(void)
{
	fill_n(&dp[0][0],301*3,0);
	
	scanf("%d", &nos);
	
	for(int i=1; i<=nos; ++i)
		scanf("%d",&stair_score[i]);
	stair_score[0]=0;
	
	printf("%d",max_ss(0, 0));
	
	return 0;
}

/* 
평소에 쓰던 Bottom-UP 방식 말고, TOP-down 이 적합해보여서 이 방식으로 풀어보았다. -> BOTTOM-UP 이 더 적합해보여서 바꿨다. 어느거로 해도 상관은 없지만 올라간다는 이미지로 푸는게 더 직관적으로 다가와서 이렇게 풀었다.

dp[pos] 로만 두고 풀면 seq 에 따라 res 가 달라지는 데 이는 첫 값으로 고정되어 잘못된 결과를 도출한다.
dp 에 seq 까지 추가했다.

dp가 2차원인데 1차원으로 잘못 초기화하면 in file included from /usr/include/c++/9/algorithm:61 와 같이 긴 에러가 나온다.

잘 되는지 확인용.
DEPTH 를 통해 깊이를 확인한 판단이 사용되지는 않았지만 좋은 아이디어인 것 같다.
그리고 풀면서 안보이던 게 나중에 보니까 보인다.

예를 만들어서 0 0 0 0 0 9 9 9 0 0 했더니 27 나와서 seq 처리 값 수정했다.
-> 그대로 두고 2칸 점프할 때 seq 를 0이 아닌 1로 설정하는 게 맞다.

2칸을 점프해도 이미 한칸 밟은 상태이므로 0이 아닌 1로 설정해줘야한다.

다시 결과값이 90 나와서 이상 있나 싶어 확인해보니 아까 seq 크기를 2로 설정해서 value 가 2일 때 잘못된 거라고 생각하고 3으로 키워주니 75 나왔다. 초기화 할때 인덱스 설정도 제대로 하자.

또 틀렸다고 나온데 예에 1 1 9 9 9 1 을 했더니 20이 나와야 정상인데 21이 나온다.

max_ss 는 0에서 시작하는데 점수가 index 0부터 있어서 계단 점수는 index 1부터 입력했다.

바보 같이 위의 seq 를 안 바꿔줬다 ㅋㅋ -> 한 변수에 이상 확인하고 수정할 때는 전부 다 수정!

배운 게 많다. 깃허브 블로그 만들고 정리하면서 행동 매뉴얼 적어놓자.
*/
