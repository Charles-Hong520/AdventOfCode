import re, numpy as np
file = open('input.txt', 'r')
line = file.readline().strip().split(":")[1]
seeds = [int(num) for num in (line.strip().split())]
graph = [[] for i in range(7)]

file.readline()

i = 0
cnt = 2
for line in file:
	line = line.strip()
	if line=="":
		i+=1
	elif line[-1]!=':':
	# src, dest, range
		line = [int(num) for num in line.split()]
		graph[i].append(line)
ans = 1e9
for seed in seeds:
	currseed = seed
	for map in graph:
		inrange = False
		for ranges in map:
			dst,src,off = ranges
			if currseed >= src and currseed < src+off:
				inrange = True
				currseed += dst-src
				break

	ans = min(ans,currseed)
print(ans)