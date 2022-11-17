import xml.etree.ElementTree as ET

#testing on parsing XML files - test1.xml
mytree = ET.parse('test1.xml')
myroot = mytree.getroot()

print(myroot[0].tag)  #<test> tag
print(myroot[1].tag)
print ("length: ",len(myroot))

#iterate through the XML tags
i=0
while(i< len(myroot)):
    for x in myroot[i]:
        print(x.tag,"->",x.text)
    i+=1






# this reverses the words not the letters
def reverseme2(text):
    results = list(text.split(' '))
    results.reverse()  #reverses the words
    return ' '.join(results)

## index testing

text1="123456"
print(text1)
print(text1[::2])
print(text1[::-1])
print(text1[1:])
print(text1[:-1])
print(text1[1:3])
print(text1[-1])
print(text1[-2])
print(text1[1])


##########  list testing

L1 = [9,67,33,0,1,2,3]
print(L1)
L1.sort()
print(L1)
L1.reverse()
print(L1)
L1.append(12)
print(L1)
L1.sort()
print(L1)
print(L1.index(33)) #print out index space
del L1[1] #deletes value in list
print(L1)
for x in L1:
   print (x)

y = 'spamaswa'
while y:
    print (y)
    y = y[1:]

a=0; b=10
while a < b:
    print (a)
    a= a+1

tests = [34,1,12,3,437,7,90,43,22]

for key in tests:
    if key == 1:
        print ("key found ", key)


mystring = input("Enter string to input: ")
print(mystring)
rstring = mystring[::-1]
print(rstring)

print(mystring[::-2])
print(mystring[::2])

tt=['ab','bc','dd','ee','ff']
for x in tt:
    print(x, end=" ")
print('\n')

kkk = {'1':'one', '2':'two','3':'three'}

for k in kkk.keys():
    print (k, kkk[k])

# I am testing for github changes

yy = ['aa', 'bb']
for x in yy:
    print (x)

# now this is another test

str='stestme4564'
print(str)
print(str[::-1])

# I am trying to commit a third time
str1='hill56543'
print(str1[::2])
print(str1[::-2])






