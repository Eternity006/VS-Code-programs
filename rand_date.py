import random
print("A random number between 0 and 6 is:",random.randrange(0,6))
print("A random number between 5 and 10 is:",random.randrange(5,10))
print("A random number between 0 and 10 with steps of 3 is:",random.randrange(0,10,3))
start=input("Enter a date in (dd-mm-yyyy) format: ")
end=input("Enter another date in (dd-mm-yyyy) format: ")
start=start.split("-")
end=end.split('-')
date1=int(start[0])
date2=int(end[0])
month1=int(start[1])
month2=int(end[1])
if month2>month1:
	m=month2
else:
	m=month1
year1=int(start[2])
year2=int(end[2])
date=random.randint(date1,date2)
month=random.randint(0,m)
if(month<10):
	m='0'+str(month)
else:
	m=str(month)
year=random.randint(year1,year2)
print("A random date between those two is : "+str(date)+'-'+m+'-'+str(year))
