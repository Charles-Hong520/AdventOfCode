import re, numpy as np
file = open('input.txt', 'r')

times = int(''.join(file.readline().split()[1:]))
dists = int(''.join(file.readline().split()[1:]))



ans = 0
# dist = (time-x)x

for j in range(times):
	dist = (times - j)*j
	if dist > dists:
		ans+=1

print(ans)