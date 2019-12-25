#include <iostream>
#include <queue>

using namespace std;

vector<int> temp;

void merge(vector<int> seq, int begin, int mid, int end)
{
	int left = begin, m = mid+1, i = begin, l;
	
	while(left<=mid && m<=end)
	{
		if(seq[left]<=seq[m])
			temp[i++] = seq[left++];
		else
			temp[i++] = seq[m++];
	}
	
	if(left>mid)
		for(l=m; l<=end; l++)
			temp[i++]=seq[l];
	
	else
		for(l=left; l<=mid; l++)
			temp[i++]=seq[l];
	
	for(l=begin; l<=end; l++)
		seq[l] = temp[l];
}

void sort(vector<int> seq, int begin, int end)
{
	int mid;
	
	if(begin<end)
	{
		mid = (begin+end)/2;
		sort(seq, begin, mid);
		sort(seq, mid+1, end);
		merge(seq, begin, mid, end);
	}
}

int main(void)
{
	int a,b,n;
	
	cin>>a>>b;
	
	vector<int> seq(a+b);
	
	for(int i=0; i<a+b; ++i)
	{
		cin>>n;
		seq[i]=n;
		cout<<seq[i]<<" ";
	}
	
	for(int i=0; i<a+b; ++i)
	{
		cout<<seq[i]<<" ";
	}
	
	sort(seq,0,a+b);
	
	for(int i=0; i<a+b; ++i)
		cout<<seq[i]<<" ";
}
