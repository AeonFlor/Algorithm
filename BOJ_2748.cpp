#include <iostream>
#include <vector>

using namespace std;

vector<int> temp;

void fibo(vector<int>&res, vector<int>&bef, int n)
{
	if(res.size()!=bef.size()) bef.push_back(0);
	
	temp.clear();
	temp = res;
	
	int cur = res.size()-1;
	
	for(int i=cur; i>=0; --i)
	{
		printf("BEF BEFORE: %d\n",bef[i]);
		printf("RES BEFORE: %d\n",res[i]);
		printf("n : %d\n",n);
		printf("----------------\n");
	}
	
	for(int i=0; i<=cur; ++i)
	{
		printf("%d : %d(bef) + %d(res) COMPLETE\n",i,bef[i],res[i]); // for checking
		res[i]+=bef[i];
		
		if(i==cur && res[i]>9)
		{
			res.push_back(res[i]/10);
			res[i]%=10;
			++cur;
		}
		
		else if(res[i]>9)
		{
			res[i+1]+=res[i]/10;
			res[i]%=10;
		}
		
		for(int j=cur; j>=0; --j)
		{
			printf("%d",res[j]);
		}
		printf("\n%d/%d----------------\n",i,cur);
	}
	
	bef.clear();
	bef = temp;
	
	if(--n==0)
	{
		for(int i=cur; i>=0; --i)
			printf("%d",res[i]);
	}
	else
		fibo(res, bef, n);
}

int main(void)
{
	int input;
	vector<int> res;
	vector<int> bef;
	
	scanf("%d",&input);
	
	if(input<2) 
	{
		printf("%d",input);
		return 0;
	}
	
	bef.push_back(0);
	res.push_back(1);
	
	fibo(res,bef,input-1);
	
	return 0;
}
