# this reverses the words not the letters
def reverseme2(text):
    results = list(text.split(' '))
    results.reverse()  #reverses the words
    return ' '.join(results)

# reverses the words
def reverseword(text):
    results = list(text.split(' '))
    newword=[]
    for word in results:
        i=len(word)
        rword=[]
        for x in range(len(word)):
            rword += word[i-1]
            i = i - 1
        rword = ' '.join(rword) #change the list to string
        newword.append(rword)
    print (newword)
    newword = ' '.join(newword)
    return newword



def reverseword2(text):
    words = list(text.split(' ')) #split words in a list
    newlist=[]
    for rev in words:
        rev = rev[::-1]
        newlist.append(rev)

    newlist = ' '.join(newlist)  #convert the list back to a string
    return newlist


        
##########  list testing

mystring = input("Enter a sentence to input: ")
print(mystring)
print(reverseme2(mystring))
print(reverseword(mystring))
print(reverseword2(mystring))
print(rw3(mystring))



