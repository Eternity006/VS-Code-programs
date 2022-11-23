a=input("Enter the name(with extention) of file to create ")
try:
	f=open((a,"x")
except:
	print("Cannot create file.")
	
f.close()
f=open(a,"w+")
l=input("Enter what you want to write\n")
l=l.split()
f.write(str(l))
f.seek(0)
print("Your file contains:\n",f.read())
f.close()
