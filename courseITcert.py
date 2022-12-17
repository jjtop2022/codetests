########### Python course week 2 questions ###########
print((10>=5*2)and(10<=5*2))

def sum(x,y):
    return (x+y)

print(sum(sum(1,2),sum(3,4)))

print((10>=5*2) and (10<=5*2))

def fractional_part(numerator, denominator):
	# Operate with numerator and denominator to 
    # keep just the fractional part of the quotient
    if denominator == 0:
        return 0
    else:
        return (numerator/denominator) % 1 #print out only decimal part

print(fractional_part(5,5))
print(fractional_part(7,5))

#######################################################



### Week 3 looping ####################################

def print_prime_factors(number):
  # Start with two, which is the first prime
  factor = 2
  # Keep going until the factor is larger than the number
  while factor <= number:
    # Check if factor is a divisor of number
    if number % factor == 0:
      # If it is, print it and divide the original number
      print(factor)
      number = number / factor
    else:
      # If it's not, increment the factor by one
      factor += 1
  return "Done"

print_prime_factors(100)

########################################
def is_power_of_two(n):
  # Check if the number can be divided by two without a remainder
  if n == 0:
    return False
  while n % 2 == 0:
    n = n / 2
  # If after dividing by two the number is 1, it's a power of two
  if n == 1:
    return True
  return False
  
print(is_power_of_two(0)) # Should be False
print(is_power_of_two(1)) # Should be True
print(is_power_of_two(8)) # Should be True
print(is_power_of_two(19)) # Should be False

######################################
def sum_divisors(n):
    sum = 0
    # Return the sum of all divisors of n, not including n
    if n == 0:
        return 0
    i=1
    while i < n:
        if n % i == 0:
            sum += i
            #print("Test sum: "+str(sum))
        i += 1
    return sum

print(sum_divisors(0))
# 0
print(sum_divisors(3)) # Should sum of 1
# 1
print(sum_divisors(36)) # Should sum of 1+2+3+4+6+9+12+18
# 55
print(sum_divisors(102)) # Should be sum of 2+3+6+17+34+51
# 114

################################################
def multiplication_table(number):
	# Initialize the starting point of the multiplication table
	multiplier = 1
	# Only want to loop through 5
	while multiplier <= 5:
		result = number * multiplier 
		# What is the additional condition to exit out of the loop?
		if result > 25:
			break
		print(str(number) + "x" + str(multiplier) + "=" + str(result))
		# Increment the variable for the loop
		multiplier += 1

multiplication_table(3) 
# Should print: 3x1=3 3x2=6 3x3=9 3x4=12 3x5=15

multiplication_table(5) 
# Should print: 5x1=5 5x2=10 5x3=15 5x4=20 5x5=25

multiplication_table(8)	
# Should print: 8x1=8 8x2=16 8x3=24

#########################################################

#factorial not by recursion
def factorial(n):
    result = 1
    for x in range(1,n+1):
        result = result * x
    return result

for n in range(0,11):
    print(n, factorial(n))

###########################################################

def retry(operation, attempts):
  for n in range(attempts):
    if operation():
      print("Attempt " + str(n) + " succeeded")
      break
    else:
      print("Attempt " + str(n) + " failed")

#retry(create_user, 3)
#retry(stop_service, 5)
#######################################################

#adds sum of numbers in the parameter
def sum_positive_numbers(n):
    # The base case is n being smaller than 1
    if n < 1:
        return 0
    # The recursive case is adding this number to 
    # the sum of the numbers smaller than this one.
    return n + sum_positive_numbers(n-1)

print(sum_positive_numbers(3)) # Should be 6
print(sum_positive_numbers(5)) # Should be 15

########################################################

def power(x, y):
    if y == 0:
        return 1
    if y >= 1:
        return x * power(x, y - 1)

print(power(10,7))

#########################################################

#counts number of digits in a number
def digits(n):
  count = 0
  if n == 0:
    return n+1
  while (n >= 1):
    count += 1
    n = n/10
  return count
	
print(digits(25))   # Should print 2
print(digits(144))  # Should print 3
print(digits(10000)) # Should print 5
print(digits(0))    # Should print 1

