#include <iostream>

using namespace std;

struct crop
{
	int adj_n=0;
	bool planted=false;
};

crop field[52][52];
int dx[5] = {0,0,0,1,-1};
int dy[5] = {0,1,-1,0,0};
int M,N;

void print_field()
{
	cout<<"============================\n";
	for(int j=1; j<N+1; ++j)
	{
		for(int k=1; k<M+1; ++k)
			cout<<field[k][j].adj_n<<" ";
		cout<<'\n';
	}
}

void erase_crop(int x, int y)
{
	int ax,ay;
		
	for(int i=0; i<5; ++i)
	{
		ax = x+dx[i];
		ay = y+dy[i];
		
		if(field[ax][ay].planted) // 여기서 검사하는데 기존에 false 라고 해놨으니 원래 있던 부분이 감소되지 않았던 것이다. 당연한거지만 앞으로 값이 변해야 하는데 변하지 않는다면 변하게 하는 부분을 확인하자. 
		{
			--field[ax][ay+1].adj_n;
			--field[ax][ay-1].adj_n;
			--field[ax+1][ay].adj_n;
			--field[ax-1][ay].adj_n;
			field[ax][ay].adj_n=0;
			field[ax][ay].planted = false;
		}
	}
	
	field[x][y].adj_n=0;
}

int main(void)
{
	int T, K, x, y, ans;
	
	cin>>T;
	
	for(int i=0; i<T; ++i)
	{
		ans = 0;
		
		cin>>M>>N>>K;
		
		for(int j=0; j<K; ++j)
		{
			cin>>x>>y;
			
			field[x+1][y+1].planted = true;
			++field[x+1][y+1].adj_n;
			++field[x][y+1].adj_n;
			++field[x+1][y].adj_n;
			++field[x+2][y+1].adj_n;
			++field[x+1][y+2].adj_n;
		}
		
		for(int j=5; j>0; --j)
			for(int k=1; k<N+1; ++k)
				for(int l=1; l<M+1; ++l)
					if(field[l][k].adj_n==j)
					{
						erase_crop(l,k);
						++ans;
						print_field();
					}
		
		cout<<ans<<'\n';
	}
}
