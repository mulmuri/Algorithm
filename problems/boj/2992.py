import itertools

x = input()

permutation = list(itertools.permutations(x))

ans = 999999

for v in permutation:
  num = int(''.join(v))
  if num > int(x):
    ans = max(ans, num)
  
if ans == 999999:
  print(0)
else:
  print(ans)