###############################################################

def multiplication_table(start, stop):
	for x in range(start,stop+1):
		for y in range(start,stop+1):
			print(str(x*y), end=" ")
		print()

multiplication_table(1, 3)
# Should print the multiplication table shown above

################################################################

def counter(start, stop):
	x = start
	if x > stop:
		return_string = "Counting down: "
		while x >= stop:
			return_string += str(x)
			if x > stop:
				return_string += ","
			x -= 1
	else:
		return_string = "Counting up: "
		while x <= stop:
			return_string += str(x)
			if x < stop:
				return_string += ","
			x += 1
	return return_string

print(counter(1, 10)) # Should be "Counting up: 1,2,3,4,5,6,7,8,9,10"
print(counter(2, 1)) # Should be "Counting down: 2,1"
print(counter(5, 5)) # Should be "Counting up: 5"

###################################################################

for x in range(1, 10, 3):
    print(x)
  

print ("Next question value of y: ")
for x in range(10):
    for y in range(x):
        print(y)


print ("Next question votes: ")

def votes(params):
  for vote in params:
    print ("Possible option: "+vote)

votes(['yes','no','maybe'])

#################################################

def even_numbers(maximum):
	return_string = ""
	for x in range(2,maximum+1,2):
		return_string += str(x) + " "
	return return_string.strip()

print(even_numbers(6))  # Should be 2 4 6
print(even_numbers(10)) # Should be 2 4 6 8 10
print(even_numbers(1))  # No numbers displayed
print(even_numbers(3))  # Should be 2
print(even_numbers(0))  # No numbers displayed

###################################################

### Week 4 strings ################################

print("MounTains".lower())
print("YEs ".rstrip().lower())
print(" ".join(["This","is","a","ball"]))
print("Your number is {number}, {name}.".format(name="James",number=56))

def student_grade(name, grade):
	return "{name} received {grade}% on the exam".format(name=name,grade=grade)

print(student_grade("Reed", 80))
print(student_grade("Paige", 92))
print(student_grade("Jesse", 85))

print ("Jogn".replace('g','h'))


####################################################

def is_palindrome(input_string):
	# We'll create two strings, to compare them
	new_string = ""
	reverse_string = ""
	# Traverse through each letter of the input string
	for x in input_string:
		# Add any non-blank letters to the 
		# end of one string, and to the front
		# of the other string. 
		if x != ' ':
			new_string = new_string+x
			reverse_string = x+reverse_string
      #print(new_string)
      #print("testing both: {string}, {string1}".format(string=new_string,string1=new_string)
	new_string = new_string.lower()
	reverse_string = reverse_string.lower()
	# Compare the strings
	if new_string == reverse_string:
		return True
	return False

print(is_palindrome("Never Odd or Even")) # Should be True
print(is_palindrome("abc")) # Should be False
print(is_palindrome("kayak")) # Should be True

##########################################################

def convert_distance(miles):
	km = miles * 1.6 
	result = "{:.1f} miles equals {:.1f} km".format(miles,km)
	return result

print(convert_distance(12)) # Should be: 12 miles equals 19.2 km
print(convert_distance(5.5)) # Should be: 5.5 miles equals 8.8 km
print(convert_distance(11)) # Should be: 11 miles equals 17.6 km

############################################################

def nametag(first_name, last_name):
	return("{} {}.".format(first_name,last_name[0]))

print(nametag("Jane", "Smith")) 
# Should display "Jane S." 
print(nametag("Francesco", "Rinaldi")) 
# Should display "Francesco R." 
print(nametag("Jean-Luc", "Grand-Pierre")) 
# Should display "Jean-Luc G." 


# replacing strings at the end of a sentence #############

def replace_ending(sentence, old, new):
	# Check if the old string is at the end of the sentence 
	if sentence[-len(old):] == str(old):
		# Using i as the slicing index, combine the part
		# of the sentence up to the matched string at the 
		# end with the new string
		i = len(old)
		
		new_sentence = sentence[:-i]+new
		return new_sentence

	# Return the original sentence if there is no match 
	return sentence
	
