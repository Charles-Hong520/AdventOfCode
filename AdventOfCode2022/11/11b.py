
from queue import Queue
#functions to make input simpler, taken from https:#codeforces.com/blog/entry/83441 
def inp():
   # convert input to int and return 
   return(int(input()))
def inlt():
   # split input (demarkers whitespace), convert to int, and return list of ints
   return(list(map(int,input().split())))
def insr():
   # remove leading and trailing whitespace and return input (string) 
   return(input().strip())
def invr():
   # convert input to int (delimiter is whitespace) and return map object
   return(map(int,input().split()))


def doOp(old, op, num):
	if(op=='+'):
		return old + num
	elif(op=='*'):
		return old * num
	elif(op=='^'):
		return old * old

def main():
	n = 8
	ops = ['*', '+', '+', '+', '+', '*', '^', '+']
	nums = [2,   3,   6,   5,   8,   5,   2,   4]

	# n = 4
	# ops = ['*', '+', '^', '+']
	# nums = [19, 6, 2, 3]


	div = [0]*n
	t = [0]*n
	f = [0]*n
	file = open("11.txt")
	v = [Queue(maxsize = 40) for i in range(n)]
	for i in range(n):
		line = file.readline() #Monkey #
		line = file.readline().strip().split() #start 
		for j in range(2,len(line)):
			if line[j][-1]==",":
				line[j] = line[j].replace(',','')
			v[i].put(int(line[j]))

		line = file.readline() #operation
		 #Operation: new = old
		 #operator, number (hard coded)

		line = file.readline() #test
		f1,f2,f3,mod = line.strip().split() #Test: divisible by
		div[i]=int(mod)

		line = file.readline().strip().split() #if true
		t[i]=int(line[-1])


		line = file.readline().strip().split() #if false
		f[i]=int(line[-1])
		line = file.readline() #empty
	
	touch = [0]*n
	for z in range(10000):
		if z%10==0:
			print(z)
		for i in range(n):
			while v[i].empty()==False:
				touch[i] += 1
				worry = v[i].get()
				
				
				worry = doOp(worry, ops[i], nums[i])
				if worry%div[i]==0:
					v[t[i]].put(worry)
				else:
					v[f[i]].put(worry)
	touch.sort()
	print(touch[-1]*touch[-2])
main()