import string

# this reverses the words not the letters
def reverseword(text):
    results = list(text.split())
    results.reverse()  #reverses the words
    results = ' '.join(results)
    return results


# reverses the letters of the words
def reverseletter(text):
    results = list(text.split())
    newword=[]
    for word in results:
        i=len(word)
        rword=''
        while i > 0:
            rword = rword + word[i-1]
            i = i - 1
        # elimate the spaces
        rword = ' '.join(rword) #change the list to string
        rword = rword.replace(" ","") #remove whitespace from string

        newword.append(rword)

    newword = ' '.join(newword)
    return newword



def reverseletter2(text):
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
print(reverseword(mystring))
print(reverseletter(mystring))
print(reverseletter2(mystring))