print(replace_ending("It's raining cats and cats", "cats", "dogs")) 
# Should display "It's raining cats and dogs"
print(replace_ending("She sells seashells by the seashore", "seashells", "donuts")) 
# Should display "She sells seashells by the seashore"
print(replace_ending("The weather is nice in May", "may", "april")) 
# Should display "The weather is nice in May"
print(replace_ending("The weather is nice in May", "May", "April")) 
# Should display "The weather is nice in April"

################################################################

#### lists #############################

def get_word(sentence, n):
	# Only proceed if n is positive 
	if n > 0:
		words = sentence.split()
		# Only proceed if n is not more than the number of words 
		if n <= len(words):
			return words[n-1]
	return("")

print(get_word("This is a lesson about lists", 4)) # Should print: lesson
print(get_word("This is a lesson about lists", -4)) # Nothing
print(get_word("Now we are cooking!", 1)) # Should print: Now
print(get_word("Now we are cooking!", 5)) # Nothing

#####  list iteration ###############################
animals = ["Lion","Zebra","Dolphin","Monkey"]
chars = 0
for animal in animals:
	chars += len(animal) #get length of each animal add to chars

print ("Total characters: {}, Average length: {}".format(chars,chars/len(animals)))

##################################################
# enumerate assigns list values to index
winners = ["AAAA","bbbbb","CCCCC"]
for index, person in enumerate(winners):
	print("{} - {}".format(index+1,person))

# function to take emails of people and names, then print out
# 1st element is email address, 2nd is name
def full_email(people):
	results =[]
	for email,name in people:
		results.append("{} <{}>".format(name,email))
	return results

print(full_email([("ttt@ttt.com", "Mr Ter"),("zzz@zzz.com", "Mrs. Yun")]))

###################################################
# prints list of skipped elements
def skip_elements(elements):
	newelement=[]
	count=0
	for index, element in enumerate(elements):
		if count ==0:
			newelement.append(elements[0])
		elif count < len(elements):
			newelement.append(elements[count])
		count = count + 2
	
	return newelement

# used without enumerate
def skip_elements2(elements):
	newelement=[]
	count=0
	for x in elements:
		if count ==0:
			newelement.append(elements[0])
		elif count < len(elements):
			newelement.append(elements[count])
		count = count + 2
	
	return newelement


print(skip_elements(["a", "b", "c", "d", "e", "f", "g"])) # Should be ['a', 'c', 'e', 'g']
print(skip_elements(['Orange', 'Pineapple', 'Strawberry', 'Kiwi', 'Peach'])) # Should be ['Orange', 'Strawberry', 'Peach']

print(skip_elements2(["a", "b", "c", "d", "e", "f", "g"])) # Should be ['a', 'c', 'e', 'g']
print(skip_elements2(['Orange', 'Pineapple', 'Strawberry', 'Kiwi', 'Peach'])) # Should be ['Orange', 'Strawberry', 'Peach']

### quick way of printing out multiples
multiples = [x*7 for x in range(1,11)]
print(multiples)

#######################################
## return all odd numbers in a list
## list comprehension - creates new list from a sequence on a single line

def odd_numbers(n):
	return [x for x in range(1,n+1) if x % 2 == 1]

print(odd_numbers(5))  # Should print [1, 3, 5]
print(odd_numbers(10)) # Should print [1, 3, 5, 7, 9]
print(odd_numbers(11)) # Should print [1, 3, 5, 7, 9, 11]
print(odd_numbers(1))  # Should print [1]
print(odd_numbers(-1)) # Should print []

########################################
filenames = ["program.c", "stdio.hpp", "sample.hpp", "a.out", "math.hpp", "hpp.out"]
# Generate newfilenames as a list containing the new filenames
# using as many lines of code as your chosen method requires.
newfilenames=[]
for file in filenames:
    #check extensions if .hpp
	fextent = file.split(".")
	print(fextent[1])
	if fextent[1] == 'hpp':
		tempname = fextent[0]+'.h'
		newfilenames.append(tempname)
	else:
		newfilenames.append(file)

print(newfilenames) 
# Should be ["program.c", "stdio.h", "sample.h", "a.out", "math.h", "hpp.out"]


