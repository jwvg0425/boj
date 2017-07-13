n = int(input())
fibos = [0,1]
for k in range(2, n+1):
    fibos.append(fibos[k-1] + fibos[k-2])

print(fibos[n])