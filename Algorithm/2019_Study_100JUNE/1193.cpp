#include <iostream>

using namespace std;

int main(void)
{
	int x,i,ck=0;

	cin>>x;

	for(i=1; ck<x; i++)
		ck+=i;
	ck-=i-1;
	x-=ck;
	i--;

	if(i%2==0)
		cout<<x<<"/"<<i-x+1<<endl;
	else
		cout<<i-x+1<<"/"<<x<<endl;

	return 0;
}

// 분모, 분자는 기본이 1이기에 i-x 에 +1 해줘야 한다.