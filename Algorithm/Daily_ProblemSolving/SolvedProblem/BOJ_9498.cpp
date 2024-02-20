#include <iostream>

using namespace std;

int main(void)
{
	int input;
	char grad[11] = {'F','F','F','F','F','F','D','C','B','A','A'};
	
	scanf("%d",&input);
	printf("%c",grad[input/10]);
}
