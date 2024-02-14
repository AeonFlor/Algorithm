#include <iostream>
#include <vector>

using namespace std;

int bitcnt(int n)
{
	int c, v=n;
	for(c=0; v; c++)
		v&=v-1;
	return c;
}

int main(void)
{
	int n, low, high;
	int i,j;
	int diff, diff_val, prev_min;
	
	scanf("%d %d %d",&n, &low, &high);
	
	vector<int> vec_a(n);
	vector<int> vec_b;
	
	for(i=0; i<n; ++i)
		scanf("%d",&vec_a[i]);
	
	for(i=0; i<n; ++i)
	{
		prev_min=51;
		
		if(vec_a[i]>low-1 && vec_a[i]<high+1)
		{
			vec_b.push_back(vec_a[i]);
			continue;
		}
		
		for(j=low; j<high+1; ++j)
		{
			diff = bitcnt(~(~vec_a[i]^j));
			
			if(diff<prev_min)
			{
				diff_val = j;
				prev_min = diff;
			}
		}
		
		vec_b.push_back(diff_val);
	}
	
	for(i=0; i<n; ++i)
		printf("%d ",vec_b[i]);
}
