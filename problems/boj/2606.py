from collections import deque


V = int(input())
E = int(input())

adj = [[] for _ in range(V+1)]
visited = [False for _ in range(V+1)]
queue = deque()

for _ in range(E):
  A, B = map(int, input().split())



def BFS(S):
  queue.append(S)
  visited[S] = True
  
  while len(queue) != 0:
    ths = queue.popleft()
    for nxt in adj[ths]:
      if not visited[nxt]:
        visited[nxt] = True
        queue.append(nxt)

BFS(1)

