import math

def brute(p, c=float("inf")): #thuật toán brutr
    if len(p) < 2: return c
    else:
        f = p[0]
        del p[0]
        return brute(p, min([c, min([dist(f, x) for x in p])]))
        ## combine the first element of p with every other, in a recursive call.

def divide(p): #chia tập hợp điểm thành 2 tập con có kích thước gần bằng nhau
    if len(p) < 4: ## |p| < 4, 
        return brute(p)
    else:
        mid = len(p)//2;
        minimum = min([divide(p[:mid]), divide(p[mid:])]) # computes the answers for the closest points strictly in only one of the regions.
        near_mid = list(filter(lambda point: point.x > p[mid].x - minimum and point.x < p[mid].x + minimum, p))
        # above, I have used the Python filter function to determine which of the points in P are near the line we found.
        # that is, if the candidate distance is called minimum, and the x of line a is xa, points whose x is in the interval [xa - minimum; xa + minimum]
        return min([brute(near_mid), minimum])

class point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def sqr(x):
    return x*x

def dist(a, b):
    return sqr(a.x - b.x) + sqr(a.y - b.y) 

N = int(input("Give the number of points (N): "))
p = []

for i in range(N):
    x, y = [int(x) for x in input("x y: ").split()]
    p.append(point(x, y))

P = sorted(p, key=lambda point: point.x) #sắp xếp các điểm theo toạ độ x


print("%.6f" % math.sqrt(divide(P)))

