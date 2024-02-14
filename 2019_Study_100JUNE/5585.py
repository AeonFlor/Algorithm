n = 1000-int(input())
rc = [500,100,50,10,5,1]
cnt = 0

for i in range(6):
	c=0
	c += n//rc[i]
	n -= rc[i]*c
	cnt += c

print(cnt)