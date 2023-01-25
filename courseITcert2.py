import re

# Anything with punctuation

def check_punctuation (text):
  result = re.search(r".[.,!:?]", text)
  return result != None

print(check_punctuation("This is a sentence that ends with a period.")) # True
print(check_punctuation("This is a sentence fragment without a period")) # False
print(check_punctuation("Aren't regular expressions awesome?")) # True
print(check_punctuation("Wow! We're really picking up some steam now!")) # True
print(check_punctuation("End of the line")) # False

print("end question 1")
##########################################################

# Any repeating letter A or a

def repeating_letter_a(text):
  result = re.search(r"[Aa].*[Aa]", text)
  return result != None

print(repeating_letter_a("banana")) # True
print(repeating_letter_a("pineapple")) # False
print(repeating_letter_a("Animal Kingdom")) # True
print(repeating_letter_a("A is for apple")) # True

print ("end question 2")

###################################################

import re
def check_sentence(text):
  result = re.search(r"^[A-Z].*[.?!]$", text)
  return result != None

print(check_sentence("Is this is a sentence?")) # True
print(check_sentence("is this is a sentence?")) # False
print(check_sentence("Hello")) # False
print(check_sentence("1-2-3-GO!")) # False
print(check_sentence("A star is born.")) # True

print ("end question 3")

#########################################################
import re
def check_web_address(text):
  pattern = "^.*\.[a-zA-Z]+$"
  result = re.search(pattern, text)
  return result != None

print(check_web_address("gmail.com")) # True
print(check_web_address("www@google")) # False
print(check_web_address("www.Coursera.org")) # True
print(check_web_address("web-address.com/homepage")) # False
print(check_web_address("My_Favorite-Blog.US")) # True

print ("end question 4")

###########################################################

# correct time

import re
def check_time(text):
  pattern = "^\d+\:[00-59]+\s*[aApP][mM]$"
  
  result = re.search(pattern, text)
  return result != None

print(check_time("12:45pm")) # True
print(check_time("9:59 AM")) # True
print(check_time("6:60am")) # False
print(check_time("five o'clock")) # False

print ("end question 5")

##########################################################3

# should return True since (IM) satisfies the match conditions.

import re
def contains_acronym(text):
  pattern = "^.*\(\w+\).*"
  result = re.search(pattern, text)
  return result != None

print(contains_acronym("Instant messaging (IM) is a set of communication technologies used for text-based communication")) # True
print(contains_acronym("American Standard Code for Information Interchange (ASCII) is a character encoding standard for electronic communication")) # True
print(contains_acronym("Please do NOT enter without permission!")) # False
print(contains_acronym("PostScript is a fourth-generation programming language (4GL)")) # True
print(contains_acronym("Have fun using a self-contained underwater breathing apparatus (Scuba)!")) # True

print ("end question 6")

#####################################################################

# zip code
import re
def check_zip_code (text):
  result = re.search(r"\d+\d+\d+\d+\d+.*", text)
  return result != None

print(check_zip_code("The zip codes for New York are 10001 thru 11104.")) # True
print(check_zip_code("90210 is a TV show")) # False
print(check_zip_code("Their address is: 123 Main Street, Anytown, AZ 85258-0001.")) # True
print(check_zip_code("The Parliament of Canada is at 111 Wellington St, Ottawa, ON K1A0A9.")) # False

print ("end question 7")

##############################################################

import re
def rearrange_name(name):
  result = re.search(r"^(\w*), (\w*) (.*)$", name)
  if result == None:
    return name
  return "{} {} {}".format(result[2], result[3], result[1])

name=rearrange_name("Kennedy, John F.")
print(name)

print("end question 8")

#############################################################

import re
def extract_pid(log_line):
    regex = r"\[(\d+)\]\: ([A-Z]+)"
    result = re.search(regex, log_line)
    if result is None:
        return None
    return "{} ({})".format(result[1],result[2])

print(extract_pid("July 31 07:51:48 mycomputer bad_process[12345]: ERROR Performing package upgrade")) # 12345 (ERROR)
print(extract_pid("99 elephants in a [cage]")) # None
print(extract_pid("A string that also has numbers [34567] but no uppercase message")) # None
print(extract_pid("July 31 08:08:08 mycomputer new_process[67890]: RUNNING Performing backup")) # 67890 (RUNNING)

print ("end question 9")

#################################################################

# add area code to phone number - seperate into groups

import re
def transform_record(record):
  new_record = re.sub(r"([\w]+)(\s)([\w]+),([\d-]+),([\w]+)", r"\1\2\3,+1-\4,\5", record)
  return new_record

print(transform_record("Sabrina Green,802-867-5309,System Administrator")) 
# Sabrina Green,+1-802-867-5309,System Administrator

print(transform_record("Eli Jones,684-3481127,IT specialist")) 
# Eli Jones,+1-684-3481127,IT specialist

print(transform_record("Melody Daniels,846-687-7436,Programmer")) 
# Melody Daniels,+1-846-687-7436,Programmer

print(transform_record("Charlie Rivera,698-746-3357,Web Developer")) 
# Charlie Rivera,+1-698-746-3357,Web Developer

print("end question 10")

###################################################################

import re
def transform_comments(line_of_code):
  result = re.sub(r"[#]+",r"//",line_of_code)
  return result

print(transform_comments("### Start of program")) 
# Should be "// Start of program"
print(transform_comments("  number = 0   ## Initialize the variable")) 
# Should be "  number = 0   // Initialize the variable"
print(transform_comments("  number += 1   # Increment the variable")) 
# Should be "  number += 1   // Increment the variable"
print(transform_comments("  return(number)")) 
# Should be "  return(number)"

print ("end question 11")

#########################################################################


import re
def show_time_of_pid(line):
  pattern = r"^(\w+ \d+ \d+\:\d+\:\d+) (.*) (.*)\[(\d+)\]"
  result = re.search(pattern, line)
  return "{} pid:{}".format(result[1],result[4])

print(show_time_of_pid("Jul 6 14:01:23 computer.name CRON[29440]: USER (good_user)")) # Jul 6 14:01:23 pid:29440

print(show_time_of_pid("Jul 6 14:02:08 computer.name jam_tag=psim[29187]: (UUID:006)")) # Jul 6 14:02:08 pid:29187

print(show_time_of_pid("Jul 6 14:02:09 computer.name jam_tag=psim[29187]: (UUID:007)")) # Jul 6 14:02:09 pid:29187

print(show_time_of_pid("Jul 6 14:03:01 computer.name CRON[29440]: USER (naughty_user)")) # Jul 6 14:03:01 pid:29440

print("end question 12")
################################################################

# try and except error handling
import random

def Guess(participants):
    my_participant_dict = {}
    for participant in participants:
        my_participant_dict[participant] = random.randint(1, 9)
    try:
        if my_participant_dict['Larry'] == 9:
            return True
        else:
            return False
    except KeyError:
        return None

participants = ['Cathy','Fred','Jack','Tom']
print(Guess(participants))   #should return None








