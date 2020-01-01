#include <iostream>
#include <vector>

using namespace std;

void perm(vector<int>&v, vector<int>&num, int n)
{
	int i;
	
	if(n==0)
	{
		for(i=0; i<v.size(); ++i)
			printf("%d ",v[i]);
		printf("\n");
	}
	
	else
	{
		for(i=0; i<num.size(); ++i)
		{
			if(num[i]==0)
			{
				v.push_back(i+1);
				num[i]=1;
				perm(v, num, n-1);
				v.pop_back();
				num[i]=0;
			}

			else
				continue;
		}
	}
}

int main(void)
{
	int n;
	vector<int> v;
	
	scanf("%d",&n);
	vector<int> num(n);
	
	perm(v, num, n);
}
