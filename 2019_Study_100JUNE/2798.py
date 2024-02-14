n,m=map(int,input().split())
l = list(map(int,input().split()))
d=0

for i in l[:n]:
	l2 = l[:n]
	l2.remove(i)
	for j in l2[:n-1]:
		l3 = l2[:n-1]
		l3.remove(j)
		for k in l3[:n-2]:
			t=i+j+k
			if(t<=m):
				d= t if m-d>m-t else d
print(d)
'''
n,m=map(int,input().split())
d=0
l = list(map(int,input().split()))

for i in l:
	l2 = l[:]
	l2.remove(i)
	for j in l2:
		l3 = l2[:]
		l3.remove(j)
		for k in l3:
			t=i+j+k
			if(t<=m):
				d= t if m-d>m-t else d
print(d)
'''