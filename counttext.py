import re
# open a log file and count the number of occurances
counter = {}
with open("counttext.log", "r") as f:
    for item in f:
        item = item[:-1] #rid newline character 
        if item not in counter:
            counter[item] = 1
        else:
            counter[item] += 1

#sort the keys
sort_thekey = sorted(counter.items(),key = lambda x : x[1], reverse = True)

#print out keys
for i in range(len(sort_thekey)):
    print("{}, {}".format(sort_thekey[i][0], sort_thekey[i][1]))


###################################
# open json file and print contents
import json

def load_json_data(filename):
    with open(filename) as json_file:
        data = json.load(json_file)
    return data


mydata = load_json_data("text1.json")
print(mydata)
print("************* After total printout *************")

count=1
for item in mydata["testcase"]:
    print("Data: {} ".format(count)+ str(item.keys())+item['a']+" "+item['b']+" "+str(item['c'])+" "+item['d'])
    count += 1

###############################################
###############################################
#Now take a text file and convert to JSON
#write to new JSON file

# try to read 3 lines at a time 
from itertools import islice   #to be used to read 3 lines at once

filename="sampledata.txt"
storedict={}
with open(filename,"r") as mytext:
    while True:
       #mydata = mytext.readlines()  #use readlines to read into list
       mydata = list(islice(mytext,3))  #use to read 3 lines at a time into list
       if not mydata:
           break
       print(mydata)
       storedict["name"] = mydata[0].strip()   #removes whitespace
       storedict["weight"] = mydata[1].strip()
       storedict["description"] = mydata[2].strip()

       #only use numbers for weight, 1. rid non numbers 2. change to decimal
       storedict["weight"] = re.sub(r"[^\d]","",storedict["weight"])
       storedict["weight"] = int(storedict["weight"])  #change to an integer from string

       storedict["image"] = "temp.jpeg"  #temp image for new, however name must change
       outfile = open("sampletest.json", "a+")  #add json to file
       json.dump(storedict,outfile,indent=2, sort_keys=False)

outfile.close()








