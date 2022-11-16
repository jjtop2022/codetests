import tkinter as tk

#gui exercise
window = tk.Tk()
greeting = tk.Label(text="testing tkinter")
greeting.pack()

###############################
print ("---------------------")
x=1
y=2
ssss="etertert"
print (x+y*2)
print (type(x))
print(ssss)
z=["test",'test1','test3','test5','test6']
zz=[56,45,22,211,334,666]
for xx in z: print (xx)
for xxx in zz: print(xxx)

## function to print patterns
def print_pattern(rows) :
    size = 3
    for i in range(size):
        print("*" * rows)
    
print_pattern(5)
print_pattern(4)


################
## Class testing
class Dog: 
    def __init__(self, name, age):
        self.name = name
        self.age = age


mydog = Dog("fido",3);
print (mydog.name," ",mydog.age)


#########################  sorting an array  ####
######### bubblesort ############################

def printme(arr1):
  for i in range(0, len(arr)):
    print(arr1[i],end=" ") 
    #print("- ")
  print("\n")

arr = [54,22,112,2,45,666]

print ("original array elements: ")
printme(arr)

arr.sort();
printme(arr)
arr.reverse()
printme(arr)
arr.append(3)
printme(arr)

while 1:
     value = input("enter a number: ")
     value = int(value)
     print (f'you entered {value} and type is {type(value)}\n')
     if value == 9999:
        break
     if value > 0 and value < 18:
         print("your a kid\n")
     elif value >= 18 and value < 65:
         print("your an adult\n")
     elif value >= 65 and value < 110:
         print("your retired\n")
     else:
         print("invalid choice\n")


print ("end loop\n")

############################################################
##############  test reading and writing in a file #########

#filename='Users\jjtopPC\JIMSTUFF\testcode\testfile.txt'
def fileprintout():
  filename = input ("enter filename: ")
  file = open(filename, 'r')
  print(file.read())
  file.close()

# function to write entries to file
def writetofile():
   filename = input("enter filename: ")
   times = input("enter number of entries: ")
   times = int(times)
   file = open(filename, 'a+')
   i = 0
   while i < times:
      name = input("enter name: ")
      name = name+','
      age = input("enter age: ")
      age = age+','
      address = input("enter address: ")
      address = address+','
      city = input("enter city: ")
      city = city+','
      state = input("enter state: ")
      state = state+','
      country = input("enter country: ")

      #concantenate the lines
      line = name+age+address+city+state+country
      #write to the file
      file.writelines(line)
      file.write("\n")
      i += 1

   file.close()

###################################
#file printout
fileprintout()

#write to file
writetofile()

#print the file 
fileprintout()

