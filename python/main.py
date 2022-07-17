geta = 1000_000_000_000_000_000_00
X, A, D, N = map(int, input().split())
A += geta
X += geta

min_v = min(A, A + (N - 1) * D)
max_v = max(A, A + (N - 1) * D)

if X <= min_v:
    print(min_v - X)
    exit(0)
if max_v <= X:
    print(X - max_v)
    exit(0)

X -= A
X %= D

print(min(X, D - X))