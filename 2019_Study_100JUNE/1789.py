s = int(input())
cnt = 0

for i in range(1,s):
	s -= i
	if s < 0 :
		break
	cnt += 1
print(cnt)