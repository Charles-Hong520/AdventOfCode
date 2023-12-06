# import re, numpy as np, time
# from numba import jit
# file = open('input.txt', 'r')
# line = file.readline().strip().split(":")[1].strip().split()
# seeds = [int(num) for num in line]
# seeds = [[seeds[i],seeds[i+1]] for i in range(len(seeds)//2)]
# graph = [[] for i in range(7)]

# file.readline()

# i = 0
# cnt = 2
# for line in file:
# 	line = line.strip()
# 	if line=="":
# 		i+=1
# 	elif line[-1]!=':':
# 	# src, dest, range
# 		line = [int(num) for num in line.split()]
# 		graph[i].append(line)

# @jit
# def func(seeds, graph):
# 	ans = 1e9
# 	for seed in seeds:
# 		for i in range(seed[1]):
# 			currseed = seed[0]+i
# 			for map in graph:
# 				for ranges in map:
# 					dst = ranges[0] 
# 					src = ranges[1]
# 					off = ranges[2]
# 					if currseed >= src and currseed < src+off:
# 						currseed += dst-src
# 						break
# 			ans = min(ans,currseed)
# 		print(seed[0])
# 	return ans


# seeds = np.array(seeds)
# graph = np.array(graph)
# print(func(seeds,graph))