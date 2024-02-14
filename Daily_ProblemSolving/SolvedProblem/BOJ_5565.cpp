#include <iostream>

int main(void)
{
	int money, price;
	
	scanf("%d",&money);
	
	for(int i=0; i<9; ++i)
	{
		scanf("%d",&price);
		money-=price;
	}
	
	printf("%d",money);
}
