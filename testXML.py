import xml.etree.ElementTree as ET

# testing on XML parsing files
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

print(len(myroot))

for i in range(len(myroot)):
    for j in myroot[i]:
        print(j.tag, " maps to", j.text)


