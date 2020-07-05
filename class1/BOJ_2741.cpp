#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	
	cin>>N;
	
	for(int i=1; i<=N; ++i)
		cout<<i<<'\n';
	
	return 0;
}
