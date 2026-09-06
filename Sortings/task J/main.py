from functools import cmp_to_key

def compare(a, b):
    return a - b

l = [81, 34, 67, 21, 33, 54, 22, 8]
l = sorted(l, key=cmp_to_key(compare))
print(l)