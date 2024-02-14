
l = []

for i in range(5):
	l.append(input())

for i in range(15):
	for j in range(5):
		if len(l[j]) >= i+1:
			print(l[j][i], end='')

'''
print(*eval('input()+" "*15,'*5))
# output: ABCDE                abcde                01234                FGHIJ                fghij  
'''