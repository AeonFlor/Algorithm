h, m = map(int,input().split())

m += 15
if m > 60:
	m -= 60
else:
	h -= 1
	if h < 0:
		h = 23

print(h,m)