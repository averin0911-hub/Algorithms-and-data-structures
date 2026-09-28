def merge_sort(arr: list, size: int):
    if len(arr) <= 1:
        return arr

    med = size // 2
    left = merge_sort(arr[:med], len(arr[:med]))
    right = merge_sort(arr[med:], len(arr[med:]))
    return merge(left, right)


def merge(left, right):
    result = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result += [left[i]]
            i += 1
        else:
            result += [right[j]]
            j += 1

    if not(i < len(left)):
        result += right[j:]
    else:
        result += left[i:]
    return result


size = int(input())
list = list(map(int, input().split()))
print(*merge_sort(list, size))


