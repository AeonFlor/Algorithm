#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int ans=0;

int countInsert(int start, int end)
{
	bool check = false;
	
	for(int i=start; i<end; ++i)
	{
		long long sum = 0LL;
		
		for(int j=i; j<end; ++j)
		{
			sum += arr[j];
			
			if(sum == 0)
			{
				check = true;
				
				if(!countInsert(i+1,j))
					++ans;
				
				i = j-1;
				
				break;
			}
		}
	}
	
	return check;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, input;
	
	cin>>n;
	
	for(int i=0; i<n; ++i)
	{
		cin>>input;
		arr.push_back(input);
	}
	
	countInsert(0, n);
	
	cout<<ans<<'\n';
}
