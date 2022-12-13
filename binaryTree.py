# Coding a binary tree below:
#      a
#     /  \
#    b    c
#   / \    \
#  d   e    f

# Declare each Node
class Node:
    def __init__(self,value):
        self.value = value
        self.left = None
        self.right = None


# Setup the binary tree as above
a = Node('a')
b = Node('b')
c = Node('c')
d = Node('d')
e = Node('e')
f = Node('f')

# Attach each node as above
a.left = b
a.right = c
b.left = d
b.right = e
c.right = f

##############################

def depthFirstValue(root, mylist):
    stack = [root]
    while len(stack) > 0:
        current = stack.pop()
        #print(current.value)
        mylist.append(current.value) #add to list
        if (current.right):  #add to stack ONLY if child node exist in the tree below
            stack.append(current.right)
        if (current.left):  #add to stack ONLY if child node exist in the tree below
            stack.append(current.left)

mylist=[]
depthFirstValue(a, mylist)
print (mylist)


