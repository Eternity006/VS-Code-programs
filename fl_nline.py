b=input("Enter the name(with extention) to search from ")	
try:
	f=open(b,"r")
except:
	print("Cannot open file.")
n=0
while(f.readline()):
	n=n+1
	
print("Number of lines= ",n)
f.close()
