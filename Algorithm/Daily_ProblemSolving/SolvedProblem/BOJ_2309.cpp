#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool flag=true;

void check(vector<int>&hgt, vector<int>&res, vector<int>&chk, int total, int n)
{
	int i;
	
	if(flag)
	{
		if(total==0 && res.size()==7)
		{
			for(i=0; i<7; ++i)
				printf("%d\n",res[i]);
			flag=false;
		}

		else if(total>0)
		{
			for(i=n; i<9; ++i)
			{
				if(chk[i]==0)
				{
					res.push_back(hgt[i]);
					chk[i]=1;
					check(hgt,res,chk,total-hgt[i],i+1);
					res.pop_back();
					chk[i]=0;
				}
			}
		}
	}
}

int main(void)
{
	vector<int> height(9);
	vector<int> result;
	vector<int> chk(9);
	int i;
	
	for(i=0; i<9; ++i)
		scanf("%d",&height[i]);
	
	sort(height.begin(),height.end());
	
	check(height,result,chk,100,0);
}
