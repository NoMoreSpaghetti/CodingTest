def solution(n, r):
    ans = 1
    mul_val = n + r - 1
    for i in range(1, n):
        ans *= mul_val
        ans //= i
        mul_val -= 1

    return ans


n, m, r = map(int, input().split())

r -= n * m

if r < 0:
    print(0)
else:
    print(solution(n, r))
