#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int num[9];
	int ans_idx=0;
	
	for(int i=0; i<9; ++i)
	{
		cin>>num[i];
		if(num[ans_idx]<num[i])
			ans_idx=i;
	}
	
	cout<<num[ans_idx]<<'\n'<<ans_idx+1<<'\n';
	
	return 0;
}
