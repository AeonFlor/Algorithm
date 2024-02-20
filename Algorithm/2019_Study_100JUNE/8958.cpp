#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	int n, score_rec, res=0;
	string score;

	cin>>n;

	for(int i=0; i<n; i++)
	{
		cin>>score;
		score_rec=0;
		res=0;

		for(int j=0; j<score.length(); j++)
		{
			if(score[j]=='O')
				res+=(++score_rec);
			else
				score_rec=0;
		}

		cout<<res<<"\n";
	}

	return 0;
}