import re
file = open('input.txt', 'r')
sum = 0
for line in file:
	lottery, pile = line.strip().split(':')[1].strip().split('|')
	lottery = lottery.strip().split()
	lottery = set(lottery)
	pile = pile.strip().split()
	cnt = 0
	for num in pile:
		if num in lottery:
			cnt += 1
	sum += 0 if cnt==0 else int(2)**(cnt-1)
print(sum)
	