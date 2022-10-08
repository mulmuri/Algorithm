import sys
input = sys.stdin.readline

def parametric(k):
    global ans
    ret = psum[max(0,k-a)] + (psum[k] - psum[max(0,k-a)])//2
    if ret > b:
        return False
    ans = max(ans,k)
    return True
    
def binarysearch(left,right):
    if left == right:
        return
    mid = (left+right)//2
    
    if parametric(mid):
        binarysearch(mid+1,right)
    else:
        binarysearch(left,mid)
    
    
n,b,a = map(int,input().split())
lst = list(map(int,input().split()))

lst.sort()
psum = [0]

for i in range(n):
    psum.append(psum[-1]+lst[i])
    
ans = 0
binarysearch(0,n+1)
print(ans)