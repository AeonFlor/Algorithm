#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n,x,num;
	vector<int> res;
	
	scanf("%d %d",&n,&x);
	
	for(int i=0; i<n; ++i)
	{
		scanf("%d",&num);
		if(num<x)
			res.push_back(num);
	}
	
	for(int i=0; i<res.size(); ++i)
	{
		printf("%d ",res[i]);
	}
}
