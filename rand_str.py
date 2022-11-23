import random
t=50
print("A Random string is :\n")
while(t!=0):
	n=random.randint(65,122)
	if n>90 and n<97:
		n+=random.randint(10,20)
	print(chr(n),end='')
	t-=1
print("\n")
	
n=int(input("Enter a lower limit: "))
h=int(input("Enter a higher limit: "))

m=random.randint(n,h)
print("Random number between",n,"and",h,"is\n",m)
m=random.randrange(0,70,7)
print("Random number between",0,"and",70,"is\n",m)
