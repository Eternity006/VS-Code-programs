a={}
st=input("Enter the string: ")

x=input("Enter the word to replace: ")
y=input("Enter what you want to replace by: ")
st=st.split()
p=len(st)
for i in range(p):
	if(st[i]==x):
		st[i]=y
p=' '.join(st)
a.update({"string":p})
print(a["string"])
