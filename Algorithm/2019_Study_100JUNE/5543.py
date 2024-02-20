l = [0, 0, 0, 0, 0]

for i in range(5) :
	l[i] = int(input())
	
print(min(l[0:3])+min(l[3:5])-50)