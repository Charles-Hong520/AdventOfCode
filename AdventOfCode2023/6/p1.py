import re, numpy as np
file = open('input.txt', 'r')

times = [int(num) for num in file.readline().split()[1:]]
dists = [int(num) for num in file.readline().split()[1:]]

ans = 1
# dist = (time-x)x

for i in range(len(times)):
	ways = 0 
	for j in range(times[i]):
		dist = (times[i] - j)*j
		if dist > dists[i]:
			ways+=1
	ans *= ways

print(ans)