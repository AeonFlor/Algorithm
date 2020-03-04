#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
	int side[3];
	int long_side;
	
	do
	{
		scanf("%d %d %d",&side[0],&side[1],&side[2]);
		sort(side,side+3);
		
		if(!side[2])
			break;
		
		if(pow(side[0],2)+pow(side[1],2)==pow(side[2],2))
			printf("right\n");
		else
			printf("wrong\n");
		
	}while(side[0]+side[1]+side[2]);
}
