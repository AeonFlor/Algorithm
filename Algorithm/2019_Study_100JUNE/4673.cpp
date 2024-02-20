#include <iostream>

using namespace std;

int main(void)
{
	int arr[10003]={0,};
	int tar;

	for(int i=1; i<9974; i++)
	{
		tar=i+i/1000+i%1000/100+i%100/10+i%10;
		arr[tar]=1;
	}

	for(int i=1; i<10001; i++)
		if(arr[i]==0)
			cout<<i<<"\n";

	return 0;
}

/*
처음에 i 가 9984 까지 가능한 줄 알았는데 이는 10014 까지 가기에 arr 의 인덱스를 초과했다.
따라서 abort trap: 6 에러가 났다. 수를 다시 찾아보니 9973 의 경우 10001, 9972 의 경우 9999 여서,
9973까지 가능하게 하려고 한다. vector 로 할까 했는데 아직 딱히 필요 없는 것 같다.

그렇다면 10001 까지 기록되는데 왜 10002는 안 되고, 10003이 되는가?
*/