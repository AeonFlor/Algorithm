#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> num;
	int input;
	
	for(int i=0; i<10; ++i)
	{
		cin>>input;
		num.push_back(input%42);
	}
	
	sort(num.begin(),num.end());
	num.erase(unique(num.begin(),num.end()),num.end());
	
	cout<<num.size()<<'\n';
	
	return 0;
}
