'''
l = [int(input()) for _ in range(5)]
X = l[0] * l[4]
if l[4]-l[2] > 0 :
	Y = l[1] + (l[4]-l[2])*l[3]
else :
	Y = l[1]
print(min(X,Y))
'''
l = [int(input()) for _ in range(5)]
if l[4]-l[2] > 0 :
	Y = l[1] + (l[4]-l[2])*l[3]
else :
	Y = l[1]
print(min(l[0]*l[4],Y))