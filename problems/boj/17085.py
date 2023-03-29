n, m = map(int, input().split())
a = [list(input()) for row in range(n)]

# 본인을 기준으로 위, 아래, 오른쪽, 왼쪽
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

# 크기와 위치 정보 입력
board = []

# 만들어 질 수 있는 모든 십자가 탐색
for x in range(n):
    for y in range(m):
        if a[x][y] == '#':
# size 0부터 저장하면서 size를 늘림
#            size = 0
#            while 0 <= x-size and x+size < n and 0 <= y-size \
#                    and y+size < m and a[x-size][y] == a[x+size][y] \
#                    == a[x][y-size] == a[x][y+size] == "#":
#                board.append([size, x, y])
#                size += 1

# 최대 size 정하고 size를 하나씩 줄여나가며 저장
            size = 0
            while 0 <= x - size and x + size < n and 0 <= y - size \
                    and y + size < m and a[x - size][y] == a[x + size][y] \
                    == a[x][y - size] == a[x][y + size] == "#":
                size += 1
            while size:  # 작은 경우끼리 곱하는게 더 클 수도 있으므로 고려해야함
                board.append([size, x, y])
                size -= 1

# max 구하기
result = 0
for i in range(len(board)-1):
    for j in range(i+1, len(board)):
        flag = True
        score = (1+(board[i][0]-1)*4) * (1+(board[j][0]-1)*4)
        if score > result:
            b = [[0] * m for _ in range(n)]
            # for문을 각 size만큼 돌림
            # 겹치는지 확인
            for k in range(board[i][0]):
                for p in range(4):
                    x1 = board[i][1]+dx[p]*k
                    y1 = board[i][2]+dy[p]*k
                    if 0 <= x1 <= n and 0 <= 0 <= y1 <= m:
                        b[x1][y1] = 1
            for k in range(board[j][0]):
                for p in range(4):
                    x2 = board[j][1] + dx[p] * k
                    y2 = board[j][2] + dy[p] * k
                    if 0 <= x2 <= n and 0 <= 0 <= y2 <= m and b[x2][y2] == 1:
                        flag = False
            if flag:
                result = score
print(result)