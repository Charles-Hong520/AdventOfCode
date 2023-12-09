# import re, numpy as np
file = open('input.txt', 'r')

sum  = 0
def allzeros(arr):
	for num in arr:
		if num!=0: return False
	return True
for line in file:
	line = [int(num) for num in line.strip().split()]
	diff = [line[i]-line[i-1] for i in range(1,len(line))]
	l = [line,diff]
	while not allzeros(l[-1]):
		diff = [l[-1][i]-l[-1][i-1] for i in range(1,len(l[-1]))]
		l.append(diff)
	for i in range(len(l)-2,-1,-1):
		l[i].insert(0,l[i][0]-l[i+1][0])
	sum += (l[0][0])
print(sum)
