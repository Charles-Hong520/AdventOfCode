from copy import copy
from collections import defaultdict 
import itertools
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
order = "J23456789TQKA"
hd = defaultdict(int)


def bestJRank(hand):
	dic = defaultdict(int)
	for card in hand:
		dic[card] += 1
	r = rank.index(sorted(list(dic.values())))
	j = dic['J']
	if j > 0:
		jcount = dic['J']
		del dic['J']
		result = ["".join(i) for i in itertools.combinations_with_replacement(order, jcount)]
		for js in result:
			tmpdic = copy(dic)
			for card in js:
				tmpdic[card] += 1
			r = min(r,rank.index(sorted(list(tmpdic.values()))))
	return r



bestJRank("AJJJ2")



for line in file:
	hand, val = line.strip().split()
	r = bestJRank(hand)
	ch = [r] + [-order.index(num) for num in hand] + [int(val)]
	l.append(ch)
l.sort()
for i, elem in enumerate(l):
	sum += (len(l)-i) * l[i][-1]

print(sorted(l))
print(sum)