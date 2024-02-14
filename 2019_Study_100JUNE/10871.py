'''
n, x = map(int, input().split())

ans = list(map(int,input().split()))

for i in range(n):
	print(ans,i, n)
	print(type(i))
	if ans[i] >= x:
		del ans[i]
		i-=1 # 이 코드 왜 무시 됨?

print(ans)
'''
'''
python 에서 for 는 list 나 tuple 등을 순회하는 반복문이다.
i 가 int 형이라 해도 다음 i 는 list 에서 가져오기에 소용 없다. 처리는 되지만 사용되지 않는 코드인 것이다.
range(n) 함수를 통해 list 를 만들어준다는 데 python2 에서는 type 이 list 였지만,  3 에서는 type 이 range() 그대로 이다.
그래도 데이터형으로 list 나 tuple 등과 같이 인식되어 사용된다고 한다.
'''

n, x = map(int, input().split())

ans = list(map(int,input().split()))
rm_l = []

for i in range(n):
	if ans[i] >= x:
		rm_l.append(ans[i])

for i in rm_l:
	ans.remove(i)

for i in ans:
	print(i, end=' ')

# 변수 앞에 * 은 몇 개가 들어갈 지 모른다는 의미이다.
# 저장하고 한 번에 출력하는 관점이 아니라, 처리할 때마다 출력하는데 결과는 하나로 출력하는 것과 같이 출력되는 관점.
