'''
while True:
	case = int(input())
	if case == 0 :
		break
	cnt = 0
	for i in range(case+1,case*2+1):
		print('case : '+str(i))
		if ( i % 2 != 0 and i % 3 != 0 and i % 5 != 0 and i % 7 != 0 and i % 11 != 0 and i % 13 != 0) or i in [1,2,3,5,7,11,13] :
			cnt += 1
			print('cnt : '+str(cnt))

	print(cnt)
'''
'''
while True:
	case = int(input())

	if case == 0 :
		break

	elif case in [1,2]:
			cnt = 1

	elif case > 2 : 
		cnt = 0
		for i in range(case+1,case*2+1):
			chk = False
			for j in range(2,i):
				if i % j == 0 :
					chk = True
					break
			if chk == False:
				cnt += 1
	print(cnt)
'''

l = [False, False, True] + [True] * (123454+123456)

for i,b in enumerate(l):
	if b:
		mul = i * 2
		while mul <= 123456*2:
			l[mul] = False
			mul += i

while True :
	n = int(input())
	if n == 0 :
		break
	print(l[n+1:n*2+1].count(True))

# 에라토스테네스의 체

