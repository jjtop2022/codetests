import json

with open('test1.json', 'r') as opened_file:
    policy = json.load(opened_file)

from pprint import pprint
pprint (policy)

# modify json file
policy['innertest']['a3'] = 'S3'

pprint (policy)

