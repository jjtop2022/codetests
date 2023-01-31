from collections import defaultdict

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
        i=1
        rword=''
        while i <= len(word):
            rword = rword + word[-i] #reverse letters from back
            i = i + 1
        # elimate the spaces
        #rword = ' '.join(rword) #change the list to string
        #rword = rword.replace(" ","") #remove whitespace from string
        newword.append(rword)

    newword = ' '.join(newword)
    return newword

def reverseletter3(text):
    results = list(text.split())
    newword=[]
    for word in results:
        rword=''
        i=1
        for x in word:
            rword = rword + word[-i]
            i = i + 1

        newword.append(rword)
    newword = '*'.join(newword)
    return newword


def reverseletter2(text):
    words = list(text.split()) #split words in a list
    newlist=[]
    for rev in words:
        rev = rev[::-1]
        newlist.append(rev)

    newlist = ' '.join(newlist)  #convert the list back to a string
    return newlist


        
##########  list testing

mystring = input("Enter a sentence to input: ")
print("String: ", mystring)
print("Reversed word: ", reverseword(mystring))
print("Reversed letters: ", reverseletter(mystring))
print("Reversed letters 2: ", reverseletter2(mystring))
print("Reverse letter3 : ", reverseletter3(mystring))

print(list(reversed(range(0,10))))

my_set = {1,1,2,3} #sets have unique elements, will eliminate redundant elements
print(my_set)

######################################################
filenames = ["program.c", "stdio.hpp", "sample.hpp", "a.out", "math.hpp", "hpp.out"]
# Generate newfilenames as a list containing the new filenames
# using as many lines of code as your chosen method requires.
newfilenames=[]
for file in filenames:
    #check extensions if .hpp
    fextent = file.split(".")
    print(fextent[1])

print(newfilenames) 
# Should be ["program.c", "stdio.h", "sample.h", "a.out", "math.h", "hpp.out"]
########################################################

