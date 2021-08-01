#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x,y,w,h,min;
	cin>>x>>y>>w>>h;

	if(x>w/2)
		min=w-x;
	else
		min=x;
	
	if(y>h/2)
		min=(min>h-y)?h-y:min;
	else
		min=(min>y)?y:min;
	
	cout<<min<<'\n';
	
	return 0;
}
