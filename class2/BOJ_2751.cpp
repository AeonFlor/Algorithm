#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,temp,min;
	cin>>N;
	
	int arr[N];
	
	for(int i=0; i<N; ++i)
		cin>>arr[i];
	
	for(int i=0; i<N-1; ++i)
	{
		min = i;
		for(int j=i+1; j<N; ++j)
			if(arr[min]>=arr[j])
				min = j;
		
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
	
	for(int i=0; i<N; ++i)
		cout<<arr[i]<<'\n';
	
	return 0;
}
