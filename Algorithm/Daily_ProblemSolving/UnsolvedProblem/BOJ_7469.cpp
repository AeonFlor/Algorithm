#include <iostream>
#include <vector>

using namespace std;

vector<int> list(100001, 0);
int count = 0;

//O(n)
void merge(vector<int>& res, int start, int mid, int end)
{
	vector<int> sorted(res.size());
	
	int i = start;
	int j = mid+1;
	int k = start;
	
	while(i<=mid && j<=end)
	{
		if(res[i]<res[j])
			sorted[k++] = res[i++];
		
		else
			sorted[k++] = res[j++];
	}
	
	while(i<=mid)
		sorted[k++] = res[i++];
	
	while(j<=end)
		sorted[k++] = res[j++];
	
	for(int r=start; r<k; ++r)
		res[r] = sorted[r];
}

//O(nlgn) -> divide is O(lgn)
void mergesort(vector<int>& res, int start, int end)
{	
	int mid;
	
	if(start < end)
	{
		mid = (start+end)/2;
		mergesort(res, start, mid);
		mergesort(res, mid+1, end);
		
		merge(res, start, mid, end);
	}
}

//O(nlgn)
void Q(int start, int end, int target)
{
	vector<int> res(end-start+1, 0);
	int i = 0;
	
	for(int r=start; r<=end; ++r)
		res[i++] = list[r];
	
	mergesort(res, 0, end-start);
	
	cout<<res[target]<<'\n';
}

int main(void)
{
	int n, m;
	int i, j, k;
	
	cin>>n>>m;
	
	for(int r=0; r<n; ++r)
		cin>>list[r];
	
	while(m--)
	{
		cin>>i>>j>>k;
		
		Q(i-1, j-1, k-1);
	}
}
