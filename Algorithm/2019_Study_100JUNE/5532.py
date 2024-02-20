e=lambda r,c:(l[r]//l[c]+max(l[r]%l[c]>0,0))
l=[int(input()) for _ in '_'*5]
print(l[0]-max(e(1,3),e(2,4)))
#-25//6 을 하면 4가 나오는 게 아니라 5가 나온다.