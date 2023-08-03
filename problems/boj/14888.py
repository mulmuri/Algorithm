n = int(input())

arr = list(map(int, input().split()))

operator = list(map(int, input().split()))

maxv = -int(2e10)
minv = int(2e10)

def backtrack(i, result, add, sub, mul, div):
    global maxv, minv

    if i == n:
        maxv = max(maxv, result)
        minv = min(minv, result)
        return
    
    if add != 0:
        backtrack(i+1, result + arr[i], add-1, sub, mul, div)
    
    if sub != 0:
        backtrack(i+1, result - arr[i], add, sub-1, mul, div)
    
    if mul != 0:
        backtrack(i+1, result * arr[i], add, sub, mul-1, div)
    
    if div != 0:
        if result < 0 and arr[0] > 0:
            backtrack(i+1, -(-result // arr[i]), add, sub, mul, div-1)
        else:
            backtrack(i+1, result // arr[i], add, sub, mul, div-1)
    
    
backtrack(1, arr[0], operator[0], operator[1], operator[2], operator[3])

print(maxv)
print(minv)