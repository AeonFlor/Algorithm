#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,max=0,grd;
	float ans;
	vector<float> grade;
	
	cin>>n;
	
	for(int i=0; i<n; ++i)
	{
		cin>>grd;
		grade.push_back(grd);
		max = (max>grd)?max:grd;
	}
	
	for(int i=0; i<n; ++i)
	{
		grade[i]/=max;
		ans+=grade[i];
	}
	
	cout<<fixed;
	cout.precision(3);
	cout<<ans/n*100<<'\n';
	
	return 0;
}
