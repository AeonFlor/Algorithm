s=0
l=[int(input())for _ in '_'*10]
for i in range(1,11):
	s=s if abs(100-s)<abs(100-sum(l[:i])) else sum(l[:i])
print(s)