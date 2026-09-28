def BubbleSort(A):
    over = False
    i = 0

    while not over:
        over = True
        for j in range(len(A) - 1, i, -1):
            if A[j] > A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]
                over = False
        i += 1
    return A