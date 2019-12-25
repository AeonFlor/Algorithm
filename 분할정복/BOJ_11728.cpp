#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int a, b, i, idx1=0, idx2=0;
	
	cin>>a>>b;
	
	vector<int> a_seq(a), b_seq(b), ans(a+b);
	
	for(i=0; i<a; ++i)
		cin>>a_seq[i];
	for(i=0; i<b; ++i)
		cin>>b_seq[i];
	
	for(i=0; i<a+b; ++i)
	{
		if(idx1>=a)
		{
			ans[i]=b_seq[idx2++];
		}
		else if(idx2>=b)
		{
			ans[i]=a_seq[idx1++];
		}
		else
		{
			if(a_seq[idx1]>b_seq[idx2])
			{
				ans[i]=b_seq[idx2++];
			}
			else
				ans[i]=a_seq[idx1++];
		}
	}
	
	for(i=0; i<a+b; ++i)
		cout<<ans[i]<<" ";
}
