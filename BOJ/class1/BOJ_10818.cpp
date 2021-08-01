#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,num,max=-1000001,min=1000001;
	
	cin>>N;
	
	for(int i=0; i<N; ++i)
	{
		cin>>num;
		max = (max>num)?max:num;
		min = (min<num)?min:num;
	}
	
	cout<<min<<" "<<max<<'\n';
	
	return 0;
}
