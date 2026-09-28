x = int(input())
arr = [i for i in range(1, x + 1)]

for i in range(2, x):
    arr[i], arr[i // 2] = arr[i // 2], arr[i]

print(*arr)