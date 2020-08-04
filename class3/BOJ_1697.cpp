// 좌표 100000 넘어갈 수 있나?
#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
bool visited[100001] = {false};

int hide8seek(int pos)
{	
	if(pos==K)
		return 1;
	
	if(visited)
		return 100001;
	
	visited[pos]=true;
	
	if(pos<0 || pos>100000) // 루프 돌아서 한 번 방문한 곳이면 false
		return 100001;
	
	if(pos != 0)
		return min(hide8seek(pos*2),min(hide8seek(pos-1),hide8seek(pos+1)));
	
	else
		return min(hide8seek(pos-1),hide8seek(pos+1));
}

int main(void)
{
	cin >> N >> K;

	cout << hide8seek(N) << '\n';
}
