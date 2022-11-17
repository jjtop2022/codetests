# this reverses the words not the letters
def reverseme2(text):
    results = list(text.split(' '))
    results.reverse()  #reverses the words
    return ' '.join(results)

## index testing

##########  list testing

mystring = input("Enter string to input: ")
print(mystring)
rstring = mystring[::-1]
print(rstring)
print(rstring[::2])
print(mystring[1::3])
print(mystring[1:3])

