for _ in "_"*int(input()):
	tg	= 0
	tcc = 0
	for _ in "_"*int(input()):
		ti, gi = map(float,input().split())
		tcc += ti
		tg += ti*gi
	print(int(tcc),round(tg/tcc,1))