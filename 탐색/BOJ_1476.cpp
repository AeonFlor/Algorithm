#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> year(3);
	vector<int> result(3);
	int flag=0;
	
	for(int i=0; i<3; ++i)
		scanf("%d",&result[i]);

	while(year!=result)
	{
		if(++year[0]>15)
			year[0]=1;
		if(++year[1]>28)
			year[1]=1;
		if(++year[2]>19)
			year[2]=1;
		++flag;
	}
	
	printf("%d",flag);
}
