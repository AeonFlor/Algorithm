'''
ln = []
sn = []

n, m = map(int, input().split())

for _ in range(n):
	ln.append(input())

for _ in range(m):
	dat = input()
	if dat in ln:
		sn.append(dat)

print(len(sn))

for i in range(len(sn)):
	print(sn[i])
'''

'''
리스트 뺴기
'''
'''
카운트 2개인 것 찾기
'''
'''
dic = {}

n, m = map(int, input().split())

for _ in range(n):
	dic[input()]=0

for _ in range(m):
	dat = input()
	if dat in dic :
		dic[dat]=1

# 어떻게 value 가 2 인 값만 filtering 함?
'''

ln = []
sn = []

n, m = map(int, input().split())

for _ in range(n):
	ln.append(input())

for _ in range(m):
	sn.append(input())

# res = list(set(ln)&set(sn)).sort() -> 안 된다. 정렬을 할 뿐 return 하지는 않는다.
res = sorted(list(set(ln)&set(sn)))
print(len(res))
for i in range(len(res)):
	print(res[i])

# 집합 연산자 문제.

