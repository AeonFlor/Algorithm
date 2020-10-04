#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, input;
	long long tot=0 ,cnt=0;
	
	set<long long> sum;
	
	cin>>n;
	
	sum.insert(0);
	
	for(int i=0; i<n; ++i)
	{
		cin>>input;
		
		tot += input;
		
		if(sum.find(tot) != sum.end())
		{
			sum.clear();
			sum.insert(0);
			tot = input;
			sum.insert(tot);
			++cnt;
		}
		
		else
			sum.insert(tot);
	}
	
	cout<<cnt<<'\n';
}
