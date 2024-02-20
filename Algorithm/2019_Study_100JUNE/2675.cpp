#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	int t, r;
	string s; // string 으로 하면 계속 뒤가 잘린다.
	char *str;

	cin>>t;

	for(int i=0; i<t; i++)
	{
		cin>>r;
		cin>>s;
		str= new char[r];

		for(int j=0; j<s.length()*r; j+=r)
		{
			for(int k=0; k<r; k++)
				str[k]=s[j];
			cout<<"STR : "<<str<<endl;
			s.replace(j,j+1,str);
			cout<<"S : "<<s<<endl;
		}

		cout<<s<<endl;
		delete[] str;
	}

	return 0;
}

// 왜 계속 반복 돌지?