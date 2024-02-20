'''
l = []

for i in range(100):
	msg = input()
	if msg == '' or len(msg)>100:
		break;
	l.append(msg)

for i in l:
	print(i)
'''

while True:
	try:
		print(input())
	except EOFError:
		break
'''
for _ in range(100):
	s = input()
	if s == '':
		break
	print(s)
'''