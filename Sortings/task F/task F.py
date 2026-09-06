import random
import time

def quick_sort1(A):
    if len(A) < 2:
        return A

    choice = random.choice(A)
    left = []
    eq = []
    right = []

    for i in range(len(A)):
        if A[i] < choice:
            left += [A[i]]
        elif A[i] == choice:
            eq += [A[i]]
        else:
            right += [A[i]]


    return quick_sort1(left) + eq + quick_sort1(right)

def quick_sort(A):
    if len(A) < 2:
        return A

    choice = random.choice(A)
    left = [el for el in A if el < choice]
    medium = [el for el in A if el == choice]
    right = [el for el in A if el > choice]

    return quick_sort(left) + medium + quick_sort(right)



random.seed(1)
A1 = [random.randint(0, 10000) for el in range(1000)]
A2 = A1.copy()

t1 = time.time()
quick_sort1(A1)
t2 = time.time()
print(t2 - t1)


t1 = time.time()
quick_sort(A1)
t2 = time.time()
print(t2 - t1)