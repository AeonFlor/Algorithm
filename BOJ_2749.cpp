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
	
	for(int i=0; i<=cur; ++i)
	{
		res[i]+=bef[i];
		
		if(i==cur && res[i]>9)
		{
			res.push_back(res[i]/10);
			res[i]%=10;
			++cur;
			break;
		}
		
		else if(res[i]>9)
		{
			res[i+1]+=res[i]/10;
			res[i]%=10;
		}
	}
	
	bef.clear();
	bef = temp;
	
	if(--n==0)
	{
		cur=(cur>5)?5:cur;
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
