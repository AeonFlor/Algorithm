#include <iostream>
 
using namespace std;
 
int n, res;
 
void checkCount(int key)
{
	int tmp = key - 1 + n/key - 1;
	
	if(n%key)
		++tmp;
	
	if(res < tmp)
		return;
	
	res = tmp;
	
	if(key == n)
		return;
	
	checkCount(key+1);
}
 
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int t;
	
	cin>>t;
	
	while(t--)
	{
		res=1000000001;
		
		cin>>n;
		
		checkCount(1);
		
		cout<<res<<'\n';
	}
}
