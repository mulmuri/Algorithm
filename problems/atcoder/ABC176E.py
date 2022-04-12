H,W,M = map(int,input().split())
Hinx = [0 for _ in range(H+1)]
Winx = [0 for _ in range(W+1)]
isExist = []
for i in range(M):
    h,w = map(int,input().split())
    Hinx[h] += 1
    Winx[w] += 1
    isExist.append((h,w))

HMinx = []
WMinx = []
Hmax = max(Hinx)
Wmax = max(Winx)
ans = Hmax + Wmax

isExist = set(isExist)
for i in range(1,H+1):
    if Hinx[i] == Hmax:
        HMinx.append(i)
for i in range(1,W+1):
    if Winx[i] == Wmax:
        WMinx.append(i)

cross = 0
not_cross = 0

flag = True
for i in HMinx:
    for j in WMinx:
        if (i,j) not in isExist:
            flag = False
            break
    if flag == False:
        break
if flag == False:
    print(ans)
else:
    print(ans-1)
