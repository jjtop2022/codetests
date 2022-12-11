
# directed graph stored as dictionary table
graph = {'a':['c','b'],
        'b':['d'],
        'c':['e'],
        'd':['f'],
        'e':['g'],
        'f':[],
        'g':[]}

######################################
#DFS iteration - use stack
def depthFirstSearch(graph,sourceNode):
    mystack = [sourceNode]
    while len(mystack) > 0:
        current = mystack.pop()
        print('node: ',current)
        for x in graph[current]:
            mystack.append(x)      #push to stack
            print("status of stack: ",mystack)


#######################################
#DFS recursion
def recuDepthfirstSearch(graph, sourceNode):
    print(sourceNode)
    for x in graph[sourceNode]:
        recuDepthfirstSearch(graph,x)


########################################
# check if there is a path from source to dest recursively
# uses DFS
def hasPath(graph,src,dest):
    if src == dest:
        return True
    for x in graph[src]:
        if hasPath(graph,x,dest) == True:
            return True
    return False

# use DFS and stack to check path
def hasPath1(graph, src, dest):
    stack = [src]
    while len(stack) > 0:
        current = stack.pop()
        if current == dest:
            return True
        for x in graph[current]:
            stack.append(x)
    return False



#########################################
# check if path iteratively -  BFS
def hasPath2(graph,src,dest):
    queue = [src]
    while len(queue) > 0:
        current = queue.pop(0)
        if current == dest:
            return True
        for x in graph[current]:
            queue.append(x)
    return False




#iterative call to DFS
depthFirstSearch(graph, 'a')

#recursive print
print("recursive print")
recuDepthfirstSearch(graph,'a')

#check hasPath recursive DFS
if hasPath(graph,'b','e') == True:
    print("RECURSIVE: (hasPath) proper path found!")
else:
    print("RECURSIVE: (hasPath) No path found!")

#check non -recursive stack
if hasPath1(graph,'a','f') == True:
    print("Stack- DFS (hasPath1) proper path found!")
else:
    print("Stack - DFS (hasPath1) No path found!")


#check BFS is has path
if hasPath2(graph,'a','g') == True:
    print("QUEUE: BFS  (hasPath2) proper path found!")
else:
    print("QUEUE: BFS (hasPath2) No path found!")

