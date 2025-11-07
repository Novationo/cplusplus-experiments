# recursion example in python
def recursiveSum(n):
    if n > 1:
        return n + recursiveSum(n - 1)
    else:
        return n


num = recursiveSum(5)

print(num)
