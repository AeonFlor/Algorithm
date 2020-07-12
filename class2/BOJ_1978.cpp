#include <iostream>

using namespace std;

int main(void)
{
	int N,input,ans=0;
	cin>>N;
	bool arr[1001];
	
	fill_n(arr,1001,true);
	arr[1]=false;
	
	for(int i=2; i<1001; ++i)
		if(arr[i])
			for(int j=i*2; j<1001; j+=i)
				arr[j]=false;
	
	for(int i=0; i<N; ++i)
	{
		cin>>input;
		if(arr[input])
			++ans;
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
