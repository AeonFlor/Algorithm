#include <iostream>

using namespace std;

int main(void)
{
	int x, y, sum=-1;
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	string dow[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	
	scanf("%d %d",&x,&y);
	
	for(int i=0; i<x-1; ++i)
		sum+=days[i];
	
	sum+=y;
	
	printf("%s",dow[sum%7].c_str());
	
}
