#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string input;
	string mw[8]={"c=","c-","d-","lj","nj","s=","dz=","z="};

	cin>>input;

	for(int i=0; i<8; i++)
		while(input.find(mw[i])!=string::npos)
			input.replace(input.find(mw[i]),mw[i].length(),".");

	cout<<input.length()<<endl;

	return 0;
}
// substr(a,b) 는 a<= x <b 이다.
/* cc== 의 경우 3 word 가 아닌 2 word 로 인식할 수 있기에 폐기. 순차적으로 접근해야 될 것 같음.
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string input;
	int cnt=0,flag=0;
	string mw[8]={"c=","c-","d-","lj","nj","s=","z=","dz="};

	cin>>input;

	while(!input.empty())
	{
		for(int i=0; i<7; i++)
			if(input.find(mw[i])!=string::npos)
			{
				input.erase(input.find(mw[i]),input.find(mw[i])+2);
				cnt++;
			}
		
		if(input.find(mw[7])!=string::npos)
		{
			input.erase(input.find(mw[7]),input.find(mw[7])+3);
			cnt++;
		}

		else
		{
			input.erase(0,1);
			cnt++;
		}
	}

	cout<<cnt<<endl;

	return 0;
}
*/