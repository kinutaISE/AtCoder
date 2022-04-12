from numpy.linalg import solve

data = input().split()
N = int(data[0])
M = int(data[1])

str_a = input().split()
a = [ int(s) for s in str_a ]
str_c = input().split()
c = [ int(s) for s in str_c ]

left = [
        [ 0 if j > i else a[i - j] for j in range(M) ]
    for i in range(N + M) ]

print( solve(left, c) )
