L=['aaa',[(1,2),(5,7),(['inner',22,['inner5',['inner6','inner6.1']]],8)],6566]

print(L[1][0])
print(L[1][2][0][0]) #printed out nested list elements
print(L[1][2][0][2][1][1]) #five layers inside
print(L)

class MyClass1:
    def setdata(self,value):
        self.data = value
    def display(self):
        print (self.data)


class MyClass2(MyClass1):
    def display(self):
        print('Current value = "%s"' % self.data)


class MyClass3(MyClass2):
    def __init__(self,value):
        self.data = value
    def __add__(self,other):
        return MyClass3(self.data + other)
    def __mul__(self,other):
        return MyClass3(self.data * other)



x=MyClass1()
x.setdata("howdy now")
x.display()
z=MyClass2()
z.setdata("Howdy too")
z.display()
zz=MyClass3("new add")
zz.display()
zzz = zz+' second one'
zzz.display()
zzzz=zz * 3
zzzz.display()

# a sample graph -use DFS
nodes={ 'a':['b','c'],
        'b':['d'],
        'c':['e'],
        'd':['f','k','y'],
        'e':['g'],
        'f': [],
        'g':[] }


##########################
#create stack
stack=[]
stack.append(nodes['a'][0])
stack.append(nodes['b'][0])
stack.append(nodes['a'][1])
stack.append(nodes['d'][2])
print(stack)
while len(stack) > 0:
    print(stack.pop())
print(stack)
##########################


def changer(x, y):
    x=209
    y[0]='sap'


def multipl(x,y):
    x=209
    y=[3,4,9]
    return x, y

X=4
L=[2,1]
print(X,L)
changer(X,L)
print(X,L)
X, L = multipl(X,L)
print(X,L)

def ppp(*aaaa):
    res = []
    for x in aaaa:
        res.append(x)
    return res

mylist = ppp('mmm','x',78,'ppp','pppp','jesse','1',8)
print(mylist, "length: ", len(mylist))

print(str(45.5+454))

#nested for loop example 
for left in range(7):
    for right in range(left, 7):
        print("[" + str(left)+"|"+str(right)+"]", end=" ")
    print()

#################################################
newDict ={}
myDict = {1:[23,45,1,11,221,1],2:["tertrte",'aaa'],56:['x','b','a'],6:[90,91,90], 3 :['eggs','aaa']}
print(myDict)
#sort the keys
for x in sorted(myDict.keys()):
    newDict[x] = myDict[x]
#sort the values
for y in newDict.keys():
    newDict[y].sort()

print(newDict)

script="thee? amd. therer#? Ehrhrtr., trsffu.."
newscript=script

print(newscript)
newscript=newscript.replace("?","")
newscript=newscript.replace(",","")
newscript=newscript.replace(".","")
newscript=newscript.replace("#","")
print(newscript)

import re
newstring = re.sub(r'[^a-zA-Z]',' ', script) #replace all non letters with space
print(newstring)
newlist = newstring.split()
print(newlist)

import copy

mylist=[[1,2,5,4],[7,34,1],67,90]
newlist = copy.deepcopy(mylist) #new list will not be modified
mylist[0][1] = 6
mylist[1][2] = 30
print(mylist)
print (newlist)

#######################################################33
def combine_guests(guests1, guests2):
    newlist={}
  # Combine both dictionaries into one, with each key listed 
  # only once, and the value from guests1 taking 
    
    for x in guests1:
        if x in guests2:
            newlist[x] = guests1[x]+guests2[x]
        else:
            newlist[x] = guests1[x]

    #add remaining guests to hash from guest2
    for x in guests2:
        if x not in guests1:
            newlist[x] = guests2[x]
    return newlist


Rorys_guests = { "Adam":2, "Brenda":3, "David":1, "Jose":3, "Charlotte":2, "Terry":1, "Robert":4 }
Taylors_guests = { "David":4, "Nancy":1, "Robert":2, "Adam":1, "Samantha":3, "Chris":5}

print(combine_guests(Rorys_guests, Taylors_guests))

def checkpalin(mystring):
    newstring1=""
    newstring2=""
    for x in mystring:
        #remove white space
        if x != ' ':
            newstring1 = x + newstring1
            newstring2 = newstring2 + x

    newstring1 = newstring1.lower()
    newstring2 = newstring2.lower()

    if newstring1 == newstring2:
        print("{} is a palindrome!".format(mystring))
    else:
        print("{} is NOT a palindrome!".format(mystring))


test1="place1"
test2="madam"
test3="khk Khk"
test4="idland"
test5="Never Odd or Even"

checkpalin(test1)
checkpalin(test2)
checkpalin(test3)
checkpalin(test4)
checkpalin(test5)

text1="testt, tast, :hterkmpw stirnh.The, twma, The netsettst: setsetset nnn:"
newtext1=""
 
for letter in text1:
    if letter.isalpha() == True:
        newtext1 = newtext1 + letter
    else:
        newtext1 = newtext1+" "

print(newtext1)

newlist = newtext1.split()
print(newlist)

mydict={}

for y in newlist:
    if y not in mydict:
        mydict[y] = 0
    mydict[y] += 1

print(mydict)

#############################################################333


