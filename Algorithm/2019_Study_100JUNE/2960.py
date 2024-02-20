n, k = map(int,input().split())
l = [i for i in range(2,n+1)]
while k>0:
	p = min(l)
	for i in range(1,max(l)//p+1):
		rm = p*i
		if rm in l:
			l.remove(rm)
			k -= 1
			if k == 0:
				break

print(rm)