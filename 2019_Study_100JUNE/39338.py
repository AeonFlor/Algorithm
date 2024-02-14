score = int(input())
grade_dict = {10 : 'A', 9 : 'A', 8 : 'B', 7 : 'C', 6 : 'D'}

if score>100 or score<0:
	pass
elif score//10 in grade_dict.keys():
	print(grade_dict.get(score//10))
else:
	print('F')
