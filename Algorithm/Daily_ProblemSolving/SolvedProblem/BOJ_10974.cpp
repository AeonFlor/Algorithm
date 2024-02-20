#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, i;
	vector<int> v;
	
	scanf("%d",&n);
	
	for(i=1; i<=n; ++i)
		v.push_back(i);
	
	do
	{
		for(i=0; i<n; ++i)
			printf("%d ",v[i]);
		printf("\n");
	}while(next_permutation(v.begin(), v.end()));
}
