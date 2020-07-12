#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,M,input;
	
	cin>>N;
	int cards[N];
	
	for(int i=0; i<N; ++i)
		cin>>cards[i];
	
	sort(cards,cards+N);
	
	cin>>M;
	for(int i=0; i<M; ++i)
	{
		cin>>input;
		cout<<upper_bound(cards, cards+N, input)-lower_bound(cards, cards+N, input)<<" ";
	}
	cout<<'\n';
	
	
	return 0;
}
