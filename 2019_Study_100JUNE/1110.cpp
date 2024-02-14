#include <iostream>

using namespace std;

int main(void)
{
	int N,Nc,cnt=1;
	
	cin>>N;

	Nc = (N%10)*10+(N/10+N%10)%10;

	while(Nc!=N)
	{
		cnt++;
		Nc = (Nc%10)*10+(Nc/10+Nc%10)%10;
	}

	cout<<cnt<<endl;

	return 0;
}

/* bm1387 code
#include<stdio.h>

int main()
{
	int cnt=1, n, m;
	scanf("%d", &n);
	for(m=n; 1; cnt++){
		n=n%10*10+(n/10+n%10)%10;
		if(m==n) break;
	}
	printf("%d", cnt);
	return 0;
}
나는 원래 것에 복사해서 반복적으로 연산한 뒤 원본이랑 대조했고, 이 사람은 원본을 연산한 뒤 복사한 것과 대조했다.
한 차례 과정이 줄어들었다. ( 원본이냐, 복사이냐 차이이기 보다는 조건문 차이인 것 같다. )
*/