####  change the sentence to pig latin
def pig_latin(text):
  say = ""
  # Separate the text into words
  words = text.split()
  for word in words:
    # Create the pig latin word and add it to the list
    newword = word[1:]+word[0]+'ay'
    # Turn the list back into a phrase
    say = say + newword + ' '
  return say
		
print(pig_latin("hello how are you")) # Should be "ellohay owhay reaay ouyay"
print(pig_latin("programming in python is fun")) # Should be "rogrammingpay niay ythonpay siay unfay"


#########################################
# print out a string in format below
def group_list(group, users):
	members = (group, users)
  # change a list to a string for users
	str =""
	for ele in users:
		if ele == users[-1]: #check if last element in last, if so don't add comma
			str += ele
		else:
			str += ele+', '
		
	return "{}: {}".format(group,str)

print(group_list("Marketing", ["Mike", "Karen", "Jake", "Tasha"])) # Should be "Marketing: Mike, Karen, Jake, Tasha"
print(group_list("Engineering", ["Kim", "Jay", "Tom"])) # Should be "Engineering: Kim, Jay, Tom"
print(group_list("Users", "")) # Should be "Users:"


####################################################
def guest_list(guests):
	for person in guests:
		print("{} is {} years old and works as {}".format(person[0],person[1],person[2]))

guest_list([('Ken', 30, "Chef"), ("Pat", 35, 'Lawyer'), ('Amanda', 25, "Engineer")])


####################################################
# change the values in linux system
def octal_to_string(octal):
    result = ""
    value_letters = [(4,"r"),(2,"w"),(1,"x")]
    # Iterate over each of the digits in octal
    #for ___ in [int(n) for n in str(octal)]:
        # Check for each of the permissions values
    #    for value, letter in value_letters:
    #        if ___ >= value:
    #            result += ___
    #            ___ -= value
    #        else:
    #            
    return result
    
print(octal_to_string(755)) # Should be rwxr-xr-x
print(octal_to_string(644)) # Should be rw-r--r--
print(octal_to_string(750)) # Should be rwxr-x---
print(octal_to_string(600)) # Should be rw-------

####################################################
### dictionary tests ###############################
filecounts = {"jpg":10,"txt":14,"csv":2,"py":23}
for e in filecounts:
	print(e)

for e, amount in filecounts.items():
	print("There is {} files with the .{} extension".format(amount,e))

########################
def count_letters(text):
	result={} #initialize a dictionary
	for letter in text:
		if letter not in result:
			result[letter] = 0
		result[letter] += 1
	return result

print(count_letters("aaaaaa"))
print(count_letters("Have a nice day"))

# generate email addresses as a list based on input
def email_list(domains):
	emails = []
	for name in domains:
		for user in domains[name]:
			email = user+'@'+name
			emails.append(email)
	return(emails)

print(email_list({"gmail.com": ["clark.kent", "diana.prince", "peter.parker"], "yahoo.com": ["barbara.gordon", "jean.grey"], "hotmail.com": ["bruce.wayne"]}))

####################################

wardrobe = {'shirt': ['red', 'blue', 'white'], 'jeans': ['blue', 'black']}
new_items = {'jeans': ['white'], 'scarf': ['yellow'], 'socks': ['black', 'brown']}
wardrobe.update(new_items)
print(wardrobe)

#####################################
def add_prices(basket):
	# Initialize the variable that will be used for the calculation
	total = 0
	# Iterate through the dictionary items
	for item in basket.keys():
		# Add each price to the total calculation
		# Hint: how do you access the values of
		# dictionary items?
		total += basket[item]
	# Limit the return value to 2 decimal places
	return round(total, 2)  

groceries = {"bananas": 1.56, "apples": 2.50, "oranges": 0.99, "bread": 4.59, 
	"coffee": 6.99, "milk": 3.39, "eggs": 2.98, "cheese": 5.44}

print(add_prices(groceries)) # Should print 28.44

#####################################################
animal="Hippopotamus"
print(animal[3:6])
print(animal[-5])
print(animal[10:])

