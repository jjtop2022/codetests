import csv
import re

#open csv file, print out contents, and read into dictionary name as key, address as value
def populate1(filename): 
  holding_dict = {}
  with open (filename) as tester:
    reader = csv.DictReader(tester)
    for row in reader:
      print("{},{} lives at {} in {}".format(row['Name'],row['Age'],row['Address'],row['State']))
      holding_dict[row['Name']] = row['Address']
  return holding_dict

# print out only names and addresses with the number 78
def parseout(mydicts):
  seventy = {}
  for key in mydicts.keys():
    # NOTE: Must use (78) in reg expression NOT [78]
    result = re.search(r"(78)", mydicts[key])  
    #print (mydicts[key],result)
    if result != None:
      seventy[key] = mydicts[key]
  return seventy

mydict = populate1('testfile.txt')

print()
print("Now I will print out dictionary...")
for key in mydict.keys():
    print("name: "+key+ " Address: " + mydict[key])

print()
seveneight = parseout(mydict)

print("printing only addresses with 78: ")
for key in seveneight:
    print(key+":"+seveneight[key])



