from functools import cmp_to_key
from sys import stdin

def compare(a, b):
    if a + b < b + a:
        return 1
    else:
        return -1

ls = [line.rstrip() for line in stdin]

ls = sorted(ls, key=cmp_to_key(compare))
print("".join(ls))
