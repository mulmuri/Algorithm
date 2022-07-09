import math

x,y,degree = map(float, input().split())

rad = degree * (math.pi / 180.0)
nx = math.cos(rad)*x - math.sin(rad)*y
ny = math.sin(rad)*x + math.cos(rad)*y

print(nx, ny)