s=[]
ave = 0

for i in range(5):
	s.append(int(input()))
	if s[i] < 40 :
		s[i] = 40
	ave += s[i]

print(ave//5)

# 런타임 에러나면 입력 형식 잘 살피자.
# short coding : print(eval("+max(8,int(input())//5)"*5))