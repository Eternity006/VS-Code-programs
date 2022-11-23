string=input("Enter the string:")
print(string[1,2])
string1=""
string2=""
for i in range(len(string)):
    if (i%2 == 0):
        string1=str(26+int(string[i-1,i]))
        string2+=string1
    else:
        string2+=string[i-1, i]
print(string2)