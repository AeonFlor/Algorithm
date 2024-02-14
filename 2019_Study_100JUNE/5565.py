i=lambda:int(input())
print(i()-sum(i() for _ in range(9)))

'''
i=lambda:int(input())
t = i()
s = sum(i() for _ in range(9))
print(t-s)
'''

# SyntaxError: unexpected EOF while parsing 나오면 괄호를 잘 살피자.