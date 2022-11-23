b=input("Enter the name(with extention) to search from ")	
try:
	f=open(b,"r")
except:
	print("Cannot open file.")
	
st=input("Enter pattern to find the occourance of: ")
	
s=str(f.read())
f.seek(0)
print(st,"occures",s.count(st),"times in ",f.read())
f.close()

