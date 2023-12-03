d = {
	"one":1,
	"two":2,
	"three":3,
	"four":4,
	"five":5,
	"six":6,
	"seven":7,
	"eight":8,
	"nine":9,
	"1":1,
	"2":2,
	"3":3,
	"4":4,
	"5":5,
	"6":6,
	"7":7,
	"8":8,
	"9":9,
}
sum = 0
with open('i2.txt', 'r') as file:
	for ll in file:		
		ll = ll.strip()
		line = ''.join(ll)
		i = 0
		while(i < len(line)):	
			for (word, num) in d.items():
				if(line[i:].startswith(word)):
					sum += num * 10
					i = len(line)
					break
			i += 1

		line = line[::-1]
		i = 0
		while(i < len(line)):	
			for (word, num) in d.items():
				if(line[i:].startswith(word[::-1])):
					sum += num
					i = len(line)
					break
			i += 1
		


print(sum)