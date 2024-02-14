#include <stdio.h>

int main(void)
{
	int n, m;
	int cn=1;
	int cm=1;

	scanf("%d",&n);
	scanf("%d",&m);


	for(int i=1;i<=n-1;i++)
	{
		cn = cn * (m-i);
		cm = cm * i
	}
	printf("%d", cn/cms);
}