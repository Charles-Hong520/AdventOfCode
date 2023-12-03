file = open('input.txt', 'r')
sum = 0
for line in file:
	id, colors = line.strip().split(':')
	id = int(id.strip().split()[1])
	colors = colors.strip().split(';')
	blues, reds, greens = 0, 0, 0
	for set in colors:
		set = set.strip().split(',')
		for twos in set:
			num,color = twos.strip().split()
			num = int(num)
			if(color=="blue"):
				blues = max(blues,num)
			elif color=="red":
				reds = max(reds,num)
			elif color=="green":
				greens = max(greens,num)
	sum += blues*reds*greens
print(sum)