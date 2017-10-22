import bisect

fib = [1, 2]

for i in range(2, 1000):
    fib.append(fib[i-1] + fib[i - 2])

a, b = map(int, input().split(' '))

while a != 0 or b != 0:
    lb = bisect.bisect_left(fib, a)
    up = bisect.bisect_right(fib, b)

    print(up - lb)

    a, b = map(int, input().split(' '))