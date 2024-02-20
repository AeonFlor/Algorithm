dn = int(input())%10
car = list(map(int, input().split()))
cnt = 0

for i in car :
	if dn == i :
		cnt += 1
print(cnt)