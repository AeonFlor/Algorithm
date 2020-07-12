#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int>& arr, int s, int e)
{
	int pivot = arr[s];
	int bs = s, be = e;
	int temp;
	
	while(s<e)
	{
		while(pivot<=arr[e] && s<e)
			e--;
		
		if(s>e)
			break;
		
		while(pivot>=arr[s] && s<e)
			s++;
		
		if(s>e)
			break;
		
		temp = arr[s];
		arr[s] = arr[e];
		arr[e] = temp;
	}
	
	temp = arr[s];
	arr[s] = arr[bs];
	arr[bs] = temp;
	
	if(bs<s)
		quick_sort(arr,bs,s-1);
	if(be>e)
		quick_sort(arr,s+1,be);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,temp,min;
	cin>>N;
	
	vector<int> arr(N);
	
	for(int i=0; i<N; ++i)
		cin>>arr[i];
	
	quick_sort(arr,0,N-1);
	
	for(int i=0; i<N; ++i)
		cout<<arr[i]<<'\n';
	
	return 0;
}
