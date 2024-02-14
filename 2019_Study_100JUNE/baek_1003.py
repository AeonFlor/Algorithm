'''
count_0, count_1 = 0, 0
ans_arr = []
count = 0

def fibonacci(n):
	global count_0, count_1

	if n==0:
		count_0+=1
		return 0
	elif n==1:
		count_1+=1
		return 1
	else:
		return fibonacci(n-2)+fibonacci(n-1)

T = int(input())

for i in range(T):
	input_n = int(input())
	fibonacci(input_n)
	ans_arr[count:count+1] = count_0, count_1
	count+=2
	count_0, count_1 = 0, 0

for i in range(T):
	print(ans_arr[i*2],ans_arr[i*2+1])
'''

# 시간 초과로 실패 , 구현에만 의의를 둠.

count_0, count_1 = 0, 0
ans_arr = []
count = 0

def fibonacci(n):
	global count_0, count_1

	if n==0:
		count_0+=1
	elif n==1:
		count_1+=1
	else:
		return fibonacci(n-2)+fibonacci(n-1)

T = int(input())

for i in range(T):
	input_n = int(input())
	fibonacci(input_n)
	ans_arr[count:count+1] = count_0, count_1
	count+=2
	count_0, count_1 = 0, 0

for i in range(T):
	print(ans_arr[i*2],ans_arr[i*2+1])
