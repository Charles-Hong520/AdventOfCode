from collections import defaultdict 
file = open('input.txt', 'r')
rank = [
	[5],
	[1,4],
	[2,3],
	[1,1,3],
	[1,2,2],
	[1,1,1,2],
	[1,1,1,1,1]
]
l = []
sum = 0
order = "23456789TJQKA"
hd = defaultdict(int)
for line in file:
	hand, val = line.strip().split()
	dic = defaultdict(int)
	for dig in hand:
		dic[dig] += 1
	r = rank.index(sorted(list(dic.values())))
	ch = [r] + [-order.index(num) for num in hand] + [int(val)]
	l.append(ch)
l.sort()
for i, elem in enumerate(l):
	sum += (len(l)-i) * l[i][-1]

print(sorted(l))
print(sum)