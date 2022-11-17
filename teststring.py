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



#this reverses the letters not the words
def reverseme(text):
   results = list(text.split(' '))
   #print(results) #changed to list
   for i in range(len(results)):
       results[i] = results[i][::-1]  #::-1 means the letters are reversed
   return ' '.join(results)


# this reverses the words not the letters
def reverseme2(text):
    results = list(text.split(' '))
    results.reverse()  #reverses the words
    return ' '.join(results)


#### testing the above functions
text = input("enter a string to reverse: ")
print ("original string: ")
print (text)
reverseme(text)
print ("reversed text: ")
print(reverseme(text))

print ("reversed again 2: ")
print(text)
print(reverseme2(text))

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

testlist = ['hi', 'bye', 'me','he']
 
print("next assignment: ")
for i in testlist:
    print (i, end=' ')
print("\n")

## dictionary testing
mytable = { 'a': 'alpha', 'b' : 'beta','c': 'carrot', 'd':'delta'}

for x in mytable.keys():
    print (x, '=', mytable[x])

print(mytable['a'])
print(mytable['b'])
print(mytable['c'])
print (mytable.keys())
print(mytable.values())

