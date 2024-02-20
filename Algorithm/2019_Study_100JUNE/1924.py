BC2007_day=[0,31,28,31,30,31,30,31,31,30,31,30,31]
BC2007_dow = ['MON','TUE','WED','THU','FRI','SAT','SUN']
day = 0

x , y = map(int, input().split())

for i in range(x):
	day += BC2007_day[i]

day += y-1

print(BC2007_dow[day%7])

'''
BC2007_day = [0,3,3,6,1,4,6,2,5,0,3,5]
BC2007_dow = ['MON','TUE','WED','THU','FRI','SAT','SUN']
# 1월 1일 월요일

x , y = map(int, input().split())

print(BC2007_dow[BC2007_day[x-1]+(y-1)%7-7])
'''

# l[::] 같은 형식에서 처음은 시작 인덱스, 두번쨰는 끝 인덱스, 세번째는 step size 라고 한다.