check_data = [0,1,2,3,4,5,6,7,8,9]
count_data = [0,0,0,0,0,0,0,0,0,0]
result = 1

for i in range(3):
	result *= int(input())

def num_check(n):
	for i in check_data:
		if n == i:
			count_data[int(i)] += 1
			continue

while result != 0:
	num_check(result%10)
	result //= 10

for i in count_data:
	print(i)