colors = ["red", "white", "blue"]
colors.insert(2, "yellow")
print(colors)

text='The a jam is ready 1234'
print(text)
text = text.lower()
print(text)
text =text.replace(" ","")
print(text)
text1=''
for x in text:
	if x.isalpha():
		text1 = text1+x
print(text1)

################### check and create function dictionary
def count_letters(text):
  result = {}
  # Go through each letter in the text
  text = text.lower()
  text = text.replace(" ","")
  text1=""
  for x in text:
    if x.isalpha():
      text1 = text1+x
  
  for letter in text1:
    # Check if the letter needs to be counted or not
      if letter not in result:
        result[letter] = 0
    # Add or increment the value in the dictionary
      result[letter] += 1
  return result

print(count_letters("AaBbCc"))
# Should be {'a': 2, 'b': 2, 'c': 2}

print(count_letters("Math is fun! 2+2=4"))
# Should be {'m': 1, 'a': 1, 't': 1, 'h': 1, 'i': 1, 's': 1, 'f': 1, 'u': 1, 'n': 1}

print(count_letters("This is a sentence."))
# Should be {'t': 2, 'h': 1, 'i': 2, 's': 3, 'a': 1, 'e': 3, 'n': 2, 'c': 1}

# replacing a list
def highlight_word(sentence, word):
	newword=" "
	t = list(sentence.split())
	for i in range(len(t)):
		if t[i] == word:
			t[i] = word.upper()
	
	return (newword.join(t))


print(highlight_word("Have a nice day", "nice"))
print(highlight_word("Shhh, don't be so loud!", "loud"))
print(highlight_word("Automating with Python is fun", "fun"))

###########################################################
def format_address(address_string):
  # Declare variables

  # Separate the address string into parts
	number, leftover = address_string.split(' ',1)
   
  # Traverse through the address parts
    # Determine if the address part is the
    # house number or part of the street name
  # Return the formatted string  
  # 
	return "house number {} on street named {}".format(number, leftover)

print(format_address("123 Main Street"))
# Should print: "house number 123 on street named Main Street"

print(format_address("1001 1st Ave"))
# Should print: "house number 1001 on street named 1st Ave"

print(format_address("55 North Center Drive"))
# Should print "house number 55 on street named North Center Drive"

##########################################################

def combine_lists(list1, list2):
  # Generate a new list containing the elements of list2
  # Followed by the elements of list1 in reverse order
  newlist = list2 + list1[::-1]
  return newlist
  
	
Jamies_list = ["Alice", "Cindy", "Bobby", "Jan", "Peter"]
Drews_list = ["Mike", "Carol", "Greg", "Marcia"]

print(combine_lists(Jamies_list, Drews_list))

############################################################

# TO DO:
def combine_guests(guests1, guests2):
  # Combine both dictionaries into one, with each key listed 
  # only once, and the value from guests1 taking 
	return None



Rorys_guests = { "Adam":2, "Brenda":3, "David":1, "Jose":3, "Charlotte":2, "Terry":1, "Robert":4 }
Taylors_guests = { "David":4, "Nancy":1, "Robert":2, "Adam":1, "Samantha":3, "Chris":5}

print(combine_guests(Rorys_guests, Taylors_guests))

######################  Classes ###################################

class Furniture:
	color = ""
	material = ""

table = Furniture()
table.color ="brown"
table.material = "wood"

couch = Furniture()
couch.color = "red"
couch.material = "leather"

def describe_furniture(piece):
	return ("This piece of furniture is made of {} {}".format(piece.color, piece.material))

print(describe_furniture(table)) 
# Should be "This piece of furniture is made of brown wood"
print(describe_furniture(couch)) 
# Should be "This piece of furniture is made of red leather"

############ Class example #####################
class Person:
	def __init__(self, name):
		self.name = name
	def __str__(self):
		return "this is a self method {}".format(self.name)
	def greeting(self):
        # Should return "hi, my name is " followed by the name of the Person.
		return "hi, my name is {}".format(self.name)


# Create a new instance with a name of your choice
some_person = Person("Texas")  
# Call the greeting method
print(some_person.greeting())
print(some_person) #calls the __str__ method

