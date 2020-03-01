#include <iostream>

using namespace std;

int main(void)
{
	int N[4];
	char res[5]={'D','C','B','A','E'};
	
	for(int i=0; i<3; ++i)
	{
		scanf("%d %d %d %d",&N[0],&N[1],&N[2],&N[3]);
		printf("%c\n",res[N[0]+N[1]+N[2]+N[3]]);
	}
}
