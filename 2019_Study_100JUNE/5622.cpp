#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	int alpti[26]={3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
	int time = 0;
	string numch;

	cin>>numch;

	for(int i=0; i<numch.length(); i++)
		time += alpti[numch[i]-65];

	cout<<time<<endl;

	return 0;
}
/* 구사과님 코드 맞게 수정.
#include <iostream>
using namespace std;

int main() {
    string ns[8] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};    
    char s[16] = {};
    int sum = 0;
   
    cin.getline(s, 15);
    
    for(int i=0; s[i]; i++) {
        for(int j=0; j<8; j++) {
            for(int k=0; k<ns[j].size(); k++) {
                if(s[i] == ns[j].at(k)) {
                    sum += j+3;
                }
            }
        }
        
    }
    cout << sum << '\n';
    
    
    return 0;
}
*/