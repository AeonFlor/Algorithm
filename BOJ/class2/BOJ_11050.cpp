#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,K,denom=1,numer=1;
	
	cin>>N>>K;
	
	if(N-K<K)
		K=N-K;
	
	for(int i=1; i<=K; ++i)
	{
		denom *= i;
		numer *= (N-i+1);
	}
	
	cout<<numer/denom<<'\n';
	
	return 0;
}
