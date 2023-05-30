from collections import deque



V = 100000
S, K = map(int, input().split())

queue = deque()
visited = [False for _ in range(V+1)]
adj = [[] for _ in range(V+1)]


for i in range(1, 100000):
  continue

def BFS(S):
  queue.append(S)
  visited[S] = True
  
  while (len(queue) != 0):
    ths = queue.popleft()
    for nxt in adj[ths]:
      if not visited[nxt]:
        visited[nxt] = True
        queue.append(nxt)

