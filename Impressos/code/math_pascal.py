from sys import stdin

valores = []

fatorial = [1]

for i in range(1, 33):
	fatorial.append(fatorial[-1] * i)

def calc(n, x, produto, anterior):
	if(n == 0):
		valores.append(fatorial[h - 1] // produto)
		return
		
	if(x == 0):
		return
		
	for i in range(0, min(anterior + 1, n + 1)):
		calc(n - i, x - 1, produto * fatorial[i], i)

for line in stdin:
	d, h = map(int, line.split(' '))
	
	calc(h - 1, d, 1, h)

	valores = list(set(valores))
	valores.sort()

	for x in valores:
		print(x)
		
	valores = []
