#include <iostream>

using namespace std;

int main(void)
{
	int plane[100][100]={0,};
	int N, x, y, ans=0;
	
	cin>>N;
	
	for(int i=0; i<N; ++i)
	{
		cin>>x>>y;
		
		for(int j=x; j<x+10; ++j)
			for(int k=y; k<y+10; ++k)
				plane[j][k]=1;
	}
	
	for(int i=0; i<100; ++i)
		for(int j=0; j<100; ++j)
			ans+=plane[i][j];
	
	cout<<ans<<endl;
	
	return 0;
}
