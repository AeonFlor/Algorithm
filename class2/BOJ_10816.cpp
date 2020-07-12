#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,M,input,cnt;
	int left, mid, right;
	
	cin>>N;
	int cards[N];
	
	for(int i=0; i<N; ++i)
		cin>>cards[i];
	
	sort(cards,cards+N);
	
	for(int i=0; i<N; ++i)
		cout<<cards[i]<<" ";
	cout<<'\n';
	
	cin>>M;
	for(int i=0; i<M; ++i)
	{
		cin>>input;
		cnt=0;
		left = 0;
		right = N-1;
		mid = N/2;
		
		while(right-left>=0)
		{
			if(cards[mid]<input)
				left=mid+1;
			else if(cards[mid]>input)
				right=mid-1;
			else
				break;
			mid = right+left/2;
		}
		
		for(int j=mid; cards[j]==cards[mid]; ++j)
			++cnt;
		
		cout<<cnt<<" ";
	}
	cout<<'\n';
	
	
	return 0;
}
