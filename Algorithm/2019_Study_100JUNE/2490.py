input_data = []
yut = ['A','B','C','D']
cnt = 0

for i in range(3):
	input_data.extend(list(map(int, input().split())))

for i in range(3):
	j = i * 4

	if input_data[j:j+4].count(0) == 0:
		print('E')
		continue

	print(yut[input_data[j:j+4].count(0)-1])
'''
yut=['D','C','B','A','E']
for _ in range(3): print(yut[sum(map(int,input().replace('\n',"").split(' ')))])
'''
# 아니 바로 출력해도 되는데 왜 혼자 잘못 코딩한 걸 아예 뜯어고치는 거야...