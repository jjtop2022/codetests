# directed graph stored as dictionary table
graph = {'a':['c','b'],
        'b':['d'],
        'c':['e'],
        'd':['f'],
        'e':[],
        'f':[]}


############################################
# BFS - queue
def breathFirstSearch(graph, sourceNode):
    myqueue = [sourceNode]
    while len(myqueue) > 0:
        current = myqueue.pop(0) #remove from front of queue
        print("Node: ",current)
        for x in graph[current]:
            myqueue.append(x)


# run BFS using queue
breathFirstSearch(graph,'a')

