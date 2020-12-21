#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, i, k, ans=0;
	
	cin>>N;
	
	int *A = new int[N];
	int *result = new int[N];
	
	for(i=0; i<N; ++i)
		cin>>A[i];
	
	for(k=0; k<N; ++k)
	{
		result[k] = A[k];
		
		for(i=0; i<k; ++i)
		{
			if(A[i] < A[k])
				result[k] = max(result[k], result[i]+A[k]);
		}
		
		ans = max(ans, result[k]);
	}
	
	cout<<ans<<'\n';
	
	delete A;
	delete result;
}
