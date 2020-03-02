#include <iostream>

int cng(int n, int cnt)
{
	if(n==0)
		return cnt;
	
	if(n>=500)
		return cng(n-500,++cnt);
	
	if(n>=100)
		return cng(n-100,++cnt);
	
	if(n>=50)
		return cng(n-50,++cnt);
	
	if(n>=10)
		return cng(n-10,++cnt);
	
	if(n>=5)
		return cng(n-5,++cnt);
	
	if(n>=1)
		return cng(n-1,++cnt);
}

int main(void)
{
	int change, count=0;
	
	scanf("%d",&change);
	
	change=1000-change;
	
	printf("%d",cng(change,0));
}
