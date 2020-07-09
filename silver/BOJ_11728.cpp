#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,M,input;
	vector<int> arr;
	
	cin>>N>>M;
	
	for(int i=0; i<N+M; ++i)
	{
		cin>>input;
		arr.push_back(input);
	}
	
	sort(arr.begin(),arr.end());
	
	for(int i=0; i<N+M; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<'\n';
	
	return 0;
}
