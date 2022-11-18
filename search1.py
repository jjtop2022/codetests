mylist=['aaa','bbb','ccc','ddd','eee','fff']

def printout(mylist1):
    for x in mylist1:
        print (x,end=' ')
    print('\n')

def searchme(mylist, t):
    for x in mylist:
        if x == t:
            return 1
    return 0

printout(mylist)
while 1:
    a1 = input("enter a string to check against list (q for quit): ")
    if a1 == "q":
        break
    num = searchme(mylist, a1)
    if num == 0:
        print ("Not found!")
    else:
        print ("Found!")





