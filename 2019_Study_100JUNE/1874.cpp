#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(void)
{
	stack<int> seq;
	int x,n,c=0;
	string res;

	cin>>n;
	int *arr = new int[n+1];

	for(int i=0; i<n; i++)
	{
		cin>>x;
		arr[i]=x;
	}

	for(int i=1; i<=n; i++)
	{
		seq.push(i);
		res += '+';

		while(!seq.empty() && seq.top()==arr[c])
		{
			seq.pop();
			res += '-';
			c++;
		}
	}

	if(c==n)
		for(int i=0; i<n*2; i++)
			cout<<res[i]<<endl;
	else
		cout<<"NO"<<endl;

	delete[] arr;
	return 0;
}

// stack 은 메모리 영역 자료구조라 empty 체크 안하고 pop 하면 error 난다.
// res 범위는 수 하나당 +, - 가 나올 수 있으므로 최대 n*2 개 이다.
// 중간에 아니다 싶으면 탈출하는 게 실행 시간을 줄여준다.