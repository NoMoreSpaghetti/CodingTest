N = int(input())


def binary_search(N):
    left = 0
    right = N
    while left <= right:
        mid = (left + right) // 2
        square_num = mid**2
        if square_num < N:
            left = mid + 1
        elif square_num > N:
            right = mid - 1
        else:
            return mid
    return left


print(binary_search(N))
