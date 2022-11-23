a=input("Enter the name(with extention) of file to create ")
try:
	f=open(a,"x")
	f.close()
except:
	print("Cannot create file.")

b=input("Enter the name(with extention) to copy the contents from ")	
try:
	s=open(b,"r")
except:
	print("Cannot open file.")
f=open(a,"w+")
f.write(s.read())
f.seek(0)
print("Your file contains:")
print(f.read())
f.close()
s.close()
