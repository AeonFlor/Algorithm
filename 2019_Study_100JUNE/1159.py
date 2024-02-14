n = int(input())
l = [input()[0] for _ in "0"*n]
r = []
for i in sorted(list(set(l))):
	if(l.count(i)>4):
		r.append(i)
if len(r)==0:
	print("PREDAJA")
else:
	print(''.join(r))
'''
python 은 문자열 또한 하나의 배열로 인식하여 위의 l list 에서 l[3][0] 과 같이 쓸 수 있다.
인덱싱할 때만 계속 전체 문자열 나옴. ex) l[:][0]
'''