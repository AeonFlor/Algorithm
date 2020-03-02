#include <iostream>

int main(void)
{
	int burger[3];
	int drink[2];
	int bur_min, dri_min;
	
	scanf("%d %d %d %d %d",&burger[0],&burger[1],&burger[2],&drink[0],&drink[1]);
	
	bur_min=(burger[0]>burger[1])?burger[1]:burger[0];
	bur_min=(bur_min>burger[2])?burger[2]:bur_min;
	dri_min=(drink[0]>drink[1])?drink[1]:drink[0];
	
	printf("%d",bur_min+dri_min-50);
}
