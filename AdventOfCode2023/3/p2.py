from collections import defaultdict 
import re
file = open('input.txt', 'r')
sum = 0
pattern = r'\d+'
i = 0

nums = []
mat = []
for line in file:
	line = ''.join(line.strip())
	mat.append("."+line+".")
	matches = re.finditer(pattern,line) 
	for match in matches:
		num,l,r = match.group(),match.start(),match.end()	
		nums.append([num, i, l+1, r+1])	
	i += 1
as_dict = defaultdict(list)
pattern = r'\*'
for set in nums:
	num,i,l,r = set
	b1,b2,b3,b4 = [None]*4
	if i > 0:
		b1 = re.finditer(pattern, mat[i-1][l-1:r+1])
	if i < len(mat)-1:
		b2 = re.finditer(pattern, mat[i+1][l-1:r+1])
	b3 = re.finditer(pattern, mat[i][r:r+1])
	b4 = re.finditer(pattern, mat[i][l-1:l])
	num = int(num)
	if b1 is not None:
		for match in b1:
			as_dict[(i-1,match.start()+l-1)] += [num]
	if b2 is not None:
		for match in b2:
			as_dict[(i+1,match.start()+l-1)] += [num]
	if b3 is not None:
		for match in b3:
			as_dict[(i, match.start()+r)] += [num]
	if b4 is not None:
		for match in b4:
			as_dict[(i, match.start()+l-1)] += [num]

for key,val in as_dict.items():
	if len(val) == 2:
		sum += val[0] * val[1]

print(sum)