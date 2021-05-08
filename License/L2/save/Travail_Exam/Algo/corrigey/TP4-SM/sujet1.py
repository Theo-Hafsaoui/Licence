def power(x, n):
	res = 1
	for i in range(0,n):
		res *= x
	return res

print(power(2,500000))	
