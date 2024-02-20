weight = int(input())

share_5 = weight // 5
share_3 = weight // 3
cnt_env = 0

for i in range(share_3+1):
	for j in range(share_5+1):
		if weight - i*3 - j*5 == 0 :
			cnt_env = j+i
			print(cnt_env)
			break
	if cnt_env > 0:
		break

if cnt_env == 0 :
	print('-1')