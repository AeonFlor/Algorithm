
g = [[0,0,0,0,0],[0,0,0,0,0]]

for i in range(8):
	s = int(input())
	m = min(g[1])
	if m < s:
		g[0][g[1].index(m)] = i+1
		g[1][g[1].index(m)] = s

g[0].sort()
print(sum(g[1]))
for i in range(5):
	print(g[0][i], end =' ')
'''
import sys
input = sys.stdin.readline
score = [int(input()) for _ in range(8)]
print(score)
final = sorted(score)[::-1][:5]
print(final)
# [::] 를 사용할 시 오름차순으로 정렬되고 [::-1] 를 사용할 시 내림차순으로 정렬된다.
'''
