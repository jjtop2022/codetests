
# directed graph stored as dictionary table
graph = {'a':['c','b'],
        'b':['d'],
        'c':['e'],
        'd':['f'],
        'e':[],
        'f':[]}

######################################
#DFS iteration
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


#iterative call to DFS
depthFirstSearch(graph, 'a')

#recursive print
print("recursive print")
recuDepthfirstSearch(graph,'a')


