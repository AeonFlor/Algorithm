#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, low, high;
	int i,j;
	int tem_j, diff, min_diff;
	
	scanf("%d %d %d",&n, &low, &high);
	
	vector<int> vec_a(n);
	vector<int> vec_b;
	
	for(i=0; i<n; ++i)
		scanf("%d",&vec_a[i]);
	
	for(i=0; i<n; ++i)
	{
		min_diff=51;
		
		if(vec_a[i]>low-1 && vec_a[i]<high+1)
		{
			vec_b.push_back(vec_a[i]);
			continue;
		}
		
		for(j=low; j<high+1; ++j)
		{
			diff=0;
			tem_j=j;
			
			do
			{
				if(vec_a[i]%2 != tem_j%2)
					diff++;
				tem_j/=2;
			}while(vec_a[i]/=2 || tem_j);
			
			if(diff<min_diff)
			{
				if(min_diff!=51)
					vec_b.pop_back();
				vec_b.push_back(j);
				min_diff = diff;
			}
		}
	}
	
	for(i=0; i<n; ++i)
		printf("%d ",vec_b[i]);
}
