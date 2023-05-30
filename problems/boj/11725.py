N = int(input())

adj = [[] for _ in range(N+1)]
parent = [0 for _ in range(N+1)]

def DFS(ths, parent):  
  for nxt in adj:
    if nxt != parent:
      DFS(nxt, ths)
      
DFS(1, 0)