###############  doc strings ###################

class Person:
  def __init__(self, name):
    self.name = name
  def greeting(self):
    """Outputs a message with the name of the person"""
    print("Hello! My name is {name}.".format(name=self.name)) 

help(Person.greeting)

###########################################################
class Clothing:
  stock={ 'name': [],'material' :[], 'amount':[]}
  def __init__(self,name):
    material = ""
    self.name = name
  def add_item(self, name, material, amount):
    Clothing.stock['name'].append(self.name)
    Clothing.stock['material'].append(self.material)
    Clothing.stock['amount'].append(amount)
  def Stock_by_Material(self, material):
    count=0
    n=0
    for item in Clothing.stock['material']:
      if item == material:
        count += Clothing.stock['amount'][n]
        n+=1
    return count


class shirt(Clothing):
  material="Cotton"
class pants(Clothing):
  material="Cotton"
  
polo = shirt("Polo")
sweatpants = pants("Sweatpants")
polo.add_item(polo.name, polo.material, 4)
sweatpants.add_item(sweatpants.name, sweatpants.material, 6)
current_stock = polo.Stock_by_Material("Cotton")
print(current_stock)

#################################################

import random
print(random.randint(1,10))
print(random.randint(1,10))

import datetime
now = datetime.datetime.now()
print(now)

##########  more class reuse ####################

class Animal:
    name = ""
    category = ""
    
    def __init__(self, name):
        self.name = name
    
    def set_category(self, category):
        self.category = category

class Turtle(Animal):
    category = "reptiles"

class Snake(Animal):
    category = "reptiles"

class Zoo:
    def __init__(self):
        self.current_animals = {} #hash to store animals, animal is the key, category is the value
    
    # add to hash - animal name as key, category as value
    def add_animal(self, animal):
        self.current_animals[animal.name] = animal.category
        print(animal.category)
    
    def total_of_category(self, category):
        result = 0
        # iterate through the hash, animal names and check if same category
        for animal in self.current_animals.keys():
          print(animal)
          if self.current_animals[animal] == category:
            result += 1
        return result

zoo = Zoo()

turtle = Turtle("Turtle") #create an instance of the Turtle class
snake = Snake("Snake") #create an instance of the Snake class

zoo.add_animal(turtle)
zoo.add_animal(snake)
print(zoo.total_of_category("reptiles")) #how many zoo animal types in the reptile category

####################################################################

def get_event_date(event):
  return event.date

def current_users(events):
  events.sort(key=get_event_date)
  machines = {}
  for event in events:
    if event.machine not in machines:
      machines[event.machine] = set()
      if event.type == 'login':
        machines[event.machine].add(event.user)
      elif event.type == 'logout':
        machines[event.machine].remove(event.user)
  return machines

def generate_report(machines):
  for machine, users in machines.items():
    if len(users) > 0:
      #generate a string of logged in users
      user_list = ", ".join(users)
      print("{} : {}".format(machine,user_list))

class Event:
  def __init__(self, event_date, event_type,machine_name,user):
    self.date = event_date
    self.type= event_type
    self.machine = machine_name
    self.user = user

events = [
          Event('2020-01-22 11:11:45', 'login', 'mymachine-1','jordon'),
          Event('2020-01-23 21:15:23', 'login', 'mymachine-1','jordon'),
          Event('2020-01-21 22:00:34', 'login', 'mymachine-1','killy'),
          Event('2020-01-23 12:31:09', 'login', 'mymachine-2','jord'),
          Event('2020-01-24 12:11:23', 'login', 'mymachine-1','jordon'),
          Event('2020-01-21 01:23:53', 'login', 'mymachine-2','jordon1'),
          ]

users = current_users(events)
print(users)
generate_report(users)

# to do: fix so a user cannot logout of a machine that was not login to

test1={}

test1['a'] = set()
test1['b'] = {'3','4','56','78'}
test1['c'] = {9,56,123,345}

for m in test1:
  print(m)
  if test1[m] == 'b':
    test1[m].add('19')
  elif test1[m] == 'c':
    test1[m].remove(56)

print(test1['b'], test1['c'], test1['a'])




