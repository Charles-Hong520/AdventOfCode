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

pattern = r'[^0-9.]'
for set in nums:
	num,i,l,r = set
	b1,b2,b3,b4 = [None]*4
	if i > 0:
		b1 = re.search(pattern, mat[i-1][l-1:r+1])
	if i < len(mat)-1:
		b2 = re.search(pattern, mat[i+1][l-1:r+1])
	b3 = re.search(pattern, mat[i][r:r+1])
	b4 = re.search(pattern, mat[i][l-1:l])
	
	
	if b1 is None and b2 is None and b3 is None and b4 is None:
		continue
	else:
		sum +=int( num)

print(sum)