i = lambda:int(input())
n = i()
if sum(i() for _ in range(n)) > n//2 :
	print('Junhee is cute!')
else :
	print('Junhee is not cute!')