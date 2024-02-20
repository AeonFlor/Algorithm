l=[]
n = int(input())
for _ in "_"*n:
	l.append(list(map(int,input().split())))
for i in range(n):
	for j in range(4):
		l[i][j]+=l[i][j+4]
	l[i][0] = max(l[i][0],1)
	l[i][1] = max(l[i][1],1)
	l[i][2] = max(l[i][2],0)
	print(l[i][0]+l[i][1]*5+l[i][2]*2+l[i][3]*2)