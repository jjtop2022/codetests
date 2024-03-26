import shutil
import psutil
from collections import Counter

import re

def check_disk_usage(disk):
    du = shutil.disk_usage(disk)
    free = du.free / du.total * 100
    return free

def check_cpu_usage():
    usage = psutil.cpu_percent(1)
    return usage < 75

if not check_disk_usage("/") > 10 or not check_cpu_usage():
    print("ERROR!")
else:
    print ("everything is OK {0:.2f}".format(check_disk_usage("/")))

class MyTest:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def move(self):
        print("move")
    def draw(self):
        print("draw")

mytest = MyTest(23, 33)
print(mytest.x)
print(mytest.move())
print(mytest.draw())
    
###################################
## testing word counts gender count

text = 'This is a test of men and women text to see waitress performance.  My uncle decides to run for election. A chairman of the house.'
MALE = 'male'
FEMALE = 'female'
BOTH = 'both'
UNKNOWN = 'unknown'

MALE_Word = set(['guy','men','chairman','brother','uncle','waiter'])
FEMALE_Word = set(['women','woman','aunt','sister','lady','waitress'])

def count_sentence(cleantext):
    mycount = 0
    cleantext = cleantext.split() #make into words
    return len(cleantext)  #return number of words



def clean_sentence(text):
    numbers = {}

    #parse out all commas and periods, make everything lower case
    mytext = text.lower()
    mytext = re.sub(r"[^\w\s]","",mytext) #parse out anything that is not a space or letter
    print(mytext)
    print ("Total number of words: {}".format(count_sentence(mytext)))
    numbers[MALE] = 0
    numbers[FEMALE] = 0
    #do a count of words
    for maleword in MALE_Word:
        if maleword in mytext:
            numbers[MALE] += 1
    
    for fword in FEMALE_Word:
        if fword in mytext:
            numbers[FEMALE] += 1

    print("Number of male words: {}, female words: {}".format(numbers[MALE],numbers[FEMALE]))


clean_sentence(text)


# count number of male or female words in a sentence
#def genderize(words):
#    mlen = len(MALE_Word.intersection(words))
#    flen = len(FEMALE_Word.intersection(words))
#    if mlen > 0 and flen == 0:
#        return MALE
#    elif mlen == 0 and flen > 0:
#        return FEMALE
#    elif mlen > 0 and flen > 0:
#        return BOTH
#    else:
#        return UNKNOWN

# evaluate total number of male or female words
#def count_gender(sentences):
#    sents = Counter()
#    words = Counter()    
#    for sentence in sentences:
#        # call above function
#        gender = genderize(sentence)
#        sents[gender] += 1
#        words[gender] += len(sentence)
#    return sents, words

