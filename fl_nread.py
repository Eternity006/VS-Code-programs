b=input("Enter the name(with extention) to search from ")	
try:
	f=open(b,"r")
except:
	print("Cannot open file.")
n=int(input("Enter number of lines to read: "))
while(n!=0):
	print(f.readline())
	n-=1
	
f.close()
