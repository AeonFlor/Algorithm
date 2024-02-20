input_data = int(input())

for i in range(31):
	if input_data%2 != 1 or input_data == 1:
		if input_data == 1:
			print('1')
			break
		input_data//=2

	else:
		print('0')
		break
