#my_hash = defaultdict(list)

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

nodes={ 'a':['b','c'],
        'b':['d'],
        'c':['e'],
        'd':['f','k','y'],
        'e':[]}


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

