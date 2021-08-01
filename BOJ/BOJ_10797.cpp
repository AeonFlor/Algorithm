#include <iostream>

int main(void)
{
	int violation,plate,cnt=0;
	
	scanf("%d",&violation);
	
	for(int i=0; i<5; ++i)
	{
		scanf("%d",&plate);
		if(violation==plate)
			cnt++;
	}
	
	printf("%d",cnt);
