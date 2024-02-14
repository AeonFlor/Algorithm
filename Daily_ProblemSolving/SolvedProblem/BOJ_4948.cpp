#include <iostream>

int main(void)
{
	int n=1,cnt;
	
	int arr[246912];
	std::fill_n(arr,246912,1);
	// 배열 index 랑 실제 수랑 맞추기 위해서 0을 1 로 설정.
	arr[0]=0;
	arr[1]=0;
	
	for(int i=2; i<246911; ++i)
	{
		if(arr[i]==0)
			continue;
			
		for(int j=i+i; j<=246912; j+=i)
				arr[j]=0;
	}
	
	while(n!=0)
	{
		scanf("%d",&n);
		
		cnt=0;
		
		for(int i=n+1; i<=2*n; ++i)
		{
			if(arr[i]==1)
				cnt++;
		}
		
		if(n!=0)
			printf("%d\n",cnt);
	}
}

// 흠.. for 문 똑바로 안 살피고 실수를 많이 했다.
