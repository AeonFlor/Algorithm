n, k = map(int,input().split())
nation = [list(map(int,input().split())) for i in '_'*n]
score = {}

for i in range(n):
	score[i+1]=(nation[i][1]*10000+nation[i][2]*100+nation[i][3])

print(score)

# idea 1: 인덱스 길게 받아서 점핑.
# idea 2: 2차원 배열 column 을 통해 비교.
# -> max()

#<map object at 0x10145fa90> 이런 거 뜨면 map()을 list() 로 감싸자.