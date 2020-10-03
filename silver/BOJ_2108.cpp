#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, input, total=0;
	vector<int> seq;
	
	cin>>N;
	
	for(int i=0; i<N; ++i)
	{
		cin>>input;
		total += input;
		seq.push_back(input);
	}
	
	sort(seq.begin(), seq.end());
	
	int ave = total/N + 0.5;
	
	cout<<ave<<'\n';
	
	cout<<seq[N/2]<<'\n';
	
	vector<int> cnt(N,0);
	
	for(int i=0; i<N; ++i)
	{
		++cnt[seq[i]];
	}
	
	int mode = cnt[0];
	bool trial = false;
	
	// 수로 안 됨. 구현 능력 부진함.
	for(int i=1; i<N; ++i)
	{
		if(cnt[i]>cnt[i-1])
		{
			mode = i;
			trial = false;
		}
		
		else if(cnt[i] == cnt[i-1])
		{
			if(trial)
				mode = i;
			
			else
				trial = true;
		}
			
	}
	
	cout<<mode<<'\n';
	
	cout<<seq[seq.size()-1]-seq[0]<<'\n';
}
