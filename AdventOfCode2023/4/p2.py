import re
file = open('input.txt', 'r')
sum = 0
cards = [1]*210
gamelen = 0
for line in file:
	game = -1 + int(line.strip().split(':')[0].split()[1])
	lottery, pile = line.strip().split(':')[1].strip().split('|')
	lottery = lottery.strip().split()
	lottery = set(lottery)
	pile = pile.strip().split()
	cnt = 0
	for num in pile:
		if num in lottery:
			cnt += 1
	for i in range(cnt):
		cards[game+i+1] += cards[game]
	gamelen += 1

for i in range(gamelen):
	sum += cards[i]
print(sum)
	